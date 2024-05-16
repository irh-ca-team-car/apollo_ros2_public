/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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

#include "modules/prediction/common/feature_output.h"

#include "absl/strings/str_cat.h"
#include "cyber/common/file.h"
#include "modules/common/util/util.h"
#include "modules/prediction/common/prediction_system_gflags.h"

namespace apollo {
namespace prediction {

using apollo::common::TrajectoryPoint;

Features FeatureOutput::features_;
ListDataForLearning FeatureOutput::list_data_for_learning_;
ListPredictionResult FeatureOutput::list_prediction_result_;
ListFrameEnv FeatureOutput::list_frame_env_;
ListDataForTuning FeatureOutput::list_data_for_tuning_;
std::size_t FeatureOutput::idx_feature_ = 0;
std::size_t FeatureOutput::idx_learning_ = 0;
std::size_t FeatureOutput::idx_prediction_result_ = 0;
std::size_t FeatureOutput::idx_frame_env_ = 0;
std::size_t FeatureOutput::idx_tuning_ = 0;
std::mutex FeatureOutput::mutex_feature_;

void FeatureOutput::Close() {
  ADEBUG << "Close feature output";
  switch (FLAGS_prediction_offline_mode) {
    case 1: {
      WriteFeatureProto();
      break;
    }
    case 2: {
      WriteDataForLearning();
      break;
    }
    case 3: {
      WritePredictionResult();
      break;
    }
    case 4: {
      WriteFrameEnv();
      break;
    }
    case 5: {
      WriteDataForTuning();
      break;
    }
    default: {
      // No data dump
      break;
    }
  }
  Clear();
}

void FeatureOutput::Clear() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  idx_feature_ = 0;
  idx_learning_ = 0;
  idx_prediction_result_ = 0;
  idx_frame_env_ = 0;
  idx_tuning_ = 0;
  features_.feature.clear();
  list_data_for_learning_.dataforlearning.clear();
  list_prediction_result_.predictionresult.clear();
  list_frame_env_.frameenv.clear();
  list_data_for_tuning_.datafortuning.clear();
}

bool FeatureOutput::Ready() {
  Clear();
  return true;
}

void FeatureOutput::InsertFeatureProto(const Feature& feature) {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  features_.feature.push_back(feature);
}
void FeatureOutput::InsertDataForLearning(
    const Feature &feature, const std::vector<double> &feature_values,
    const std::string &category, const apollo_msgs::msg::ApollopredictionLaneSequence *lane_sequence_ptr)
{
  const std::vector<std::string> dummy_string_feature_values;
  InsertDataForLearning(feature, feature_values, dummy_string_feature_values,
                        category, lane_sequence_ptr);
}

void FeatureOutput::InsertDataForLearning(
    const Feature &feature, const std::vector<double> &feature_values,
    const std::vector<std::string> &string_feature_values,
    const std::string &category, const apollo_msgs::msg::ApollopredictionLaneSequence *lane_sequence_ptr)
{
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  DataForLearning& data_for_learning =
      list_data_for_learning_.dataforlearning.emplace_back();
  data_for_learning.set__id(feature.id);
  data_for_learning.set__timestamp(feature.timestamp);
  data_for_learning.featuresforlearning = {
      feature_values.begin(), feature_values.end()};
  data_for_learning.stringfeaturesforlearning = {
      string_feature_values.begin(), string_feature_values.end()};
  data_for_learning.set__category(category);
  ADEBUG << "Insert [" << category
         << "] data for learning with size = " << feature_values.size();
  if (lane_sequence_ptr != nullptr) {
    data_for_learning.set__lanesequenceid(
        lane_sequence_ptr->lanesequenceid);
  }
}

void FeatureOutput::InsertPredictionResult(
    const Obstacle *obstacle, const PredictionObstacle &prediction_obstacle,
    const apollo_msgs::msg::ApollopredictionObstacleConf &obstacle_conf, const apollo_msgs::msg::ApollopredictionScenario &scenario)
{
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  PredictionResult& prediction_result =
      list_prediction_result_.predictionresult.emplace_back();
  prediction_result.set__id(obstacle->id());
  prediction_result.set__timestamp(prediction_obstacle.timestamp);
  for (size_t i = 0; i < prediction_obstacle.trajectory.size(); ++i) {
    prediction_result.trajectory.push_back(
        prediction_obstacle.trajectory.at(i));
    prediction_result.obstacleconf=(obstacle_conf);
  }
  // Insert the scenario that the single obstacle is in
  if (scenario.type == Scenario::JUNCTION &&
      obstacle->IsInJunction(scenario.junctionid)) {
    prediction_result.scenario.set__type(Scenario::JUNCTION);
  } else if (obstacle->IsOnLane()) {
    prediction_result.scenario.set__type(Scenario::CRUISE);
  }
}

void FeatureOutput::InsertFrameEnv(const FrameEnv& frame_env) {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  list_frame_env_.frameenv.push_back(frame_env);
}

void FeatureOutput::InsertDataForTuning(
    const Feature &feature, const std::vector<double> &feature_values,
    const std::string &category, const apollo_msgs::msg::ApollopredictionLaneSequence &lane_sequence,
    const std::vector<TrajectoryPoint> &adc_trajectory)
{
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  DataForTuning& data_for_tuning = list_data_for_tuning_.datafortuning.emplace_back();
  data_for_tuning.set__id(feature.id);
  data_for_tuning.set__timestamp(feature.timestamp);
  data_for_tuning.valuesfortuning = {feature_values.begin(),
                                                   feature_values.end()};
  data_for_tuning.set__category(category);
  ADEBUG << "Insert [" << category
         << "] data for tuning with size = " << feature_values.size();
  data_for_tuning.set__lanesequenceid(lane_sequence.lanesequenceid);
  for (const auto& adc_traj_point : adc_trajectory) {
    data_for_tuning.adctrajectorypoint.push_back(adc_traj_point);
  }
}

void FeatureOutput::WriteFeatureProto() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  if (features_.feature.empty()) {
    ADEBUG << "Skip writing empty feature.";
  } else {
    const std::string file_name = absl::StrCat(
        FLAGS_prediction_data_dir, "/feature.", idx_feature_, ".bin");
    cyber::common::SetProtoToBinaryFile(features_, file_name);
    features_.feature.clear();
    ++idx_feature_;
  }
}

