/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
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
#include "modules/perception/camera/lib/lane/detector/darkSCNN/darkSCNN_lane_detector.h"

#include <algorithm>
#include <map>

#include "cyber/cyber.h"

#include "modules/perception/camera/common/util.h"
#include "modules/perception/inference/inference_factory.h"
#include "modules/perception/inference/utils/resize.h"

namespace apollo {
namespace perception {
namespace camera {

using apollo::cyber::common::GetAbsolutePath;
using apollo::cyber::common::GetProtoFromASCIIFile;

bool DarkSCNNLaneDetector::Init(const LaneDetectorInitOptions &options) {
  std::string proto_path = GetAbsolutePath(options.root_dir, options.conf_file);
  if (!apollo::cyber::common::GetProtoFromFile(proto_path, &darkscnn_param_))
  {
    AINFO_EVERY(60000) << "load proto param failed, root dir: " << options.root_dir;
    AINFO_EVERY(60000) << "load proto param failed, proto_path: " << proto_path;
    return false;
  }
   AINFO_EVERY(60000) << " darkscnn_param_: " << darkscnn_param_;
  const auto model_param = darkscnn_param_.modelparam;
  std::string model_root =
      GetAbsolutePath(options.root_dir, model_param.modelname);
  std::string proto_file =
      GetAbsolutePath(model_root, model_param.protofile);
  std::string weight_file =
      GetAbsolutePath(model_root, model_param.weightfile);
  AINFO_EVERY(60000) << " proto_file: " << proto_file;
  AINFO_EVERY(60000) << " weight_file: " << weight_file;
  AINFO_EVERY(60000) << " model_root: " << model_root;

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

  // compute image provider parameters
  input_offset_y_ = static_cast<uint16_t>(model_param.inputoffsety);
  input_offset_x_ = static_cast<uint16_t>(model_param.inputoffsetx);
  resize_height_ = static_cast<uint16_t>(model_param.resizeheight);
  resize_width_ = static_cast<uint16_t>(model_param.resizewidth);
  crop_height_ = static_cast<uint16_t>(model_param.cropheight);
  crop_width_ = static_cast<uint16_t>(model_param.cropwidth);
  confidence_threshold_lane_ = model_param.confidencethreshold;

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

  const auto net_param = darkscnn_param_.netparam;
  net_inputs_.push_back(net_param.inputblob);
  net_outputs_.push_back(net_param.segblob);
  if (model_param.modeltype == "CaffeNet" && net_param.vptblob!=std::string() &&
      net_param.vptblob.size() > 0) {
    net_outputs_.push_back(net_param.vptblob);
  }

  for (auto name : net_inputs_) {
    AINFO_EVERY(60000) << "net input blobs: " << name;
  }
  for (auto name : net_outputs_) {
    AINFO_EVERY(60000) << "net output blobs: " << name;
  }

  // initialize caffe net
  const auto &model_type = model_param.modeltype;
  AINFO_EVERY(60000) << "model_type: " << model_type;
  cnnadapter_lane_.reset(
      inference::CreateInferenceByName(model_type, proto_file, weight_file,
                                       net_outputs_, net_inputs_, model_root));
  ACHECK(cnnadapter_lane_ != nullptr);
  cnnadapter_lane_->set_gpu_id(options.gpu_id);
  ACHECK(resize_width_ > 0) << "resize width should be more than 0";
  ACHECK(resize_height_ > 0) << "resize height should be more than 0";
  std::vector<int> shape = {1, 3, resize_height_, resize_width_};
  std::map<std::string, std::vector<int>> input_reshape{
      {net_inputs_[0], shape}};
  AINFO_EVERY(60000) << "input_reshape: " << input_reshape[net_inputs_[0]][0] << ", "
        << input_reshape[net_inputs_[0]][1] << ", "
        << input_reshape[net_inputs_[0]][2] << ", "
        << input_reshape[net_inputs_[0]][3];
  if (!cnnadapter_lane_->Init(input_reshape)) {
    AINFO_EVERY(60000) << "net init fail.";
    return false;
  }

  for (auto &input_blob_name : net_inputs_) {
    auto input_blob = cnnadapter_lane_->get_blob(input_blob_name);
    AINFO_EVERY(60000) << input_blob_name << ": " << input_blob->channels() << " "
          << input_blob->height() << " " << input_blob->width();
  }

  auto output_blob = cnnadapter_lane_->get_blob(net_outputs_[0]);
  AINFO_EVERY(60000) << net_outputs_[0] << " : " << output_blob->channels() << " "
        << output_blob->height() << " " << output_blob->width();
  lane_output_height_ = output_blob->height();
  lane_output_width_ = output_blob->width();
  num_lanes_ = output_blob->channels();

  if (net_outputs_.size() > 1) {
    vpt_mean_.push_back(model_param.vptmeandx);
    vpt_mean_.push_back(model_param.vptmeandy);
    vpt_std_.push_back(model_param.vptstddx);
    vpt_std_.push_back(model_param.vptstddy);
  }

  std::vector<int> lane_shape = {1, 1, lane_output_height_, lane_output_width_};
  lane_blob_.reset(new base::Blob<float>(lane_shape));

  return true;
}

bool DarkSCNNLaneDetector::Detect(const LaneDetectorOptions &options,
                                  CameraFrame *frame) {
  UNUSED(options);
  if (frame == nullptr) {
    AINFO_EVERY(60000) << "camera frame is empty.";
    return false;
  }

  auto start = std::chrono::high_resolution_clock::now();
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

  // use data provider to crop input image
  if (!data_provider->GetImage(data_provider_image_option_, &image_src_)) {
    return false;
  }

  //  bottom 0 is data
  auto input_blob = cnnadapter_lane_->get_blob(net_inputs_[0]);
  auto blob_channel = input_blob->channels();
  auto blob_height = input_blob->height();
  auto blob_width = input_blob->width();
  ADEBUG << "input_blob: " << blob_channel << " " << blob_height << " "
         << blob_width;

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
  // resize the cropped image into network input blob
  inference::ResizeGPU(
      image_src_, input_blob, static_cast<int>(crop_width_), 0,
      static_cast<float>(image_mean_[0]), static_cast<float>(image_mean_[1]),
      static_cast<float>(image_mean_[2]), false, static_cast<float>(1.0));
  ADEBUG << "resize gpu finish.";
  cudaDeviceSynchronize();
  cnnadapter_lane_->Infer();
  ADEBUG << "infer finish.";

  auto elapsed_1 = std::chrono::high_resolution_clock::now() - start;
  int64_t microseconds_1 =
      std::chrono::duration_cast<std::chrono::microseconds>(elapsed_1).count();
  time_1 += microseconds_1;

  // convert network output to color map
  const auto seg_blob = cnnadapter_lane_->get_blob(net_outputs_[0]);
  ADEBUG << "seg_blob: " << seg_blob->shape_string();
  std::vector<cv::Mat> masks;
  for (int i = 0; i < num_lanes_; ++i) {
    cv::Mat tmp(lane_output_height_, lane_output_width_, CV_32FC1);
    memcpy(tmp.data,
           seg_blob->cpu_data() + lane_output_width_ * lane_output_height_ * i,
           lane_output_width_ * lane_output_height_ * sizeof(float));
    // cv::resize(tmp
    // , tmp, cv::Size(lane_output_width_, lane_output_height_), 0,
    //            0);
    masks.push_back(tmp);
  }
  std::vector<int> cnt_pixels(13, 0);
  cv::Mat mask_color(lane_output_height_, lane_output_width_, CV_32FC1);
  mask_color.setTo(cv::Scalar(0));
  for (int c = 0; c < num_lanes_; ++c) {
    for (int h = 0; h < masks[c].rows; ++h) {
      for (int w = 0; w < masks[c].cols; ++w) {
        if (masks[c].at<float>(h, w) >= confidence_threshold_lane_) {
          mask_color.at<float>(h, w) = static_cast<float>(c);
          cnt_pixels[c]++;
        }
      }
    }
  }
  memcpy(lane_blob_->mutable_cpu_data(),
         reinterpret_cast<float *>(mask_color.data),
         lane_output_width_ * lane_output_height_ * sizeof(float));
  // Don't use this way to copy data, it will modify data
  // lane_blob_->set_cpu_data((float*)mask_color.data);
  frame->lane_detected_blob = lane_blob_;

  // retrieve vanishing point network output
  if (net_outputs_.size() > 1) {
    const auto vpt_blob = cnnadapter_lane_->get_blob(net_outputs_[1]);
    ADEBUG_EVERY(60000) << "vpt_blob: " << vpt_blob->shape_string();
    std::vector<float> v_point(2, 0);
    std::copy(vpt_blob->cpu_data(), vpt_blob->cpu_data() + 2, v_point.begin());
    // compute coordinate in net input image
    v_point[0] = v_point[0] * vpt_std_[0] + vpt_mean_[0] +
                 (static_cast<float>(blob_width) / 2);
    v_point[1] = v_point[1] * vpt_std_[1] + vpt_mean_[1] +
                 (static_cast<float>(blob_height) / 2);
    // compute coordinate in original image
    v_point[0] = v_point[0] / static_cast<float>(blob_width) *
                     static_cast<float>(crop_width_) +
                 static_cast<float>(input_offset_x_);
    v_point[1] = v_point[1] / static_cast<float>(blob_height) *
                     static_cast<float>(crop_height_) +
                 static_cast<float>(input_offset_y_);

    ADEBUG_EVERY(60000) << "vanishing point: " << v_point[0] << " " << v_point[1];
    if (v_point[0] > 0 && v_point[0] < static_cast<float>(input_width_) &&
        v_point[1] > 0 && v_point[0] < static_cast<float>(input_height_)) {
      frame->pred_vpt = v_point;
    }
  }

  auto elapsed_2 = std::chrono::high_resolution_clock::now() - start;
  int64_t microseconds_2 =
      std::chrono::duration_cast<std::chrono::microseconds>(elapsed_2).count();
  time_2 += microseconds_2 - microseconds_1;

  time_num += 1;
  ADEBUG_EVERY(60000) << "Avg detection infer time: " << time_1 / time_num
         << " Avg detection merge output time: " << time_2 / time_num;
  ADEBUG_EVERY(60000) << "Lane detection done!";
  return true;
}

std::string DarkSCNNLaneDetector::Name() const {
  return "DarkSCNNLaneDetector";
}

REGISTER_LANE_DETECTOR(DarkSCNNLaneDetector);

}  // namespace camera
}  // namespace perception
}  // namespace apollo
