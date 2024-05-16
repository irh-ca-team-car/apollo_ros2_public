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
#include "modules/perception/radar/lib/preprocessor/conti_ars_preprocessor/conti_ars_preprocessor.h"
#include "modules/common/util/perf_util.h"

namespace apollo {
namespace perception {
namespace radar {

int ContiArsPreprocessor::current_idx_ = 0;
std::unordered_map<int, int> ContiArsPreprocessor::local2global_;

bool ContiArsPreprocessor::Init() {
  std::string model_name = "ContiArsPreprocessor";
  const lib::ModelConfig* model_config = nullptr;
  ACHECK(lib::ConfigManager::Instance()->GetModelConfig(model_name,
                                                        &model_config));
  ACHECK(model_config->get_value("delay_time", &delay_time_));
  return true;
}

bool ContiArsPreprocessor::Preprocess(
    const drivers::ContiRadar& raw_obstacles,
    const PreprocessorOptions& options,
    drivers::ContiRadar* corrected_obstacles) {
  UNUSED(options);
  PERF_FUNCTION();
  SkipObjects(raw_obstacles, corrected_obstacles);
  ExpandIds(corrected_obstacles);
  CorrectTime(corrected_obstacles);
  return true;
}

std::string ContiArsPreprocessor::Name() const {
  return "ContiArsPreprocessor";
}

void ContiArsPreprocessor::SkipObjects(
    const drivers::ContiRadar& raw_obstacles,
    drivers::ContiRadar* corrected_obstacles) {
  corrected_obstacles->apolloheader=raw_obstacles.apolloheader;
  double timestamp = raw_obstacles.apolloheader.timestampsec - 1e-6;
  for (const auto& contiobs : raw_obstacles.contiobs) {
    double object_timestamp = contiobs.apolloheader.timestampsec;
    if (object_timestamp > timestamp &&
        object_timestamp < timestamp + CONTI_ARS_INTERVAL) {
      corrected_obstacles->contiobs.push_back(contiobs);
    }
  }
  if (raw_obstacles.contiobs.size() > corrected_obstacles->contiobs.size()) {
    AINFO_EVERY(60000) << "skip objects: " << raw_obstacles.contiobs.size() << "-> "
          << corrected_obstacles->contiobs.size();
  }
}

void ContiArsPreprocessor::ExpandIds(drivers::ContiRadar* corrected_obstacles) {
  for (size_t iobj = 0; iobj < corrected_obstacles->contiobs.size(); ++iobj) {
    const auto& contiobs = corrected_obstacles->contiobs[iobj];
    int id = contiobs.obstacleid;
    int corrected_id = 0;
    auto ob = local2global_.find(id);
    if (ob != local2global_.end()) {
      if (CONTI_NEW == contiobs.measstate) {
        corrected_id = GetNextId();
        ob->second = corrected_id;
      } else {
        corrected_id = ob->second;
      }
    } else {
      corrected_id = GetNextId();
      local2global_.insert({id, corrected_id});
    }
    corrected_obstacles->contiobs[iobj].obstacleid=corrected_id;
  }
}

void ContiArsPreprocessor::CorrectTime(
    drivers::ContiRadar* corrected_obstacles) {
  double correct_timestamp =
      corrected_obstacles->apolloheader.timestampsec - delay_time_;
  corrected_obstacles->apolloheader.timestampsec=correct_timestamp;
}

int ContiArsPreprocessor::GetNextId() {
  ++current_idx_;
  if (MAX_RADAR_IDX == current_idx_) {
    current_idx_ = 1;
  }
  return current_idx_;
}

PERCEPTION_REGISTER_PREPROCESSOR(ContiArsPreprocessor);

}  // namespace radar
}  // namespace perception
}  // namespace apollo
