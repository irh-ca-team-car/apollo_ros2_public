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

#include "modules/planning/common/trajectory_evaluator.h"

#include <algorithm>
#include <limits>

#include "absl/strings/str_cat.h"
#include "cyber/common/file.h"
#include "modules/planning/common/planning_gflags.h"
#include "modules/planning/common/trajectory/discretized_trajectory.h"
#include "modules/planning/pipeline/evaluator_logger.h"

namespace apollo {
namespace planning {

void TrajectoryEvaluator::WriteLog(const std::string& msg) {
  AERROR << msg;
  if (FLAGS_planning_offline_learning) {
    EvaluatorLogger::GetStream() << msg << std::endl;
  }
}

void TrajectoryEvaluator::EvaluateTrajectoryByTime(
    const int frame_num, const std::string& obstacle_id,
    const std::vector<std::pair<double, CommonTrajectoryPointFeature>>&
        trajectory,
    const double start_point_timestamp_sec, const double delta_time,
    std::vector<TrajectoryPointFeature>* evaluated_trajectory) {
  if (trajectory.empty() || (fabs(trajectory.front().first -
                                  start_point_timestamp_sec) < delta_time &&
                             fabs(trajectory.back().first -
                                  start_point_timestamp_sec) < delta_time)) {
    return;
  }

  std::vector<apollo::common::TrajectoryPoint> updated_trajectory;
  for (const auto& tp : trajectory) {
    // CommonTrajectoryPointFeature -> common::TrajectoryPoint
    double relative_time = tp.first - start_point_timestamp_sec;
    apollo::common::TrajectoryPoint trajectory_point;
    Convert(tp.second, relative_time, &trajectory_point);
    updated_trajectory.push_back(trajectory_point);
  }

  if (trajectory.front().first > trajectory.back().first) {
    std::reverse(updated_trajectory.begin(), updated_trajectory.end());
  }

  DiscretizedTrajectory discretized_trajectory;
  double last_relative_time = std::numeric_limits<double>::lowest();
  for (const auto& tp : updated_trajectory) {
    // filter out abnormal perception data
    if (tp.relativetime > last_relative_time) {
      discretized_trajectory.AppendTrajectoryPoint(tp);
      last_relative_time = tp.relativetime;
    } else {
      const std::string msg = absl::StrCat(
          "DISCARD trajectory point: frame_num[", frame_num, "] obstacle_id[",
          obstacle_id, "] last_relative_time[", last_relative_time,
          "] relatice_time[", tp.relativetime, "] relative_time_diff[",
          tp.relativetime - last_relative_time, "]");
      WriteLog(msg);
    }
  }

  const int low_bound =
      std::max(-150.0,
               ceil(updated_trajectory.front().relativetime / delta_time));
  const int high_bound =
      std::min(150.0,
               floor(updated_trajectory.back().relativetime / delta_time));
  ADEBUG << "frame_num[" << frame_num << "] obstacle_id[" << obstacle_id
         << "] low[" << low_bound << "] high[" << high_bound << "]";
  for (int i = low_bound; i <= high_bound; ++i) {
    double timestamp_sec = start_point_timestamp_sec + i * delta_time;
    double relative_time = i * delta_time;
    auto tp = discretized_trajectory.Evaluate(relative_time);

    // common::TrajectoryPoint -> TrajectoryPointFeature
    TrajectoryPointFeature trajectory_point;
    Convert(tp, timestamp_sec, &trajectory_point);

    evaluated_trajectory->push_back(trajectory_point);
  }
}

void TrajectoryEvaluator::EvaluateADCTrajectory(
    const double start_point_timestamp_sec, const double delta_time,
    LearningDataFrame* learning_data_frame) {
  std::vector<std::pair<double, CommonTrajectoryPointFeature>> trajectory;
  for (const auto& adc_tp : learning_data_frame->adctrajectorypoint) {
    trajectory.push_back(
        std::make_pair(adc_tp.timestampsec, adc_tp.trajectorypoint));
  }

  if (trajectory.size() <= 1) {
    const std::string msg = absl::StrCat(
        "too short adc_trajectory_point. frame_num[",
        learning_data_frame->framenum, "] size[", trajectory.size(), "]");
    WriteLog(msg);
    return;
  }

  learning_data_frame->adctrajectorypoint.clear();

  if (fabs(trajectory.front().first - start_point_timestamp_sec) <=
      delta_time) {
    auto adc_trajectory_point = learning_data_frame->adctrajectorypoint.emplace_back();
    adc_trajectory_point.timestampsec=(trajectory.back().first);
    adc_trajectory_point.trajectorypoint=(
        trajectory.back().second);

    const std::string msg =
        absl::StrCat("too short adc_trajectory. frame_num[",
                     learning_data_frame->framenum, "] size[",
                     trajectory.size(), "] timestamp_diff[",
                     start_point_timestamp_sec - trajectory.front().first, "]");
    WriteLog(msg);
    return;
  }

  std::vector<TrajectoryPointFeature> evaluated_trajectory;
  EvaluateTrajectoryByTime(learning_data_frame->framenum, "adc_trajectory",
                           trajectory, start_point_timestamp_sec, delta_time,
                           &evaluated_trajectory);
  ADEBUG << "frame_num[" << learning_data_frame->framenum
         << "] orig adc_trajectory[" << trajectory.size()
         << "] evaluated_trajectory_size[" << evaluated_trajectory.size()
         << "]";

  for (const auto& tp : evaluated_trajectory) {
    if (tp.trajectorypoint.relativetime <= 0.0 &&
        tp.trajectorypoint.relativetime >=
            -FLAGS_trajectory_time_length) {
      auto adc_trajectory_point =
          &learning_data_frame->adctrajectorypoint.emplace_back();
      adc_trajectory_point->timestampsec=(tp.timestampsec);
      adc_trajectory_point->trajectorypoint=(
          tp.trajectorypoint);
    } else {
      const std::string msg =
          absl::StrCat("DISCARD adc_trajectory_point. frame_num[",
                       learning_data_frame->framenum, "] size[",
                       evaluated_trajectory.size(), "] relative_time[",
                       tp.trajectorypoint.relativetime, "]");
      WriteLog(msg);
    }
  }
}

void TrajectoryEvaluator::EvaluateADCFutureTrajectory(
    const int frame_num,
    const std::vector<TrajectoryPointFeature>& adc_future_trajectory,
    const double start_point_timestamp_sec, const double delta_time,
    std::vector<TrajectoryPointFeature>* evaluated_adc_future_trajectory) {
  evaluated_adc_future_trajectory->clear();

  std::vector<std::pair<double, CommonTrajectoryPointFeature>> trajectory;
  for (const auto& adc_future_trajectory_point : adc_future_trajectory) {
    trajectory.push_back(
        std::make_pair(adc_future_trajectory_point.timestampsec,
                       adc_future_trajectory_point.trajectorypoint));
  }

  if (trajectory.size() <= 1) {
    const std::string msg =
        absl::StrCat("too short adc_future_trajectory. frame_num[", frame_num,
                     "] size[", trajectory.size(), "]");
    WriteLog(msg);
    return;
  }

  if (fabs(trajectory.back().first - start_point_timestamp_sec) <= delta_time) {
    const std::string msg =
        absl::StrCat("too short adc_future_trajectory. frame_num[", frame_num,
                     "] size[", trajectory.size(), "] time_range[",
                     trajectory.back().first - start_point_timestamp_sec, "]");
    WriteLog(msg);
    return;
  }

  std::vector<TrajectoryPointFeature> evaluated_trajectory;
  EvaluateTrajectoryByTime(frame_num, "adc_future_trajectory", trajectory,
                           start_point_timestamp_sec, delta_time,
                           &evaluated_trajectory);

  ADEBUG << "frame_num[" << frame_num << "] orig adc_future_trajectory["
         << trajectory.size() << "] evaluated_trajectory_size["
         << evaluated_trajectory.size() << "]";

  if (evaluated_trajectory.empty()) {
    const std::string msg = absl::StrCat(
        "WARNING: adc_future_trajectory not long enough. ", "frame_num[",
        frame_num, "] size[", evaluated_trajectory.size(), "]");
    WriteLog(msg);
  } else {
    const double time_range =
        evaluated_trajectory.back().timestampsec - start_point_timestamp_sec;
    if (time_range < FLAGS_trajectory_time_length) {
      const std::string msg = absl::StrCat(
          "WARNING: adc_future_trajectory not long enough. ", "frame_num[",
          frame_num, "] size[", evaluated_trajectory.size(), "] time_range[",
          time_range, "]");
      WriteLog(msg);
    }
  }

  for (const auto& tp : evaluated_trajectory) {
    if (tp.trajectorypoint.relativetime > 0.0 &&
        tp.trajectorypoint.relativetime <= FLAGS_trajectory_time_length) {
      evaluated_adc_future_trajectory->push_back(tp);
    } else {
      const std::string msg = absl::StrCat(
          "DISCARD adc_future_trajectory_point. frame_num[", frame_num,
          "] size[", evaluated_trajectory.size(), "] relative_time[",
          tp.trajectorypoint.relativetime, "]");
      WriteLog(msg);
    }
  }
}

void TrajectoryEvaluator::EvaluateObstacleTrajectory(
    const double start_point_timestamp_sec, const double delta_time,
    LearningDataFrame* learning_data_frame) {
  for (size_t i = 0; i < learning_data_frame->obstacle.size(); ++i) {
    const int obstacle_id = learning_data_frame->obstacle[i].id;
    const auto obstacle_trajectory =
        learning_data_frame->obstacle[i].obstacletrajectory;
    std::vector<std::pair<double, CommonTrajectoryPointFeature>> trajectory;
    for (const auto& perception_obstacle :
         obstacle_trajectory.perceptionobstaclehistory) {
      CommonTrajectoryPointFeature trajectory_point;
      trajectory_point.pathpoint.x=(
          perception_obstacle.position.x);
      trajectory_point.pathpoint.y=(
          perception_obstacle.position.y);
      trajectory_point.pathpoint.z=(
          perception_obstacle.position.z);
      trajectory_point.pathpoint.theta=(
          perception_obstacle.theta);

      const double v = std::sqrt(perception_obstacle.velocity.x *
                                     perception_obstacle.velocity.x +
                                 perception_obstacle.velocity.y *
                                     perception_obstacle.velocity.y);
      trajectory_point.set__v(v);

      const double a = std::sqrt(perception_obstacle.acceleration.x *
                                     perception_obstacle.acceleration.x +
                                 perception_obstacle.acceleration.y *
                                     perception_obstacle.acceleration.y);
      trajectory_point.set__a(a);

      trajectory.push_back(std::make_pair(perception_obstacle.timestampsec,
                                          trajectory_point));
    }

    std::vector<TrajectoryPointFeature> evaluated_trajectory;
    if (trajectory.size() == 1 ||
        fabs(trajectory.front().first - start_point_timestamp_sec)
            <= delta_time ||
        fabs(trajectory.front().first - trajectory.back().first)
            <= delta_time) {
      ADEBUG << "too short obstacle_trajectory. frame_num["
             << learning_data_frame->framenum << "] obstacle_id["
             << obstacle_id << "] size[" << trajectory.size()
             << "] timestamp_diff["
             << start_point_timestamp_sec - trajectory.front().first
             << "] time_range["
             << fabs(trajectory.front().first - trajectory.back().first) << "]";

      // pick at lease one point regardless of short timestamp,
      // to avoid model failure
      TrajectoryPointFeature trajectory_point;
      trajectory_point.timestampsec=(trajectory.front().first);
      trajectory_point.trajectorypoint=(
          trajectory.front().second);
      evaluated_trajectory.push_back(trajectory_point);
    } else {
      EvaluateTrajectoryByTime(learning_data_frame->framenum,
                               std::to_string(obstacle_id), trajectory,
                               start_point_timestamp_sec, delta_time,
                               &evaluated_trajectory);

      ADEBUG << "frame_num[" << learning_data_frame->framenum
             << "] obstacle_id[" << obstacle_id
             << "] orig obstacle_trajectory[" << trajectory.size()
             << "] evaluated_trajectory_size[" << evaluated_trajectory.size()
             << "]";
    }

    // update learning_data
    learning_data_frame->obstacle[i]
        .obstacletrajectory.evaluatedtrajectorypoint.clear();
    for (const auto& tp : evaluated_trajectory) {
      auto evaluated_trajectory_point = &learning_data_frame->obstacle[i]
                                            .obstacletrajectory.evaluatedtrajectorypoint.emplace_back();
      evaluated_trajectory_point->timestampsec=(tp.timestampsec);
      evaluated_trajectory_point->trajectorypoint=(
          tp.trajectorypoint);
    }
  }
}

void TrajectoryEvaluator::EvaluateObstaclePredictionTrajectory(
    const double start_point_timestamp_sec, const double delta_time,
    LearningDataFrame* learning_data_frame) {
  for (size_t i = 0; i < learning_data_frame->obstacle.size(); ++i) {
    const int obstacle_id = learning_data_frame->obstacle[i].id;
    const auto obstacle_prediction =
        learning_data_frame->obstacle[i].obstacleprediction;
    for (size_t j = 0; j < obstacle_prediction.trajectory.size(); ++j)
    {
      const auto obstacle_prediction_trajectory =
          obstacle_prediction.trajectory[j];

      std::vector<std::pair<double, CommonTrajectoryPointFeature>> trajectory;
      for (const auto& trajectory_point :
           obstacle_prediction_trajectory.trajectorypoint) {
        const double timestamp_sec =
            obstacle_prediction.timestampsec +
            trajectory_point.trajectorypoint.relativetime;
        trajectory.push_back(
            std::make_pair(timestamp_sec, trajectory_point.trajectorypoint));
      }
      if (fabs(trajectory.back().first - start_point_timestamp_sec) <=
          delta_time) {
        ADEBUG << "too short obstacle_prediction_trajectory. frame_num["
               << learning_data_frame->framenum << "] obstacle_id["
               << obstacle_id << "] size[" << trajectory.size()
               << "] timestamp_diff["
               << trajectory.back().first - start_point_timestamp_sec << "]";
        continue;
      }

      std::vector<TrajectoryPointFeature> evaluated_trajectory;
      EvaluateTrajectoryByTime(learning_data_frame->framenum,
                               std::to_string(obstacle_id), trajectory,
                               start_point_timestamp_sec, delta_time,
                               &evaluated_trajectory);

      ADEBUG << "frame_num[" << learning_data_frame->framenum
             << "] obstacle_id[" << obstacle_id
             << "orig obstacle_prediction_trajectory[" << trajectory.size()
             << "] evaluated_trajectory_size[" << evaluated_trajectory.size()
             << "]";

      // update learning_data
      learning_data_frame->obstacle[i]
          .obstacleprediction
          .trajectory[j].trajectorypoint.clear();
      for (const auto& tp : evaluated_trajectory) {
        auto obstacle_prediction_trajectory_point =
            learning_data_frame->obstacle[i]
                .obstacleprediction
                .trajectory[j].trajectorypoint.emplace_back();
        obstacle_prediction_trajectory_point.timestampsec=(
            tp.timestampsec);
        obstacle_prediction_trajectory_point.trajectorypoint
            =(tp.trajectorypoint);
      }
    }
  }
}

void TrajectoryEvaluator::Convert(const CommonTrajectoryPointFeature& tp,
                                  const double relative_time,
                                  common::TrajectoryPoint* trajectory_point) {
  auto path_point = trajectory_point->pathpoint;
  path_point.x=(tp.pathpoint.x);
  path_point.y=(tp.pathpoint.y);
  path_point.z=(tp.pathpoint.z);
  path_point.theta=(tp.pathpoint.theta);
  path_point.s=(tp.pathpoint.s);
  path_point.laneid=(tp.pathpoint.laneid);
  trajectory_point->v=(tp.v);
  trajectory_point->a=(tp.a);
  trajectory_point->relativetime=(relative_time);
  trajectory_point->gaussianinfo=(tp.gaussianinfo);
}

void TrajectoryEvaluator::Convert(const common::TrajectoryPoint& tp,
                                  const double timestamp_sec,
                                  TrajectoryPointFeature* trajectory_point) {
  trajectory_point->timestampsec=(timestamp_sec);
  auto path_point =
      trajectory_point->trajectorypoint.pathpoint;
  path_point.x=(tp.pathpoint.x);
  path_point.y=(tp.pathpoint.y);
  path_point.z=(tp.pathpoint.z);
  path_point.theta=(tp.pathpoint.theta);
  path_point.s=(tp.pathpoint.s);
  path_point.laneid=(tp.pathpoint.laneid);
  trajectory_point->trajectorypoint.v=(tp.v);
  trajectory_point->trajectorypoint.a=(tp.a);
  trajectory_point->trajectorypoint.relativetime=(
      tp.relativetime);
  trajectory_point->trajectorypoint
      .gaussianinfo
      =(tp.gaussianinfo);
}

}  // namespace planning
}  // namespace apollo