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

#include "modules/transform/transform_broadcaster.h"

#include "modules/common/adapters/adapter_gflags.h"
namespace apollo {
namespace transform {

TransformBroadcaster::TransformBroadcaster(cyber::ComponentBase *node) {
  node_=node;
  //cyber::proto::RoleAttributes attr;
  //attr.set_channel_name(FLAGS_tf_topic);
  writer_ = node_->CreateWriter<tf2_msgs::msg::TFMessage>(FLAGS_tf_topic);
}

void TransformBroadcaster::SendTransform(const TransformStamped& transform) {
  std::vector<TransformStamped> transforms;
  transforms.emplace_back(transform);
  SendTransform(transforms);
}
void TransformBroadcaster::SendTransform(
    const std::vector<TransformStamped>& transforms) {
  auto message = std::make_shared<tf2_msgs::msg::TFMessage>();
  message->transforms = {transforms.begin(), transforms.end()};
  writer_->Write(message);
}

}  // namespace transform
}  // namespace apollo
