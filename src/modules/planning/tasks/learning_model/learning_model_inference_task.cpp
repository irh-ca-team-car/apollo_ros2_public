/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 **/

#include "modules/planning/tasks/learning_model/learning_model_inference_task.h"

#include <cmath>
#include <limits>
#include <string>

#include "absl/strings/str_cat.h"
#include "modules/planning/learning_based/model_inference/trajectory_imitation_libtorch_inference.h"
#include "modules/planning/proto/learning_data.pb.h"
#include "modules/planning/proto/planning_config.pb.h"

namespace apollo {
namespace planning {

using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::common::TrajectoryPoint;

LearningModelInferenceTask::LearningModelInferenceTask(
    const apollo_msgs::msg::ApolloplanningTaskConfig& config,
    const std::shared_ptr<DependencyInjector>& injector)
    : Task(config, injector) {
  ACHECK(config.taskconfig.learningmodelinferencetaskconfig != apollo_msgs::msg::ApolloplanningLearningModelInferenceTaskConfig());
  trajectory_imitation_inference_ =
      std::make_unique<TrajectoryImitationLibtorchInference>(
          config.taskconfig.learningmodelinferencetaskconfig);
}

Status LearningModelInferenceTask::Execute(
    Frame* frame, ReferenceLineInfo* reference_line_info) {
  CHECK_NOTNULL(frame);

  Task::Execute(frame, reference_line_info);
  return Process(frame);
}

Status LearningModelInferenceTask::Process(Frame* frame) {
  CHECK_NOTNULL(frame);
  const auto& config = config_.taskconfig.learningmodelinferencetaskconfig;

  if (!injector_->learning_based_data() ||
      !injector_->learning_based_data()->GetLatestLearningDataFrame()) {
    const std::string msg = "learning_data_frame empty";
    AERROR << msg;
    // hybrid model will use rule based planning when learning based data or
    // learning data frame is empty
    if (config.allowemptylearningbaseddata) {
      return Status::OK();
    }
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }

  LearningDataFrame learning_data_frame;
  learning_data_frame=(
      *(injector_->learning_based_data()->GetLatestLearningDataFrame()));

  ADEBUG << "LearningModelInferenceTask: frame_num["
         << learning_data_frame.framenum << "] adc_trajectory_point_size["
         << learning_data_frame.adctrajectorypoint.size() << "]";

  if (learning_data_frame.adctrajectorypoint.size() <= 0) {
    const std::string msg =
        absl::StrCat("learning_data adc_trajectory_point empty. frame_num[",
                     learning_data_frame.framenum, "]");
    AERROR << msg;
    // hybrid model will use rule based planning when learning model output is
    // not ready
    if (config.allowemptyoutputtrajectory) {
      return Status::OK();
    }
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }

  const double start_point_timestamp_sec =
      learning_data_frame
          .adctrajectorypoint.at(
              learning_data_frame.adctrajectorypoint.size() - 1)
          .timestampsec;

  ADEBUG << "start_point_timestamp_sec: " << start_point_timestamp_sec;

  TrajectoryEvaluator trajectory_evaluator;

  // evaluate adc trajectory
  trajectory_evaluator.EvaluateADCTrajectory(start_point_timestamp_sec,
                                             config.trajectorydeltat,
                                             &learning_data_frame);

  // evaluate obstacle trajectory
  trajectory_evaluator.EvaluateObstacleTrajectory(start_point_timestamp_sec,
                                                  config.trajectorydeltat,
                                                  &learning_data_frame);

  // evaluate obstacle prediction trajectory
  trajectory_evaluator.EvaluateObstaclePredictionTrajectory(
      start_point_timestamp_sec, config.trajectorydeltat,
      &learning_data_frame);

  if (!trajectory_imitation_inference_->LoadModel()) {
    const std::string msg = absl::StrCat(
        "TrajectoryImitationInference LoadModel() failed. frame_num[",
        learning_data_frame.framenum, "]");
    AERROR << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }
  if (!trajectory_imitation_inference_->DoInference(&learning_data_frame)) {
    const std::string msg = absl::StrCat(
        "TrajectoryImitationLibtorchInference Inference failed. frame_num[",
        learning_data_frame.framenum, "]");
    AERROR << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }

  const int adc_future_trajectory_point_size =
      learning_data_frame.output.adcfuturetrajectorypoint.size();
  ADEBUG << "   adc_future_trajectory_point_size["
         << adc_future_trajectory_point_size << "]";
  if (adc_future_trajectory_point_size < 10) {
    const std::string msg = absl::StrCat(
        "too short adc_future_trajectory_point. frame_num[",
        learning_data_frame.framenum, "] adc_future_trajectory_point_size[",
        adc_future_trajectory_point_size, "]");
    AERROR << msg;
    return Status(ErrorCode::PLANNING_ERROR, msg);
  }

  // evaluate adc future trajectory
  // TODO(all): move to conf
  constexpr double kADCFutureTrajectoryDeltaTime = 0.02;
  std::vector<TrajectoryPointFeature> future_trajectory;
  for (const auto& tp :
       learning_data_frame.output.adcfuturetrajectorypoint) {
    future_trajectory.push_back(tp);
  }

  TrajectoryPointFeature tp;
  const int last = learning_data_frame.adctrajectorypoint.size() - 1;
  tp.set__timestampsec(
      learning_data_frame.adctrajectorypoint.at(last).timestampsec);
  tp.trajectorypoint=(
      learning_data_frame.adctrajectorypoint.at(last).trajectorypoint);
  future_trajectory.insert(future_trajectory.begin(), tp);

  std::vector<TrajectoryPointFeature> evaluated_future_trajectory;
  trajectory_evaluator.EvaluateADCFutureTrajectory(
      learning_data_frame.framenum, future_trajectory,
      start_point_timestamp_sec, kADCFutureTrajectoryDeltaTime,
      &evaluated_future_trajectory);

  // convert to common::TrajectoryPoint
  std::vector<common::TrajectoryPoint> adc_future_trajectory;
  ConvertADCFutureTrajectory(evaluated_future_trajectory,
                             &adc_future_trajectory);
  ADEBUG << "adc_future_trajectory_size: " << adc_future_trajectory.size();

  injector_->learning_based_data()
      ->set_learning_data_adc_future_trajectory_points(adc_future_trajectory);

  return Status::OK();
}

void LearningModelInferenceTask::ConvertADCFutureTrajectory(
    const std::vector<TrajectoryPointFeature>& trajectory,
    std::vector<common::TrajectoryPoint>* adc_future_trajectory) {
  adc_future_trajectory->clear();

  for (const auto& trajectory_point_feature : trajectory) {
    const auto& tp = trajectory_point_feature.trajectorypoint;
    // TrajectoryPointFeature -> common::TrajectoryPoint
    apollo::common::TrajectoryPoint trajectory_point;
    auto path_point = &trajectory_point.pathpoint;
    path_point->set__x(tp.pathpoint.x);
    path_point->set__y(tp.pathpoint.y);
    // path_point->set_z(tp.path_point().z());
    path_point->set__theta(tp.pathpoint.theta);
    // path_point->set_s(tp.path_point().s());
    // path_point->set_lane_id(tp.path_point().lane_id());
    // path_point->set_x_derivative();
    // path_point->set_y_derivative();

    trajectory_point.set__v(tp.v);
    trajectory_point.set__relativetime(tp.relativetime);
    // trajectory_point.mutable_gaussian_info()->CopyFrom(tp.gaussian_info());
    // trajectory_point.set_steer();

    adc_future_trajectory->push_back(trajectory_point);
  }

  double accumulated_s = 0.0;
  adc_future_trajectory->front().pathpoint.set__s(0.0);
  for (size_t i = 1; i < adc_future_trajectory->size(); ++i) {
    auto* cur_path_point = &(*adc_future_trajectory)[i].pathpoint;
    const auto& pre_path_point = (*adc_future_trajectory)[i - 1].pathpoint;
    accumulated_s += std::sqrt((cur_path_point->x - pre_path_point.x) *
                                   (cur_path_point->x - pre_path_point.x) +
                               (cur_path_point->y - pre_path_point.y) *
                                   (cur_path_point->y - pre_path_point.y));
    cur_path_point->set__s(accumulated_s);
  }

  for (size_t i = 0; i + 1 < adc_future_trajectory->size(); ++i) {
    const auto& cur_v = (*adc_future_trajectory)[i].v;
    const auto& cur_relative_time = (*adc_future_trajectory)[i].relativetime;
    const auto& next_v = (*adc_future_trajectory)[i + 1].v;
    const auto& next_relative_time =
        (*adc_future_trajectory)[i + 1].relativetime;
    const double cur_a =
        (next_v - cur_v) / (next_relative_time - cur_relative_time);
    (*adc_future_trajectory)[i].set__a(cur_a);
  }
  // assuming last point keeps zero acceleration
  adc_future_trajectory->back().set__a(0.0);

  for (size_t i = 0; i + 1 < adc_future_trajectory->size(); ++i) {
    const auto& cur_a = (*adc_future_trajectory)[i].a;
    const auto& cur_relative_time = (*adc_future_trajectory)[i].relativetime;
    const auto& next_a = (*adc_future_trajectory)[i + 1].a;
    const auto& next_relative_time =
        (*adc_future_trajectory)[i + 1].relativetime;
    const double cur_da =
        (next_a - cur_a) / (next_relative_time - cur_relative_time);
    (*adc_future_trajectory)[i].set__da(cur_da);
  }
  // assuming last point keeps zero acceleration
  adc_future_trajectory->back().set__da(0.0);

  for (size_t i = 0; i + 1 < adc_future_trajectory->size(); ++i) {
    auto* cur_path_point = &(*adc_future_trajectory)[i].pathpoint;
    const auto& next_path_point = (*adc_future_trajectory)[i + 1].pathpoint;
    const double cur_kappa =
        apollo::common::math::NormalizeAngle(next_path_point.theta -
                                             cur_path_point->theta) /
        (next_path_point.s - cur_path_point->s);
    cur_path_point->set__kappa(cur_kappa);
  }
  // assuming last point has zero kappa
  adc_future_trajectory->back().pathpoint.set__kappa(0.0);

  for (size_t i = 0; i + 1 < adc_future_trajectory->size(); ++i) {
    auto* cur_path_point = &(*adc_future_trajectory)[i].pathpoint;
    const auto& next_path_point = (*adc_future_trajectory)[i + 1].pathpoint;
    const double cur_dkappa =
        (next_path_point.kappa - cur_path_point->kappa) /
        (next_path_point.s - cur_path_point->s);
    cur_path_point->set__dkappa(cur_dkappa);
  }
  // assuming last point going straight with the last heading
  adc_future_trajectory->back().pathpoint.set__dkappa(0.0);

  for (size_t i = 0; i + 1 < adc_future_trajectory->size(); ++i) {
    auto* cur_path_point = &(*adc_future_trajectory)[i].pathpoint;
    const auto& next_path_point = (*adc_future_trajectory)[i + 1].pathpoint;
    const double cur_ddkappa =
        (next_path_point.dkappa - cur_path_point->dkappa) /
        (next_path_point.s - cur_path_point->s);
    cur_path_point->set__ddkappa(cur_ddkappa);
  }
  // assuming last point going straight with the last heading
  adc_future_trajectory->back().pathpoint.set__ddkappa(0.0);
}

}  // namespace planning
}  // namespace apollo
