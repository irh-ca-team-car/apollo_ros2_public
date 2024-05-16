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
#include "component/lidar_output.h"
#include "modules/perception/onboard/msg_serializer/msg_serializer.h"
#include "modules/perception/onboard/internal_messages/inner_component_messages.h"
#include "modules/perception/factories.h"

#include "modules/perception/onboard/common_flags/common_flags.h"

namespace apollo {
namespace perception {
namespace onboard {

bool LidarOutputComponent::Init() {
  InitFactories();

  AINFO << "Setting gflags";

  INIT_FLAG_bool(obs_enable_hdmap_input, true, "enable hdmap input for roi filter");
  INIT_FLAG_bool(obs_enable_visualization, false,
            "whether to send message for visualization");
  INIT_FLAG_string(obs_screen_output_dir, "./",
              "output dir. for saving visualization screenshots");
  INIT_FLAG_bool(obs_benchmark_mode, false,
            "whether open benchmark mode, default false");
  INIT_FLAG_bool(obs_save_fusion_supplement, false,
            "whether save fusion supplement data, default false");
  INIT_FLAG_bool(start_visualizer, false, "Whether to start visualizer");
  
  AINFO << "Gflags set";

  writer_ =
      node_->CreateWriter<PerceptionObstacles>("/apollo/perception/obstacles");
  sensframe_reader_ = node_->CreateReaderJson<SensorFrameMessage>("/apollo/perception/inner/PrefusedObjects", std::bind(&LidarOutputComponent::Proc, this, std::placeholders::_1));
  return true;
}

bool LidarOutputComponent::Proc(
    const std::shared_ptr<SensorFrameMessage>& message) {
  std::shared_ptr<PerceptionObstacles> out_message(new PerceptionObstacles);

  if (message->frame_ == nullptr) {
    AERROR << "Failed to get frame in message.";
    return false;
  }

  if (!MsgSerializer::SerializeMsg(
          message->timestamp_, message->lidar_timestamp_, message->seq_num_,
          message->frame_->objects, message->error_code_, out_message.get())) {
    AERROR << "Failed to serialize PerceptionObstacles object.";
    return false;
  }

  writer_->Write(out_message);
  // Send("/apollo/perception/obstacles", out_message);

  return true;
}


}  // namespace onboard
}  // namespace perception
}  // namespace apollo

CYBER_REGISTER_COMPONENT(LidarOutputComponent);
