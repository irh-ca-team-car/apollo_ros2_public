/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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

#include "modules/perception/lidar/lib/tracker/multi_lidar_fusion/mlf_track_object_distance.h"

#include "cyber/cyber.h"
#include "modules/perception/lib/config_manager/config_manager.h"
#include "modules/perception/lidar/lib/tracker/association/distance_collection.h"
#include "modules/perception/lidar/lib/tracker/multi_lidar_fusion/proto/multi_lidar_fusion_config.pb.h"

namespace apollo {
namespace perception {
namespace lidar {

// location dist weight, irection dist weight, bbox size dist weight,
// point num dist weight, histogram dist weight, centroid shift dist weight
// bbox iou dist weight, semantic map dist weight
const std::vector<float> MlfTrackObjectDistance::kForegroundDefaultWeight = {
    0.6f, 0.2f, 0.1f, 0.1f, 0.5f, 0.f, 0.f, 0.6f};
// location dist weight, irection dist weight, bbox size dist weight,
// point num dist weight, histogram dist weight, centroid shift dist weight
// bbox iou dist weight
const std::vector<float> MlfTrackObjectDistance::kBackgroundDefaultWeight = {
    0.f, 0.f, 0.f, 0.f, 0.f, 0.2f, 0.8f};

bool MlfTrackObjectDistance::Init(
    const MlfTrackObjectDistanceInitOptions& options) {
  UNUSED(options);
  auto config_manager = lib::ConfigManager::Instance();
  const lib::ModelConfig* model_config = nullptr;
  ACHECK(config_manager->GetModelConfig(Name(), &model_config));
  const std::string work_root = config_manager->work_root();
  std::string config_file;
  std::string root_path;
  ACHECK(model_config->get_value("root_path", &root_path));
  config_file = cyber::common::GetAbsolutePath(work_root, root_path);
  config_file = cyber::common::GetAbsolutePath(
      config_file, "mlf_track_object_distance.json");
  MlfDistanceConfig config;
  ACHECK(cyber::common::GetProtoFromASCIIFile(config_file, &config));

  foreground_weight_table_.clear();
  background_weight_table_.clear();
  for (size_t i = 0; i < config.foregroundweights.size(); ++i) {
    const auto& fgws = config.foregroundweights[i];
    const std::string& name = fgws.sensornamepair;
    std::vector<float> weights(7, 0.f);
    weights[0] = fgws.locationdistweight;
    weights[1] = fgws.directiondistweight;
    weights[2] = fgws.bboxsizedistweight;
    weights[3] = fgws.pointnumdistweight;
    weights[4] = fgws.histogramdistweight;
    weights[5] = fgws.centroidshiftdistweight;
    weights[6] = fgws.bboxioudistweight;
    weights[7] = fgws.semanticmapdistweight;
    foreground_weight_table_.emplace(name, weights);
  }
  for (size_t i = 0; i < config.backgroundweights.size(); ++i) {
    const auto& bgws = config.backgroundweights[i];
    const std::string& name = bgws.sensornamepair;
    std::vector<float> weights(7, 0.f);
    weights[0] = bgws.locationdistweight;
    weights[1] = bgws.directiondistweight;
    weights[2] = bgws.bboxsizedistweight;
    weights[3] = bgws.pointnumdistweight;
    weights[4] = bgws.histogramdistweight;
    weights[5] = bgws.centroidshiftdistweight;
    weights[6] = bgws.bboxioudistweight;
    background_weight_table_.emplace(name, weights);
  }

  return true;
}

float MlfTrackObjectDistance::ComputeDistance(
    const TrackedObjectConstPtr& object,
    const MlfTrackDataConstPtr& track) const {
  bool is_background = object->is_background;
  const TrackedObjectConstPtr latest_object = track->GetLatestObject().second;
  std::string key = latest_object->sensor_info.name + object->sensor_info.name;
  const std::vector<float>* weights = nullptr;
  if (is_background) {
    auto iter = background_weight_table_.find(key);
    if (iter == background_weight_table_.end()) {
      weights = &kBackgroundDefaultWeight;
    } else {
      weights = &iter->second;
    }
  } else {
    auto iter = foreground_weight_table_.find(key);
    if (iter == foreground_weight_table_.end()) {
      weights = &kForegroundDefaultWeight;
    } else {
      weights = &iter->second;
    }
  }
  if (weights == nullptr || weights->size() < 7) {
    AERROR_EVERY(60000) << "Invalid weights";
    return 1e+10f;
  }
  float distance = 0.f;
  float delta = 1e-10f;

  double current_time = object->object_ptr->latest_tracked_time;
  track->PredictState(current_time);

  double time_diff =
      track->age_ ? current_time - track->latest_visible_time_ : 0;
  if (weights->at(0) > delta) {
    distance +=
        weights->at(0) * LocationDistance(latest_object, track->predict_.state,
                                          object, time_diff);
  }
  if (weights->at(1) > delta) {
    distance +=
        weights->at(1) * DirectionDistance(latest_object, track->predict_.state,
                                           object, time_diff);
  }
  if (weights->at(2) > delta) {
    distance +=
        weights->at(2) * BboxSizeDistance(latest_object, track->predict_.state,
                                          object, time_diff);
  }
  if (weights->at(3) > delta) {
    distance +=
        weights->at(3) * PointNumDistance(latest_object, track->predict_.state,
                                          object, time_diff);
  }
  if (weights->at(4) > delta) {
    distance +=
        weights->at(4) * HistogramDistance(latest_object, track->predict_.state,
                                           object, time_diff);
  }
  if (weights->at(5) > delta) {
    distance += weights->at(5) * CentroidShiftDistance(latest_object,
                                                       track->predict_.state,
                                                       object, time_diff);
  }
  if (weights->at(6) > delta) {
    distance += weights->at(6) *
                BboxIouDistance(latest_object, track->predict_.state, object,
                                time_diff, background_object_match_threshold_);
  }
  // for foreground, calculate semantic map based distance
//  if (!is_background) {
//    distance += weights->at(7) * SemanticMapDistance(*track, object);
//  }

  return distance;
}

}  // namespace lidar
}  // namespace perception
}  // namespace apollo
