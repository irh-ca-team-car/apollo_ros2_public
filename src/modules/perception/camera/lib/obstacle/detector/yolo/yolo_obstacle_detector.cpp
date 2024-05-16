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
#include "modules/perception/camera/lib/obstacle/detector/yolo/yolo_obstacle_detector.h"

#include "cyber/cyber.h"

#include "modules/common/util/perf_util.h"
#include "modules/perception/base/common.h"
#include "modules/perception/camera/common/timer.h"
#include "modules/perception/inference/inference_factory.h"
#include "modules/perception/inference/utils/resize.h"

namespace apollo
{
    namespace perception
    {
        namespace camera
        {

            using cyber::common::GetAbsolutePath;

            void YoloObstacleDetector::LoadInputShape(const yolo::ModelParam &model_param)
            {
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

            void YoloObstacleDetector::LoadParam(const yolo::YoloParam &yolo_param)
            {
                const auto &model_param = yolo_param.modelparam;
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
                auto const &nms_param = yolo_param.nmsparam;
                nms_.sigma = nms_param.sigma;
                nms_.type = nms_param.type;
                nms_.threshold = nms_param.threshold;
                nms_.inter_cls_nms_thresh = nms_param.interclsnmsthresh;
                nms_.inter_cls_conf_thresh = nms_param.interclsconfthresh;
            }

            bool YoloObstacleDetector::InitNet(const yolo::YoloParam &yolo_param,
                                               const std::string &model_root)
            {
                const auto &model_param = yolo_param.modelparam;
                std::string proto_file =
                    GetAbsolutePath(model_root, model_param.protofile);
                std::string weight_file =
                    GetAbsolutePath(model_root, model_param.weightfile);
                std::vector<std::string> input_names;
                std::vector<std::string> output_names;
                auto const &net_param = yolo_param.netparam;
                input_names.push_back(net_param.inputblob);
                output_names.push_back(net_param.det1locblob);
                output_names.push_back(net_param.det1objblob);
                output_names.push_back(net_param.det1clsblob);
                output_names.push_back(net_param.det1oriconfblob);
                output_names.push_back(net_param.det1oriblob);
                output_names.push_back(net_param.det1dimblob);
                output_names.push_back(net_param.det2locblob);
                output_names.push_back(net_param.det2objblob);
                output_names.push_back(net_param.det2clsblob);
                output_names.push_back(net_param.det2oriconfblob);
                output_names.push_back(net_param.det2oriblob);
                output_names.push_back(net_param.det2dimblob);
                output_names.push_back(net_param.det3locblob);
                output_names.push_back(net_param.det3objblob);
                output_names.push_back(net_param.det3clsblob);
                output_names.push_back(net_param.det3oriconfblob);
                output_names.push_back(net_param.det3oriblob);
                output_names.push_back(net_param.det3dimblob);
                output_names.push_back(net_param.lofblob);
                output_names.push_back(net_param.lorblob);
                output_names.push_back(net_param.brvisblob);
                output_names.push_back(net_param.brswtblob);
                output_names.push_back(net_param.ltvisblob);
                output_names.push_back(net_param.ltswtblob);
                output_names.push_back(net_param.rtvisblob);
                output_names.push_back(net_param.rtswtblob);
                output_names.push_back(net_param.featblob);
                output_names.push_back(net_param.areaidblob);
                output_names.push_back(net_param.visibleratioblob);
                output_names.push_back(net_param.cutoffratioblob);
                // init Net
                const auto &model_type = model_param.modeltype;
                AINFO_EVERY(60000) << "model_type=" << model_type;
                inference_.reset(inference::CreateInferenceByName(model_type, proto_file,
                                                                  weight_file, output_names,
                                                                  input_names, model_root));
                if (nullptr == inference_.get())
                {
                    AERROR_EVERY(60000) << "Failed to init CNNAdapter";
                    return false;
                }

                inference_->set_gpu_id(gpu_id_);
                std::vector<int> shape = {1, height_, width_, 3};
                std::map<std::string, std::vector<int>> shape_map{
                    {net_param.inputblob, shape}};

                if (!inference_->Init(shape_map))
                {
                    return false;
                }

                inference_->Infer();

                return true;
            }

            void YoloObstacleDetector::InitYoloBlob(const yolo::NetworkParam &net_param)
            {
                auto obj_blob_scale1 = inference_->get_blob(net_param.det1objblob);
                auto obj_blob_scale2 = inference_->get_blob(net_param.det2objblob);
                auto obj_blob_scale3 = inference_->get_blob(net_param.det3objblob);
                int output_height_scale1 = obj_blob_scale1->shape(1);
                int output_width_scale1 = obj_blob_scale1->shape(2);
                int obj_size = output_height_scale1 * output_width_scale1 *
                               static_cast<int>(anchors_.size()) / anchorSizeFactor;
                if (obj_blob_scale2)
                {
                    int output_height_scale2 = obj_blob_scale2->shape(1);
                    int output_width_scale2 = obj_blob_scale2->shape(2);
                    int output_height_scale3 = obj_blob_scale3->shape(1);
                    int output_width_scale3 = obj_blob_scale3->shape(2);
                    obj_size = (output_height_scale1 * output_width_scale1 +
                                output_height_scale2 * output_width_scale2 +
                                output_height_scale3 * output_width_scale3) *
                               static_cast<int>(anchors_.size()) / anchorSizeFactor / numScales;
                }

                yolo_blobs_.res_box_blob.reset(
                    new base::Blob<float>(1, 1, obj_size, kBoxBlockSize));
                yolo_blobs_.res_cls_blob.reset(new base::Blob<float>(
                    1, 1, static_cast<int>(types_.size() + 1), obj_size));
                yolo_blobs_.res_cls_blob->cpu_data();
                overlapped_.reset(
                    new base::Blob<bool>(std::vector<int>{obj_k_, obj_k_}, true));
                overlapped_->cpu_data();
                overlapped_->gpu_data();
                idx_sm_.reset(new base::Blob<int>(std::vector<int>{obj_k_}, true));
                yolo_blobs_.anchor_blob.reset(
                    new base::Blob<float>(1, 1, static_cast<int>(anchors_.size() / 2), 2));
                yolo_blobs_.expand_blob.reset(
                    new base::Blob<float>(1, 1, 1, static_cast<int>(expands_.size())));
                auto expand_cpu_data = yolo_blobs_.expand_blob->mutable_cpu_data();
                memcpy(expand_cpu_data, expands_.data(), expands_.size() * sizeof(float));
                auto anchor_cpu_data = yolo_blobs_.anchor_blob->mutable_cpu_data();
                memcpy(anchor_cpu_data, anchors_.data(), anchors_.size() * sizeof(float));
                yolo_blobs_.anchor_blob->gpu_data();

                image_.reset(new base::Image8U(height_, width_, base::Color::RGB));

                yolo_blobs_.det1_loc_blob =
                    inference_->get_blob(yolo_param_.netparam.det1locblob);
                yolo_blobs_.det1_obj_blob =
                    inference_->get_blob(yolo_param_.netparam.det1objblob);
                yolo_blobs_.det1_cls_blob =
                    inference_->get_blob(yolo_param_.netparam.det1clsblob);
                yolo_blobs_.det1_ori_conf_blob =
                    inference_->get_blob(yolo_param_.netparam.det1oriconfblob);
                yolo_blobs_.det1_ori_blob =
                    inference_->get_blob(yolo_param_.netparam.det1oriblob);
                yolo_blobs_.det1_dim_blob =
                    inference_->get_blob(yolo_param_.netparam.det1dimblob);
                yolo_blobs_.det2_loc_blob =
                    inference_->get_blob(yolo_param_.netparam.det2locblob);
                yolo_blobs_.det2_obj_blob =
                    inference_->get_blob(yolo_param_.netparam.det2objblob);
                yolo_blobs_.det2_cls_blob =
                    inference_->get_blob(yolo_param_.netparam.det2clsblob);
                yolo_blobs_.det2_ori_conf_blob =
                    inference_->get_blob(yolo_param_.netparam.det2oriconfblob);
                yolo_blobs_.det2_ori_blob =
                    inference_->get_blob(yolo_param_.netparam.det2oriblob);
                yolo_blobs_.det2_dim_blob =
                    inference_->get_blob(yolo_param_.netparam.det2dimblob);
                yolo_blobs_.det3_loc_blob =
                    inference_->get_blob(yolo_param_.netparam.det3locblob);
                yolo_blobs_.det3_obj_blob =
                    inference_->get_blob(yolo_param_.netparam.det3objblob);
                yolo_blobs_.det3_cls_blob =
                    inference_->get_blob(yolo_param_.netparam.det3clsblob);
                yolo_blobs_.det3_ori_conf_blob =
                    inference_->get_blob(yolo_param_.netparam.det3oriconfblob);
                yolo_blobs_.det3_ori_blob =
                    inference_->get_blob(yolo_param_.netparam.det3oriblob);
                yolo_blobs_.det3_dim_blob =
                    inference_->get_blob(yolo_param_.netparam.det3dimblob);

                yolo_blobs_.lof_blob =
                    inference_->get_blob(yolo_param_.netparam.lofblob);
                yolo_blobs_.lor_blob =
                    inference_->get_blob(yolo_param_.netparam.lorblob);

                yolo_blobs_.brvis_blob =
                    inference_->get_blob(yolo_param_.netparam.brvisblob);
                yolo_blobs_.brswt_blob =
                    inference_->get_blob(yolo_param_.netparam.brswtblob);
                yolo_blobs_.ltvis_blob =
                    inference_->get_blob(yolo_param_.netparam.ltvisblob);
                yolo_blobs_.ltswt_blob =
                    inference_->get_blob(yolo_param_.netparam.ltswtblob);
                yolo_blobs_.rtvis_blob =
                    inference_->get_blob(yolo_param_.netparam.rtvisblob);
                yolo_blobs_.rtswt_blob =
                    inference_->get_blob(yolo_param_.netparam.rtswtblob);

                yolo_blobs_.area_id_blob =
                    inference_->get_blob(yolo_param_.netparam.areaidblob);
                yolo_blobs_.visible_ratio_blob =
                    inference_->get_blob(yolo_param_.netparam.visibleratioblob);
                yolo_blobs_.cut_off_ratio_blob =
                    inference_->get_blob(yolo_param_.netparam.cutoffratioblob);
            }

            bool YoloObstacleDetector::Init(const ObstacleDetectorInitOptions &options)
            {
                gpu_id_ = options.gpu_id;
                BASE_CUDA_CHECK(cudaSetDevice(gpu_id_));
                BASE_CUDA_CHECK(cudaStreamCreate(&stream_));

                base_camera_model_ = options.base_camera_model;
                ACHECK(base_camera_model_ != nullptr) << "base_camera_model is nullptr!";
                std::string config_path =
                    GetAbsolutePath(options.root_dir, options.conf_file);
                if (!cyber::common::GetProtoFromASCIIFile(config_path, &yolo_param_))
                {
                    AERROR_EVERY(60000) << "read proto_config fail at" << config_path;
                    return false;
                }
                const auto &model_param = yolo_param_.modelparam;
                std::string model_root =
                    GetAbsolutePath(options.root_dir, model_param.modelname);
                std::string anchors_file =
                    GetAbsolutePath(model_root, model_param.anchorsfile);
                std::string types_file =
                    GetAbsolutePath(model_root, model_param.typesfile);
                std::string expand_file =
                    GetAbsolutePath(model_root, model_param.expandfile);
                LoadInputShape(model_param);
                LoadParam(yolo_param_);
                min_dims_.min_2d_height /= static_cast<float>(height_);
                if (!LoadAnchors(anchors_file, &anchors_))
                {
                    return false;
                }
                if (!LoadTypes(types_file, &types_))
                {
                    return false;
                }
                if (!LoadExpand(expand_file, &expands_))
                {
                    return false;
                }
                ACHECK(expands_.size() == types_.size());
                if (!InitNet(yolo_param_, model_root))
                {
                    return false;
                }
                InitYoloBlob(yolo_param_.netparam);
                if (!InitFeatureExtractor(model_root))
                {
                    return false;
                }
                return true;
            }

            bool YoloObstacleDetector::InitFeatureExtractor(const std::string &root_dir)
            {
                FeatureExtractorInitOptions feat_options;
                feat_options.conf_file = yolo_param_.modelparam.featurefile;
                feat_options.root_dir = root_dir;
                feat_options.gpu_id = gpu_id_;
                auto feat_blob_name = yolo_param_.netparam.featblob;
                feat_options.feat_blob = inference_->get_blob(feat_blob_name);
                feat_options.input_height = height_;
                feat_options.input_width = width_;
                feature_extractor_.reset(BaseFeatureExtractorRegisterer::GetInstanceByName(
                    "TrackingFeatureExtractor"));
                if (!feature_extractor_->Init(feat_options))
                {
                    return false;
                }
                return true;
            }

            bool YoloObstacleDetector::Detect(const ObstacleDetectorOptions &options,
                                              CameraFrame *frame)
            {
                UNUSED(options);
                if (frame == nullptr)
                {
                    return false;
                }

                Timer timer;
                if (cudaSetDevice(gpu_id_) != cudaSuccess)
                {
                    AERROR_EVERY(60000) << "Failed to set device to " << gpu_id_;
                    return false;
                }

                auto input_blob = inference_->get_blob(yolo_param_.netparam.inputblob);
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

                /////////////////////////// detection part ///////////////////////////
                inference_->Infer();
                AINFO_EVERY(60000) << "Network Forward: " << static_cast<double>(timer.Toc()) * 0.001
                      << "ms";
                get_objects_cpu(yolo_blobs_, stream_, types_, nms_, yolo_param_.modelparam,
                                light_vis_conf_threshold_, light_swt_conf_threshold_,
                                overlapped_.get(), idx_sm_.get(), &(frame->detected_objects));

                AINFO_EVERY(60000) << "GetObj: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";
                filter_bbox(min_dims_, &(frame->detected_objects));
                FeatureExtractorOptions feat_options;
                feat_options.normalized = true;
                AINFO_EVERY(60000) << "Post1: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";
                feature_extractor_->Extract(feat_options, frame);
                AINFO_EVERY(60000) << "Extract: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";
                recover_bbox(frame->data_provider->src_width(),
                             frame->data_provider->src_height() - offset_y_, offset_y_,
                             &frame->detected_objects);

                // post processing
                int left_boundary =
                    static_cast<int>(border_ratio_ * static_cast<float>(image_->cols()));
                int right_boundary = static_cast<int>((1.0f - border_ratio_) *
                                                      static_cast<float>(image_->cols()));
                for (auto &obj : frame->detected_objects)
                {
                    // recover alpha
                    obj->camera_supplement.alpha /= ori_cycle_;
                    // get area_id from visible_ratios
                    if (yolo_param_.modelparam.numareas == 0)
                    {
                        obj->camera_supplement.area_id =
                            get_area_id(obj->camera_supplement.visible_ratios);
                    }
                    // clear cut off ratios
                    auto &box = obj->camera_supplement.box;
                    if (box.xmin >= left_boundary)
                    {
                        obj->camera_supplement.cut_off_ratios[2] = 0;
                    }
                    if (box.xmax <= right_boundary)
                    {
                        obj->camera_supplement.cut_off_ratios[3] = 0;
                    }
                }
                AINFO_EVERY(60000) << "Post2: " << static_cast<double>(timer.Toc()) * 0.001 << "ms";

                return true;
            }

            REGISTER_OBSTACLE_DETECTOR(YoloObstacleDetector);

        } // namespace camera
    }     // namespace perception
} // namespace apollo
