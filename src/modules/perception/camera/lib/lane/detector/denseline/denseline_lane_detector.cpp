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
#include "modules/perception/camera/lib/lane/detector/denseline/denseline_lane_detector.h"

#include <algorithm>
#include <map>

#include "cyber/cyber.h"
#include "modules/perception/camera/common/util.h"
#include "modules/perception/inference/inference_factory.h"
#include "modules/perception/inference/utils/resize.h"

namespace apollo {
namespace perception {
namespace camera {

using cyber::common::GetAbsolutePath;
bool DenselineLaneDetector::Init(const LaneDetectorInitOptions &options) {
  std::string proto_path = GetAbsolutePath(options.root_dir, options.conf_file);
  if (!cyber::common::GetProtoFromASCIIFile (proto_path, &denseline_param_)) {
    AINFO_EVERY(60000) << "load proto param failed, root dir: " << options.root_dir;
    return false;
  }
  std::string param_str;
  AINFO_EVERY(60000) << "denseline param: " << param_str;

  const auto model_param = denseline_param_.modelparam;
  std::string model_root =
      GetAbsolutePath(options.root_dir, model_param.modelname);
  std::string proto_file =
      GetAbsolutePath(model_root, model_param.protofile);
  std::string weight_file =
      GetAbsolutePath(model_root, model_param.weightfile);
  base_camera_model_ = options.base_camera_model;
  if (base_camera_model_ == nullptr) {
    AERROR_EVERY(60000) << "options.intrinsic is nullptr!";
    input_height_ = 1080;
    input_width_ = 1920;
  } else {
    input_height_ = static_cast<uint16_t>(base_camera_model_->get_height());
    input_width_ = static_cast<uint16_t>(base_camera_model_->get_width());
  }
  ACHECK(input_width_ > 0) << "input width should be more than 0";
  ACHECK(input_height_ > 0) << "input height should be more than 0";

  AINFO_EVERY(60000) << "input_height: " << input_height_;
  AINFO_EVERY(60000) << "input_width: " << input_width_;

  image_scale_ = model_param.resizescale;
  input_offset_y_ = static_cast<uint16_t>(model_param.inputoffsety);
  input_offset_x_ = static_cast<uint16_t>(model_param.inputoffsetx);
  crop_height_ = static_cast<uint16_t>(model_param.cropheight);
  crop_width_ = static_cast<uint16_t>(model_param.cropwidth);

  CHECK_LE(crop_height_, input_height_)
      << "crop height larger than input height";
  CHECK_LE(crop_width_, input_width_) << "crop width larger than input width";

  if (model_param.isbgr) {
    data_provider_image_option_.target_color = base::Color::BGR;
    image_mean_[0] = model_param.meanb;
    image_mean_[1] = model_param.meang;
    image_mean_[2] = model_param.meanr;
  } else {
    data_provider_image_option_.target_color = base::Color::RGB;
    image_mean_[0] = model_param.meanr;
    image_mean_[1] = model_param.meang;
    image_mean_[2] = model_param.meanb;
  }
  data_provider_image_option_.do_crop = true;
  data_provider_image_option_.crop_roi.x = input_offset_x_;
  data_provider_image_option_.crop_roi.y = input_offset_y_;
  data_provider_image_option_.crop_roi.height = crop_height_;
  data_provider_image_option_.crop_roi.width = crop_width_;

  cudaDeviceProp prop;
  cudaGetDeviceProperties(&prop, options.gpu_id);
  AINFO_EVERY(60000) << "GPU: " << prop.name;

  const auto netparam = denseline_param_.netparam;
  net_inputs_.push_back(netparam.inblob);
  net_outputs_.push_back(netparam.outblob);
  std::copy(netparam.internalblobint8.begin(),
            netparam.internalblobint8.end(),
            std::back_inserter(net_outputs_));

  for (auto name : net_inputs_) {
    AINFO_EVERY(60000) << "net input blobs: " << name;
  }
  for (auto name : net_outputs_) {
    AINFO_EVERY(60000) << "net output blobs: " << name;
  }

  const auto &model_type = model_param.modeltype;
  AINFO_EVERY(60000) << "model_type: " << model_type;
  rt_net_.reset(inference::CreateInferenceByName(model_type, proto_file,
                                                 weight_file, net_outputs_,
                                                 net_inputs_, model_root));
  ACHECK(rt_net_ != nullptr);
  rt_net_->set_gpu_id(options.gpu_id);

  resize_height_ = static_cast<uint16_t>(crop_height_ * image_scale_);
  resize_width_ = static_cast<uint16_t>(crop_width_ * image_scale_);
  ACHECK(resize_width_ > 0) << "resize width should be more than 0";
  ACHECK(resize_height_ > 0) << "resize height should be more than 0";

  std::vector<int> shape = {1, 3, resize_height_, resize_width_};

  std::map<std::string, std::vector<int>> input_reshape{
      {net_inputs_[0], shape}};
  AINFO_EVERY(60000) << "input_reshape: " << input_reshape[net_inputs_[0]][0] << ", "
        << input_reshape[net_inputs_[0]][1] << ", "
        << input_reshape[net_inputs_[0]][2] << ", "
        << input_reshape[net_inputs_[0]][3];
  if (!rt_net_->Init(input_reshape)) {
    AINFO_EVERY(60000) << "net init fail.";
    return false;
  }

  for (auto &input_blob_name : net_inputs_) {
    auto input_blob = rt_net_->get_blob(input_blob_name);
    AINFO_EVERY(60000) << input_blob_name << ": " << input_blob->channels() << " "
          << input_blob->height() << " " << input_blob->width();
  }

  for (auto &output_blob_name : net_outputs_) {
    auto output_blob = rt_net_->get_blob(output_blob_name);
    AINFO_EVERY(60000) << output_blob_name << " : " << output_blob->channels() << " "
          << output_blob->height() << " " << output_blob->width();
  }

  return true;
}

bool DenselineLaneDetector::Detect(const LaneDetectorOptions &options,
                                   CameraFrame *frame) {
                                    UNUSED(options);
  if (frame == nullptr) {
    AINFO_EVERY(60000) << "camera frame is empty.";
    return false;
  }

  auto data_provider = frame->data_provider;
  if (input_width_ != data_provider->src_width()) {
    AERROR_EVERY(60000) << "Input size is not correct: " << input_width_ << " vs "
           << data_provider->src_width();
    return false;
  }
  if (input_height_ != data_provider->src_height()) {
    AERROR_EVERY(60000) << "Input size is not correct: " << input_height_ << " vs "
           << data_provider->src_height();
    return false;
  }

  if (!data_provider->GetImage(data_provider_image_option_, &image_src_)) {
    return false;
  }

  //  bottom 0 is data
  auto input_blob = rt_net_->get_blob(net_inputs_[0]);
  auto blob_channel = input_blob->channels();
  auto blob_height = input_blob->height();
  auto blob_width = input_blob->width();
  AINFO_EVERY(60000) << "input_blob: " << blob_channel << " " << blob_height << " " << blob_width;

  if (blob_height != resize_height_) {
    AERROR_EVERY(60000) << "height is not equal" << blob_height << " vs " << resize_height_;
    return false;
  }
  if (blob_width != resize_width_) {
    AERROR_EVERY(60000) << "width is not equal" << blob_width << " vs " << resize_width_;
    return false;
  }
  ADEBUG << "image_blob: " << image_src_.blob()->shape_string();
  ADEBUG << "input_blob: " << input_blob->shape_string();

  inference::ResizeGPU(
      image_src_, input_blob, static_cast<int>(crop_width_), 0,
      static_cast<float>(image_mean_[0]), static_cast<float>(image_mean_[1]),
      static_cast<float>(image_mean_[2]), false, static_cast<float>(1.0));
  AINFO_EVERY(60000) << "resize gpu finish.";
  cudaDeviceSynchronize();
  rt_net_->Infer();
  AINFO_EVERY(60000) << "infer finish.";

  frame->lane_detected_blob = rt_net_->get_blob(net_outputs_[0]);
  ADEBUG << frame->lane_detected_blob->shape_string();
  return true;
}

std::string DenselineLaneDetector::Name() const {
  return "DenselineLaneDetector";
}

REGISTER_LANE_DETECTOR(DenselineLaneDetector);

}  // namespace camera
}  // namespace perception
}  // namespace apollo
