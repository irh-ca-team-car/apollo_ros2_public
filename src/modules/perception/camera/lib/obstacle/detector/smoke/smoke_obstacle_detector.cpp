/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
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
#include "modules/perception/camera/lib/obstacle/detector/smoke/smoke_obstacle_detector.h"

#include "cyber/cyber.h"

#include "modules/common/util/perf_util.h"
#include "modules/perception/base/common.h"
#include "modules/perception/camera/common/timer.h"
#include "modules/perception/inference/inference_factory.h"
#include "modules/perception/inference/utils/resize.h"

namespace apollo {
namespace perception {
namespace camera {

using cyber::common::GetAbsolutePath;

void SmokeObstacleDetector::LoadInputShape(
                            const smoke::ModelParam &model_param) {
  float offset_ratio = model_param.offsetratio;
  float cropped_ratio = model_param.croppedratio;
  int resized_width = model_param.resizedwidth;
  int aligned_pixel = model_param.alignedpixel;
  // inference input shape
  int image_height = static_cast<int>(base_camera_model_->get_height());
  int image_width = static_cast<int>(base_camera_model_->get_width());

  offset_y_ =
      static_cast<int>(offset_ratio * static_cast<float>(image_height) + .5f);
  float roi_ratio = cropped_ratio * static_cast<float>(image_height) /
                    static_cast<float>(image_width);
  width_ = static_cast<int>(resized_width + aligned_pixel / 2) / aligned_pixel *
           aligned_pixel;
  height_ = static_cast<int>(static_cast<float>(width_) * roi_ratio +
                             static_cast<float>(aligned_pixel) / 2.0f) /
            aligned_pixel * aligned_pixel;

  AINFO_EVERY(60000) << "image_height=" << image_height << ", "
        << "image_width=" << image_width << ", "
        << "roi_ratio=" << roi_ratio;
  AINFO_EVERY(60000) << "offset_y=" << offset_y_ << ", height=" << height_
        << ", width=" << width_;
}

void SmokeObstacleDetector::LoadParam(const smoke::SmokeParam &smoke_param) {
  const auto &model_param = smoke_param.modelparam;
  confidence_threshold_ = model_param.confidencethreshold;
  light_vis_conf_threshold_ = model_param.lightvisconfthreshold;
  light_swt_conf_threshold_ = model_param.lightswtconfthreshold;
  min_dims_.min_2d_height = model_param.min2dheight;
  min_dims_.min_3d_height = model_param.min3dheight;
  min_dims_.min_3d_width = model_param.min3dwidth;
  min_dims_.min_3d_length = model_param.min3dlength;
  ori_cycle_ = model_param.oricycle;

  border_ratio_ = model_param.borderratio;

  // init NMS
  auto const &nms_param = smoke_param.nmsparam;
  nms_.sigma = nms_param.sigma;
  nms_.type = nms_param.type;
  nms_.threshold = nms_param.threshold;
  nms_.inter_cls_nms_thresh = nms_param.interclsnmsthresh;
  nms_.inter_cls_conf_thresh = nms_param.interclsconfthresh;
}

bool SmokeObstacleDetector::InitNet(const smoke::SmokeParam &smoke_param,
                                   const std::string &model_root) {
  const auto &model_param = smoke_param.modelparam;

  std::string proto_file =
      GetAbsolutePath(model_root, model_param.protofile);
  std::string weight_file =
      GetAbsolutePath(model_root, model_param.weightfile);
  std::vector<std::string> input_names;
  std::vector<std::string> output_names;
  // init Net
  auto const &net_param = smoke_param.netparam;
  input_names.push_back(net_param.inputdatablob);
  input_names.push_back(net_param.inputratioblob);
  input_names.push_back(net_param.inputinstricblob);
  output_names.push_back(net_param.det1locblob);
  output_names.push_back(net_param.featblob);

  // init Net
  const auto &model_type = model_param.modeltype;
  AINFO_EVERY(60000) << "model_type=" << model_type;
  inference_.reset(inference::CreateInferenceByName(model_type, proto_file,
                                                    weight_file, output_names,
                                                    input_names, model_root));
  if (nullptr == inference_.get()) {
    AERROR_EVERY(60000) << "Failed to init CNNAdapter";
    return false;
  }
  inference_->set_gpu_id(gpu_id_);
  std::vector<int> shape_input = {1, height_, width_, 3};
  std::vector<int> shape_param = {1, 3, 3};
  std::vector<int> shape_ratio = {1, 2};
  std::vector<int> shape_res = {1, 1, 50, 14};
  std::vector<int> shape_feat = {1, 64, 160, 240};
  std::map<std::string, std::vector<int>> shape_map;
  shape_map.emplace(
      (std::pair<std::string, std::vector<int>>(input_names[0], shape_input)));
  shape_map.emplace(
      (std::pair<std::string, std::vector<int>>(input_names[1], shape_param)));
  shape_map.emplace(
      (std::pair<std::string, std::vector<int>>(input_names[2], shape_ratio)));
  shape_map.emplace(
      (std::pair<std::string, std::vector<int>>(output_names[0], shape_res)));
  shape_map.emplace(
      (std::pair<std::string, std::vector<int>>(output_names[1], shape_feat)));
  if (!inference_->Init(shape_map)) {
    return false;
  }
  // inference_->Infer();
  return true;
}

void SmokeObstacleDetector::InitSmokeBlob(
                            const smoke::NetworkParam &net_param) {
  auto obj_blob_scale1 = inference_->get_blob(net_param.det1objblob);
  overlapped_.reset(
      new base::Blob<bool>(std::vector<int>{obj_k_, obj_k_}, true));
  overlapped_->cpu_data();
  overlapped_->gpu_data();
  idx_sm_.reset(new base::Blob<int>(std::vector<int>{obj_k_}, true));
  image_.reset(new base::Image8U(height_, width_, base::Color::RGB));

  smoke_blobs_.det1_loc_blob =
      inference_->get_blob(smoke_param_.netparam.det1locblob);
}

bool SmokeObstacleDetector::Init(const ObstacleDetectorInitOptions &options) {
  gpu_id_ = options.gpu_id;
  BASE_CUDA_CHECK(cudaSetDevice(gpu_id_));
  BASE_CUDA_CHECK(cudaStreamCreate(&stream_));

  base_camera_model_ = options.base_camera_model;
  ACHECK(base_camera_model_ != nullptr) << "base_camera_model is nullptr!";
  std::string config_path =
      GetAbsolutePath(options.root_dir, options.conf_file);
  if (!cyber::common::GetProtoFromASCIIFile(config_path, &smoke_param_)) {
    AERROR_EVERY(60000) << "read proto_config fail";
    return false;
  }
  const auto &model_param = smoke_param_.modelparam;
  std::string model_root =
      GetAbsolutePath(options.root_dir, model_param.modelname);
  std::string anchors_file =
      GetAbsolutePath(model_root, model_param.anchorsfile);
  std::string types_file =
      GetAbsolutePath(model_root, model_param.typesfile);
  std::string expand_file =
      GetAbsolutePath(model_root, model_param.expandfile);
  LoadInputShape(model_param);
  LoadParam(smoke_param_);
  min_dims_.min_2d_height /= static_cast<float>(height_);

  if (!LoadAnchors(anchors_file, &anchors_)) {
    return false;
  }
  if (!LoadTypes(types_file, &types_)) {
    return false;
  }
  if (!LoadExpand(expand_file, &expands_)) {
    return false;
  }
  ACHECK(expands_.size() == types_.size());
  if (!InitNet(smoke_param_, model_root)) {
    return false;
  }
  InitSmokeBlob(smoke_param_.netparam);
  if (!InitFeatureExtractor(model_root)) {
    return false;
  }
  return true;
}

bool SmokeObstacleDetector::InitFeatureExtractor(const std::string &root_dir) {
  FeatureExtractorInitOptions feature_options;
  feature_options.conf_file = smoke_param_.modelparam.featurefile;
  feature_options.root_dir = root_dir;
  feature_options.gpu_id = gpu_id_;
  auto feat_blob_name = smoke_param_.netparam.featblob;
  feature_options.feat_blob = inference_->get_blob(feat_blob_name);
  feature_options.input_height = height_;
  feature_options.input_width = width_;
  feature_extractor_.reset(BaseFeatureExtractorRegisterer::GetInstanceByName(
      "TrackingFeatureExtractor"));
  if (!feature_extractor_->Init(feature_options)) {
    return false;
  }
  return true;
}

bool SmokeObstacleDetector::Detect(const ObstacleDetectorOptions &options,
                                  CameraFrame *frame) {
  UNUSED(options);
  if (frame == nullptr)
  {
    return false;
  }

  Timer timer;
  if (cudaSetDevice(gpu_id_) != cudaSuccess) {
    AERROR_EVERY(60000) << "Failed to set device to " << gpu_id_;
    return false;
  }
  const auto &camera_k_matrix = frame->camera_k_matrix.inverse();
  auto const &net_param = smoke_param_.netparam;
  auto input_blob = inference_->get_blob(net_param.inputdatablob);
  auto input_K_blob = inference_->get_blob(net_param.inputratioblob);
  auto input_ratio_blob = inference_->get_blob(net_param.inputinstricblob);

  float* ratio_data = input_ratio_blob->mutable_cpu_data();
  float* K_data = input_K_blob->mutable_cpu_data();
  for (size_t i = 0; i < 3; i++) {
    size_t i3 = i * 3;
    for (size_t j = 0; j < 3; j++) {
      if (frame->data_provider->sensor_name() == "front_12mm") {
        K_data[i3 + j] = camera_k_matrix(i, j) * 2.f;
      } else {
        K_data[i3 + j] = camera_k_matrix(i, j);
      }
    }
  }
  AINFO_EVERY(60000) << "Camera k matrix input to obstacle postprocessor: \n"
        << K_data[0] << ", " << K_data[1] << ", " << K_data[2] << "\n"
        << K_data[3] << ", " << K_data[4] << ", " << K_data[5] << "\n"
        << K_data[6] << ", " << K_data[7] << ", " << K_data[8] << "\n";
  ratio_data[0] = 4.f * static_cast<float>(frame->data_provider->src_width())
                  / static_cast<float>(width_);
  ratio_data[1] = 4.f * static_cast<float>(frame->data_provider->src_height())
                  / static_cast<float>(height_);

  AINFO_EVERY(60000) << "Start: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";
  DataProvider::ImageOptions image_options;
  image_options.target_color = base::Color::BGR;
  image_options.crop_roi = base::RectI(
      0, offset_y_, static_cast<int>(base_camera_model_->get_width()),
      static_cast<int>(base_camera_model_->get_height()) - offset_y_);
  image_options.do_crop = true;
  frame->data_provider->GetImage(image_options, image_.get());
  AINFO_EVERY(60000) << "GetImageBlob: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";
  inference::ResizeGPU(*image_, input_blob, frame->data_provider->src_width(),
                       0);
  AINFO_EVERY(60000) << "Resize: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";

  AINFO_EVERY(60000) << "Camera type: " << frame->data_provider->sensor_name();
  /////////////////////////// detection part ///////////////////////////
  inference_->Infer();
  AINFO_EVERY(60000) << "Network Forward: " << static_cast<double>(timer.Toc()) * 0.001
        << "ms";
  get_smoke_objects_cpu(smoke_blobs_, types_, smoke_param_.modelparam,
                  light_vis_conf_threshold_, light_swt_conf_threshold_,
                  overlapped_.get(), idx_sm_.get(), &(frame->detected_objects),
                  frame->data_provider->src_width(),
                  frame->data_provider->src_height() - offset_y_);

  AINFO_EVERY(60000) << "GetObj: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";
  filter_bbox(min_dims_, &(frame->detected_objects));
  FeatureExtractorOptions feature_options;
  feature_options.normalized = true;
  AINFO_EVERY(60000) << "Post1: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";
  feature_extractor_->Extract(feature_options, frame);
  AINFO_EVERY(60000) << "Extract: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";
  recover_smoke_bbox(frame->data_provider->src_width(),
               frame->data_provider->src_height() - offset_y_, offset_y_,
               &frame->detected_objects);

  // post processing
  int left_boundary =
      static_cast<int>(border_ratio_ * static_cast<float>(image_->cols()));
  int right_boundary = static_cast<int>((1.0f - border_ratio_) *
                                        static_cast<float>(image_->cols()));
  for (auto &obj : frame->detected_objects) {
    // recover alpha
    obj->camera_supplement.alpha /= ori_cycle_;
    // get area_id from visible_ratios
    if (smoke_param_.modelparam.numareas == 0) {
      obj->camera_supplement.area_id =
          get_area_id(obj->camera_supplement.visible_ratios);
    }
    // clear cut off ratios
    auto &box = obj->camera_supplement.box;
    if (box.xmin >= left_boundary) {
      obj->camera_supplement.cut_off_ratios[2] = 0;
    }
    if (box.xmax <= right_boundary) {
      obj->camera_supplement.cut_off_ratios[3] = 0;
    }
  }
  AINFO_EVERY(60000) << "Post2: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";

  return true;
}

REGISTER_OBSTACLE_DETECTOR(SmokeObstacleDetector);

}  // namespace camera
}  // namespace perception
}  // namespace apollo
