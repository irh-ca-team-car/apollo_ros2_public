/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include "modules/perception/camera/app/traffic_light_camera_perception.h"

#include "cyber/cyber.h"
#include "modules/common/util/perf_util.h"
#include "modules/perception/camera/common/util.h"
#include "modules/perception/camera/lib/traffic_light/detector/detection/detection.h"
#include "modules/perception/camera/lib/traffic_light/detector/recognition/recognition.h"
#include "modules/perception/camera/lib/traffic_light/tracker/semantic_decision.h"

namespace apollo {
namespace perception {
namespace camera {

using cyber::common::GetAbsolutePath;

bool TrafficLightCameraPerception::Init(
    const CameraPerceptionInitOptions &options) {
  std::string work_root = "";
  if (options.use_cyber_work_root) {
    work_root = GetCyberWorkRoot();
  }
  std::string proto_path = GetAbsolutePath(options.root_dir, options.conf_file);
  apollo_msgs::msg::ApolloperceptioncameraappDetectorParam interparam;
  proto_path = GetAbsolutePath(work_root, proto_path);
  AINFO_EVERY(60000) << "proto_path " << proto_path;
  /*if (!cyber::common::GetProtoFromFile(proto_path, &tl_param_)) {
    AINFO_EVERY(60000) << "load proto param failed, root dir: " << options.root_dir;
    return false;
  }*/
  auto currentNode = apollo::cyber::currentNode;
  tl_param_.gpuid = currentNode->declare_parameter<int>("gpu_id", 0);
  
  interparam.pluginparam.name = currentNode->declare_parameter<std::string>("name", "TrafficLightDetection");
  interparam.pluginparam.rootdir = currentNode->declare_parameter<std::string>("root_dir", "<root>/data/perception/production/data/perception/camera/models/traffic_light_detection");
  interparam.pluginparam.configfile = currentNode->declare_parameter<std::string>("config_file", "detection.pt");
  tl_param_.detectorparam.push_back(interparam);
  
  interparam.pluginparam.name = currentNode->declare_parameter<std::string>("name", "TrafficLightRecognition");
  interparam.pluginparam.rootdir = currentNode->declare_parameter<std::string>("root_dir", "<root>/data/perception/production/data/perception/camera/models/traffic_light_recognition");
  interparam.pluginparam.configfile = currentNode->declare_parameter<std::string>("config_file", "recognition.pt");
  tl_param_.detectorparam.push_back(interparam);
  
  tl_param_.trackerparam.pluginparam.name = currentNode->declare_parameter<std::string>("name", "SemanticReviser");
  tl_param_.trackerparam.pluginparam.rootdir = currentNode->declare_parameter<std::string>("root_dir", "<root>/data/perception/production/data/perception/camera/models/traffic_light_tracker");
  tl_param_.trackerparam.pluginparam.configfile = currentNode->declare_parameter<std::string>("config_file", "semantic.pt");

  TrafficLightDetectorInitOptions init_options;
  auto plugin_param = tl_param_.detectorparam[0].pluginparam;

  init_options.root_dir = GetAbsolutePath(work_root, plugin_param.rootdir);
  init_options.conf_file = plugin_param.configfile;
  init_options.gpu_id = tl_param_.gpuid;
  detector_.reset(BaseTrafficLightDetectorRegisterer::GetInstanceByName(
      plugin_param.name));
  ACHECK(detector_ != nullptr);
  if (!detector_->Init(init_options)) {
    AERROR_EVERY(60000) << "tl detector init failed";
    return false;
  }

  plugin_param = tl_param_.detectorparam[1].pluginparam;
  init_options.root_dir = GetAbsolutePath(work_root, plugin_param.rootdir);
  init_options.conf_file = plugin_param.configfile;
  init_options.gpu_id = tl_param_.gpuid;
  recognizer_.reset(BaseTrafficLightDetectorRegisterer::GetInstanceByName(
      plugin_param.name));
  ACHECK(recognizer_ != nullptr);
  if (!recognizer_->Init(init_options)) {
    AERROR_EVERY(60000) << "tl recognizer init failed";
    return false;
  }

  TrafficLightTrackerInitOptions tracker_init_options;
  auto tracker_plugin_param = tl_param_.trackerparam.pluginparam;
  tracker_init_options.root_dir =
      GetAbsolutePath(work_root, tracker_plugin_param.rootdir);
  tracker_init_options.conf_file = tracker_plugin_param.configfile;
  tracker_.reset(BaseTrafficLightTrackerRegisterer::GetInstanceByName(
      tracker_plugin_param.name));
  ACHECK(tracker_ != nullptr);
  AINFO_EVERY(60000) << tracker_init_options.root_dir << " "
        << tracker_init_options.conf_file;
  if (!tracker_->Init(tracker_init_options)) {
    AERROR_EVERY(60000) << "tl tracker init failed";
    return false;
  }

  AINFO_EVERY(60000) << "tl pipeline init done";
  return true;
}

bool TrafficLightCameraPerception::Perception(
    const CameraPerceptionOptions &options, CameraFrame *frame) {
  UNUSED(options);
  PERF_FUNCTION();
  PERF_BLOCK_START();
  TrafficLightDetectorOptions detector_options;
  if (!detector_->Detect(detector_options, frame)) {
    AERROR_EVERY(60000) << "tl failed to detect.";
    return false;
  }

  TrafficLightDetectorOptions recognizer_options;
  if (!recognizer_->Detect(recognizer_options, frame)) {
    AERROR_EVERY(60000) << "tl failed to recognize.";
    return false;
  }

  TrafficLightTrackerOptions tracker_options;
  if (!tracker_->Track(tracker_options, frame)) {
    AERROR_EVERY(60000) << "tl failed to track.";
    return false;
  }
  return true;
}

}  // namespace camera
}  // namespace perception
}  // namespace apollo
