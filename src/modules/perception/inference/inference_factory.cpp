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

#include "modules/perception/inference/inference_factory.h"

#include "modules/perception/inference/libtorch/torch_det.h"
#include "modules/perception/inference/libtorch/torch_net.h"
#include "modules/perception/inference/onnx/libtorch_obstacle_detector.h"
#include "modules/perception/inference/tensorrt/rt_net.h"

namespace apollo {
namespace perception {
namespace inference {

Inference *CreateInferenceByName(const std::string &name,
                                 const std::string &proto_file,
                                 const std::string &weight_file,
                                 const std::vector<std::string> &outputs,
                                 const std::vector<std::string> &inputs,
                                 const std::string &model_root) {
  (void)(model_root);
  ADEBUG << name <<  " " << proto_file << " " << weight_file << " " << model_root;
  if (name == "RTNet")
  {
    return new RTNet(proto_file, weight_file, outputs, inputs);
  }
  else if (name == "RTNetInt8")
  {
    return new RTNet(proto_file, weight_file, outputs, inputs, model_root);
  }
  else if (name == "TorchDet")
  {
    return new TorchDet(proto_file, weight_file, outputs, inputs);
  }
  else if (name == "TorchNet")
  {
    return new TorchNet(proto_file, weight_file, outputs, inputs);
  }
  else if (name == "Obstacle")
  {
    return new ObstacleDetector(proto_file, weight_file, outputs, inputs);
  }
  return nullptr;
}

}  // namespace inference
}  // namespace perception
}  // namespace apollo