void FeatureOutput::WriteDataForLearning() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  if (list_data_for_learning_.dataforlearning.empty()) {
    ADEBUG << "Skip writing empty data_for_learning.";
  } else {
    const std::string file_name = absl::StrCat(
        FLAGS_prediction_data_dir, "/datalearn.", idx_learning_, ".bin");
    cyber::common::SetProtoToBinaryFile(list_data_for_learning_, file_name);
    list_data_for_learning_.dataforlearning.clear();
    ++idx_learning_;
  }
}

void FeatureOutput::WritePredictionResult() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  if (list_prediction_result_.predictionresult.empty()) {
    ADEBUG << "Skip writing empty prediction_result.";
  } else {
    const std::string file_name =
        absl::StrCat(FLAGS_prediction_data_dir, "/prediction_result.",
                     idx_prediction_result_, ".bin");
    cyber::common::SetProtoToBinaryFile(list_prediction_result_, file_name);
    list_prediction_result_.predictionresult.clear();
    ++idx_prediction_result_;
  }
}

void FeatureOutput::WriteFrameEnv() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  if (list_frame_env_.frameenv.empty()) {
    ADEBUG << "Skip writing empty prediction_result.";
  } else {
    const std::string file_name = absl::StrCat(
        FLAGS_prediction_data_dir, "/frame_env.", idx_frame_env_, ".bin");
    cyber::common::SetProtoToBinaryFile(list_frame_env_, file_name);
    list_frame_env_.frameenv.clear();
    ++idx_frame_env_;
  }
}

void FeatureOutput::WriteDataForTuning() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  if (list_data_for_tuning_.datafortuning.empty()) {
    ADEBUG << "Skip writing empty data_for_tuning.";
    return;
  }
  const std::string file_name = absl::StrCat(
      FLAGS_prediction_data_dir, "/datatuning.", idx_tuning_, ".bin");
  cyber::common::SetProtoToBinaryFile(list_data_for_tuning_, file_name);
  list_data_for_tuning_.datafortuning.clear();
  ++idx_tuning_;
}

int FeatureOutput::Size() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  return features_.feature.size();
}

int FeatureOutput::SizeOfDataForLearning() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  return list_data_for_learning_.dataforlearning.size();
}

int FeatureOutput::SizeOfPredictionResult() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  return list_prediction_result_.predictionresult.size();
}

int FeatureOutput::SizeOfFrameEnv() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  return list_frame_env_.frameenv.size();
}

int FeatureOutput::SizeOfDataForTuning() {
  UNIQUE_LOCK_MULTITHREAD(mutex_feature_);
  return list_data_for_tuning_.datafortuning.size();
}

}  // namespace prediction
}  // namespace apollo
