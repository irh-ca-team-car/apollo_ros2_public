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
#include "component/lane_detection.h"
#include "modules/perception/factories.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <tuple>

#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

#ifdef NVVC
#define __CUDACC__ NVVC
#endif
#include "Eigen/Core"
#include "Eigen/Dense"
#include "absl/strings/str_cat.h"
#include "yaml-cpp/yaml.h"

#include "cyber/cyber.h"
#include "modules/common/util/util.h"
#include "modules/common/math/math_utils.h"
#include "modules/common/util/string_util.h"
#include "modules/perception/common/perception_gflags.h"
#include "modules/perception/common/sensor_manager/sensor_manager.h"
#include "modules/perception/onboard/common_flags/common_flags.h"
#include "modules/perception/onboard/component/camera_perception_viz_message.h"

#include "modules/localization/proto/localization.pb.h"

namespace apollo
{
  namespace perception
  {
    namespace onboard
    {
      using apollo::cyber::common::GetAbsolutePath;
      using apollo::localization::LocalizationEstimate;

      FunInfoType LaneDetectionComponent::init_func_arry_[] = {
          {&LaneDetectionComponent::InitSensorInfo, "InitSensorInfo"},
          {&LaneDetectionComponent::InitAlgorithmPlugin, "InitAlgorithmPlugin"},
          {&LaneDetectionComponent::InitCameraFrames, "InitCameraFrames"},
          {&LaneDetectionComponent::InitProjectMatrix, "InitProjectMatrix"},
          {&LaneDetectionComponent::InitMotionService, "InitMotionService"},
          {&LaneDetectionComponent::InitCameraListeners, "InitCameraListeners"}};

      std::optional<int> gpuId;
      static int GetGpuId(const camera::CameraPerceptionInitOptions &options)
      {
        UNUSED(options);
      
        camera::app::PerceptionParam perception_param;
        auto currentNode = apollo::cyber::currentNode;
        if(!gpuId)
        {
          gpuId = std::make_optional(currentNode->declare_parameter<int>("gpu_id", -1));
        }
        perception_param.gpuid = *gpuId;

        if (perception_param.gpuid == -1)
        {
          AINFO << "gpu id not found.";
          return -1;
        }
        return perception_param.gpuid;
      }

      static bool SetCameraHeight(const std::string &sensor_name,
                                  const std::string &params_dir,
                                  float default_camera_height, float *camera_height)
      {
        float base_h = default_camera_height;
        float camera_offset = 0.0f;
        try
        {
          YAML::Node lidar_height =
              YAML::LoadFile(params_dir + "/" + "velodyne128_height.yaml");
          base_h = lidar_height["vehicle"]["parameters"]["height"].as<float>();
          AINFO << base_h;
          YAML::Node camera_ex =
              YAML::LoadFile(params_dir + "/" + sensor_name + "_extrinsics.yaml");
          camera_offset = camera_ex["transform"]["translation"]["z"].as<float>();
          AINFO << camera_offset;
          *camera_height = base_h + camera_offset;
        }
        catch (YAML::InvalidNode &in)
        {
          AERROR << "load camera extrisic file error, YAML::InvalidNode exception";
          return false;
        }
        catch (YAML::TypedBadConversion<float> &bc)
        {
          AERROR << "load camera extrisic file error, "
                 << "YAML::TypedBadConversion exception";
          return false;
        }
        catch (YAML::Exception &e)
        {
          AERROR << "load camera extrisic file "
                 << " error, YAML exception:" << e.what();
          return false;
        }
        return true;
      }

      // @description: load camera extrinsics from yaml file
      static bool LoadExtrinsics(const std::string &yaml_file,
                                 Eigen::Matrix4d *camera_extrinsic)
      {
        if (!apollo::cyber::common::PathExists(yaml_file))
        {
          AINFO << yaml_file << " not exist!";
          return false;
        }
        YAML::Node node = YAML::LoadFile(yaml_file);
        double qw = 0.0;
        double qx = 0.0;
        double qy = 0.0;
        double qz = 0.0;
        double tx = 0.0;
        double ty = 0.0;
        double tz = 0.0;
        try
        {
          if (node.IsNull())
          {
            AINFO << "Load " << yaml_file << " failed! please check!";
            return false;
          }
          qw = node["transform"]["rotation"]["w"].as<double>();
          qx = node["transform"]["rotation"]["x"].as<double>();
          qy = node["transform"]["rotation"]["y"].as<double>();
          qz = node["transform"]["rotation"]["z"].as<double>();
          tx = node["transform"]["translation"]["x"].as<double>();
          ty = node["transform"]["translation"]["y"].as<double>();
          tz = node["transform"]["translation"]["z"].as<double>();
        }
        catch (YAML::InvalidNode &in)
        {
          AERROR << "load camera extrisic file " << yaml_file
                 << " with error, YAML::InvalidNode exception";
          return false;
        }
        catch (YAML::TypedBadConversion<double> &bc)
        {
          AERROR << "load camera extrisic file " << yaml_file
                 << " with error, YAML::TypedBadConversion exception";
          return false;
        }
        catch (YAML::Exception &e)
        {
          AERROR << "load camera extrisic file " << yaml_file
                 << " with error, YAML exception:" << e.what();
          return false;
        }
        camera_extrinsic->setConstant(0);
        Eigen::Quaterniond q;
        q.x() = qx;
        q.y() = qy;
        q.z() = qz;
        q.w() = qw;
        (*camera_extrinsic).block<3, 3>(0, 0) = q.normalized().toRotationMatrix();
        (*camera_extrinsic)(0, 3) = tx;
        (*camera_extrinsic)(1, 3) = ty;
        (*camera_extrinsic)(2, 3) = tz;
        (*camera_extrinsic)(3, 3) = 1;
        return true;
      }

      // @description: get project matrix
      static bool GetProjectMatrix(
          const std::vector<std::string> &camera_names,
          const EigenMap<std::string, Eigen::Matrix4d> &extrinsic_map,
          const EigenMap<std::string, Eigen::Matrix3f> &intrinsic_map,
          Eigen::Matrix3d *project_matrix, double *pitch_diff = nullptr)
      {
        if (camera_names.size() != 2)
        {
          AINFO << "camera number must be 2!";
          return false;
        }
        *project_matrix =
            intrinsic_map.at(camera_names[0]).cast<double>() *
            extrinsic_map.at(camera_names[0]).block<3, 3>(0, 0).inverse() *
            extrinsic_map.at(camera_names[1]).block<3, 3>(0, 0) *
            intrinsic_map.at(camera_names[1]).cast<double>().inverse();
        // extract the pitch_diff = pitch_narrow - pitch_obstacle
        if (pitch_diff != nullptr)
        {
          Eigen::Vector3d euler =
              (extrinsic_map.at(camera_names[0]).block<3, 3>(0, 0).inverse() *
               extrinsic_map.at(camera_names[1]).block<3, 3>(0, 0))
                  .eulerAngles(0, 1, 2);
          *pitch_diff = euler(0);
          AINFO << "pitch diff: " << *pitch_diff;
        }
        return true;
      }

      LaneDetectionComponent::~LaneDetectionComponent() {}

      bool LaneDetectionComponent::Init()
      {
        InitFactories();

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

        // sensor_manager
        INIT_FLAG_string(obs_sensor_intrinsic_path,
                         "data/perception/params",
                         "The intrinsics/extrinsics dir.");

        INIT_FLAG_string(obs_sensor_meta_path,
                         "data/perception/production"
                         "/data/perception/common/sensor_meta.pt",
                         "The SensorManager config file.");

        INIT_FLAG_bool(enable_base_object_pool, false, "Enable base object pool.");

        // config_manager
        INIT_FLAG_string(config_manager_path, "./conf", "The ModelConfig config paths.");
        INIT_FLAG_string(work_root, "", "Project work root direcotry.");

        // lidar_point_pillars
        INIT_FLAG_int32(gpu_id, 0, "The id of gpu used for inference.");
        INIT_FLAG_string(pfe_torch_file,
                         "data/perception/production/data/perception/lidar/"
                         "models/detection/point_pillars/pts_voxel_encoder.zip",
                         "The path of pillars feature extractor torch file.");
        INIT_FLAG_string(scattered_torch_file,
                         "data/perception/production/data/perception/lidar/"
                         "models/detection/point_pillars/pts_middle_encoder.zip",
                         "The path of pillars feature scatter torch file.");
        INIT_FLAG_string(backbone_torch_file,
                         "data/perception/production/data/perception/lidar/"
                         "models/detection/point_pillars/pts_backbone.zip",
                         "The path of pillars backbone torch file.");
        INIT_FLAG_string(fpn_torch_file,
                         "data/perception/production/data/perception/lidar/"
                         "models/detection/point_pillars/pts_neck.zip",
                         "The path of pillars fpn torch file.");
        INIT_FLAG_string(bbox_head_torch_file,
                         "data/perception/production/data/perception/lidar/"
                         "models/detection/point_pillars/pts_bbox_head.zip",
                         "The path of pillars bbox head torch file.");
        INIT_FLAG_double(normalizing_factor, 255,
                         "Normalize intensity range to [0, 1] by this factor.");
        INIT_FLAG_int32(num_point_feature, 5,
                        "Length of raw point feature. Features include x, y, z,"
                        "intensity and delta of time.");
        INIT_FLAG_bool(enable_ground_removal, false, "Enable ground removal.");
        INIT_FLAG_double(ground_removal_height, -1.5, "Height for ground removal.");
        INIT_FLAG_bool(enable_downsample_beams, false,
                       "Enable down sampling point cloud beams with a factor.");
        INIT_FLAG_int32(downsample_beams_factor, 4,
                        "Down sample point cloud beams with this factor.");
        INIT_FLAG_bool(enable_downsample_pointcloud, false,
                       "Enable down sampling point cloud into centroids of voxel grid.");
        INIT_FLAG_double(downsample_voxel_size_x, 0.01,
                         "X-axis size of voxels used for down sampling point cloud.");
        INIT_FLAG_double(downsample_voxel_size_y, 0.01,
                         "Y-axis size of voxels used for down sampling point cloud.");
        INIT_FLAG_double(downsample_voxel_size_z, 0.01,
                         "Z-axis size of voxels used for down sampling point cloud.");
        INIT_FLAG_bool(enable_fuse_frames, false,
                       "Enable fusing preceding frames' point cloud into current frame.");
        INIT_FLAG_int32(num_fuse_frames, 5,
                        "Number of frames to fuse, including current frame.");
        INIT_FLAG_double(fuse_time_interval, 0.5,
                         "Time interval in seconds of frames to fuse.");
        INIT_FLAG_bool(enable_shuffle_points, false,
                       "Enable shuffling points before preprocessing.");
        INIT_FLAG_int32(max_num_points, std::numeric_limits<int>::max(),
                        "Max number of points to preprocess.");
        INIT_FLAG_bool(reproduce_result_mode, false, "True if preprocess in CPU mode.");
        INIT_FLAG_double(score_threshold, 0.5, "Classification score threshold.");
        INIT_FLAG_double(nms_overlap_threshold, 0.5, "Nms overlap threshold.");
        INIT_FLAG_int32(num_output_box_feature, 7, "Length of output box feature.");

        // emergency detection onnx
        INIT_FLAG_string(onnx_obstacle_detector_model,
                         "data/perception/camera"
                         "/lib/obstacle/detector/yolov4/model/yolov4_1_3_416_416.onnx",
                         "The onnx model file for emergency detection");
        INIT_FLAG_string(onnx_test_input_path,
                         "data/perception/inference"
                         "/onnx/testdata/dog.jpg",
                         "The test input image file for onnx inference");
        INIT_FLAG_string(onnx_test_input_name_file,
                         "data/perception/inference"
                         "/onnx/testdata/coco.names",
                         "The test input coco name file for onnx inference");
        INIT_FLAG_string(onnx_prediction_image_path,
                         "data/perception/inference"
                         "/onnx/testdata/prediction.jpg",
                         "The prediction output image file for onnx inference");
        INIT_FLAG_int32(num_classes, 80, "number of classes for onnx inference");

        // emergency detection libtorch
        INIT_FLAG_string(torch_detector_model,
                         "data/perception/camera"
                         "/lib/obstacle/detector/yolov4/model/yolov4.pt",
                         "The torch model file for emergency detection");

        
        if (InitConfig() != cyber::SUCC)
        {
          AERROR << "InitConfig() failed.";
          return false;
        }

        
        writer_ = node_->CreateWriter<PerceptionLanes>(output_lanes_channel_name_);
        if (!EXEC_ALL_FUNS(LaneDetectionComponent, this,
                           LaneDetectionComponent::init_func_arry_))
        {
          return false;
        }
        
        SetCameraHeightAndPitch();

        // Init visualizer
        // TODO(techoe, yg13): homography from image to ground should be
        // computed from camera height and pitch.
        // Apply online calibration to adjust pitch/height automatically
        // Temporary code is used here for testing
        
        // load in lidar to imu extrinsic
        Eigen::Matrix4d ex_lidar2imu;
        
        LoadExtrinsics(FLAGS_obs_sensor_intrinsic_path + "/" +
                           "velodyne128_novatel_extrinsics.yaml",
                       &ex_lidar2imu);
        AINFO << "velodyne128_novatel_extrinsics: " << ex_lidar2imu;

        homography_image2ground_ = visualize_.homography_im2car(visual_camera_);
        camera_lane_pipeline_->SetIm2CarHomography(homography_image2ground_);

        AINFO << "Init processes all succeed";
        return true;
      }

      // On receiving motion service input, convert it to motion_buff_
      void LaneDetectionComponent::OnMotionService(
          const MotionServiceMsgType &message)
      {
        if(message->vehiclestatus.size() ==0) return;
        // Comment: use the circular buff to do it smartly, only push the latest
        // circular_buff only saves only the incremental motion between frames.
        // motion_service is now hard-coded for camera front 6mm
        base::VehicleStatus vehicledata;
        vehicledata.roll_rate = message->vehiclestatus[0].rollrate;
        vehicledata.pitch_rate = message->vehiclestatus[0].pitchrate;
        vehicledata.yaw_rate = message->vehiclestatus[0].yawrate;
        vehicledata.velocity = message->vehiclestatus[0].velocity;
        vehicledata.velocity_x = message->vehiclestatus[0].velocityx;
        vehicledata.velocity_y = message->vehiclestatus[0].velocityy;
        vehicledata.velocity_z = message->vehiclestatus[0].velocityz;
        vehicledata.time_ts = message->vehiclestatus[0].timets;
        vehicledata.time_d = message->vehiclestatus[0].timed;

        base::MotionType motion_2d = base::MotionType::Identity();
        motion_2d(0, 0) = message->vehiclestatus[0].motion.m00;
        motion_2d(0, 1) = message->vehiclestatus[0].motion.m01;
        motion_2d(0, 2) = message->vehiclestatus[0].motion.m02;
        motion_2d(0, 3) = message->vehiclestatus[0].motion.m03;
        motion_2d(1, 0) = message->vehiclestatus[0].motion.m10;
        motion_2d(1, 1) = message->vehiclestatus[0].motion.m11;
        motion_2d(1, 2) = message->vehiclestatus[0].motion.m12;
        motion_2d(1, 3) = message->vehiclestatus[0].motion.m13;
        motion_2d(2, 0) = message->vehiclestatus[0].motion.m20;
        motion_2d(2, 1) = message->vehiclestatus[0].motion.m21;
        motion_2d(2, 2) = message->vehiclestatus[0].motion.m22;
        motion_2d(2, 3) = message->vehiclestatus[0].motion.m23;
        motion_2d(3, 0) = message->vehiclestatus[0].motion.m30;
        motion_2d(3, 1) = message->vehiclestatus[0].motion.m31;
        motion_2d(3, 2) = message->vehiclestatus[0].motion.m32;
        motion_2d(3, 3) = message->vehiclestatus[0].motion.m33;
        vehicledata.motion = motion_2d;

        mot_buffer_->push_back(vehicledata);

        // TODO(@yg13): output motion in text file
      }

      void LaneDetectionComponent::OnReceiveImage(
          const std::shared_ptr<apollo::drivers::Image> &message,
          const std::string &camera_name)
      {
        const double msg_timestamp = message->measurementtime + timestamp_offset_;
        AINFO_EVERY(60000) << "Enter LaneDetectionComponent::Proc(), camera_name: " << camera_name
              << " image ts: " << msg_timestamp;
        // timestamp should be almost monotonic
        if (last_timestamp_ - msg_timestamp > ts_diff_)
        {
          AINFO_EVERY(60000) << "Received an old message. Last ts is " << std::setprecision(19)
                << last_timestamp_ << " current ts is " << msg_timestamp
                << " last - current is " << last_timestamp_ - msg_timestamp;
          return;
        }
        last_timestamp_ = msg_timestamp;
        ++seq_num_;

        // for e2e lantency statistics
        {
          const double cur_time = apollo::cyber::Clock::NowInSeconds();
          const double start_latency = (cur_time - message->measurementtime) * 1e3;
          AINFO_EVERY(60000) << "FRAME_STATISTICS:Camera:Start:msg_time[" << camera_name << "-"
                << FORMAT_TIMESTAMP(message->measurementtime) << "]:cur_time["
                << FORMAT_TIMESTAMP(cur_time) << "]:cur_latency[" << start_latency
                << "]";
        }

        // protobuf msg
        std::shared_ptr<apollo::perception::PerceptionLanes> out_message(
            new (std::nothrow) apollo::perception::PerceptionLanes);
        apollo::common::ErrorCode error_code = apollo::common::OK;

        // prefused msg
        std::shared_ptr<SensorFrameMessage> prefused_message(new (std::nothrow)
                                                                 SensorFrameMessage);
        if (InternalProc(message, camera_name, &error_code, prefused_message.get(),
                         out_message.get()) != cyber::SUCC)
        {
          AERROR << "InternalProc failed, error_code: " << error_code;
          return;
        }

        // for e2e lantency statistics
        {
          const double end_timestamp = apollo::cyber::Clock::NowInSeconds();
          const double end_latency =
              (end_timestamp - message->measurementtime) * 1e3;
          AINFO_EVERY(60000) << "FRAME_STATISTICS:Camera:End:msg_time[" << camera_name << "-"
                << FORMAT_TIMESTAMP(message->measurementtime) << "]:cur_time["
                << FORMAT_TIMESTAMP(end_timestamp) << "]:cur_latency[" << end_latency
                << "]";
        }
      }

      int LaneDetectionComponent::InitConfig()
      {
        // the macro READ_CONF would return cyber::FAIL if config not exists
        apollo::perception::onboard::LaneDetection lane_detection_param;
        
        
        lane_detection_param.cameranames = declare_parameter<std::string>("camera_names", "front_6mm,front_12mm");
        
        lane_detection_param.inputcamerachannelnames = declare_parameter<std::string>("input_camera_channel_names", "/apollo/sensor/camera/front_6mm/image,/apollo/sensor/camera/front_12mm/image");
        
        lane_detection_param.timestampoffset = declare_parameter<float>("timestamp_offset", 0.0);
        
        lane_detection_param.cameralaneperceptionconfdir = declare_parameter<std::string>("camera_lane_perception_conf_dir", "data/perception/production/conf/perception/camera");
        
        apollo::cyber::ComponentBase::instance()->replaceRoot(lane_detection_param.cameralaneperceptionconfdir);
        
        lane_detection_param.cameralaneperceptionconffile = declare_parameter<std::string>("camera_lane_perception_conf_file", "lane.pt");
        
        lane_detection_param.framecapacity = declare_parameter<int>("frame_capacity", 20);
        
        lane_detection_param.imagechannelnum = declare_parameter<int>("image_channel_num", 3);
        
        lane_detection_param.enableundistortion = declare_parameter<bool>("enable_undistortion", false);
        
        lane_detection_param.enablevisualization = declare_parameter<bool>("enable_visualization", false);
        
        lane_detection_param.outputlaneschannelname = declare_parameter<std::string>("output_lanes_channel_name", "/apollo/perception/lanes");
        
        lane_detection_param.defaultcamerapitch = declare_parameter<float>("default_camera_pitch", 0.0);
        
        lane_detection_param.defaultcameraheight = declare_parameter<float>("default_camera_height", 1.5);
        
        lane_detection_param.lanecalibrationworkingsensorname = declare_parameter<std::string>("lane_calibration_working_sensor_name", "front_6mm");
        
        lane_detection_param.calibratormethod = declare_parameter<std::string>("calibrator_method", "LaneLineCalibrator");
        
        lane_detection_param.calibservicename = declare_parameter<std::string>("calib_service_name", "OnlineCalibrationService");
        
        lane_detection_param.runcalibservice = declare_parameter<bool>("run_calib_service", true);
        
        lane_detection_param.tsdiff = declare_parameter<float>("ts_diff", 0.1);
        
        lane_detection_param.visualdebugfolder = declare_parameter<std::string>("visual_debug_folder", "/mnt/sd/log");
        
        lane_detection_param.visualcamera = declare_parameter<std::string>("visual_camera", "front_6mm");
        
        lane_detection_param.writevisualimg = declare_parameter<bool>("write_visual_img", false);

        
        std::string camera_names_str = lane_detection_param.cameranames;
        boost::algorithm::split(camera_names_, camera_names_str,
                                boost::algorithm::is_any_of(","));
        if (camera_names_.size() != 2)
        {
          AERROR << "Now LaneDetectionComponent only support 1 cameras";
          return cyber::FAIL;
        }

        std::string input_camera_channel_names_str =
            lane_detection_param.inputcamerachannelnames;
        boost::algorithm::split(input_camera_channel_names_,
                                input_camera_channel_names_str,
                                boost::algorithm::is_any_of(","));
        if (input_camera_channel_names_.size() != camera_names_.size())
        {
          AERROR << "wrong input_camera_channel_names_.size(): "
                 << input_camera_channel_names_.size();
          return cyber::FAIL;
        }

        camera_perception_init_options_.root_dir =
            lane_detection_param.cameralaneperceptionconfdir;
        camera_perception_init_options_.conf_file =
            lane_detection_param.cameralaneperceptionconffile;
        camera_perception_init_options_.lane_calibration_working_sensor_name =
            lane_detection_param.lanecalibrationworkingsensorname;
        camera_perception_init_options_.use_cyber_work_root = true;
        frame_capacity_ = lane_detection_param.framecapacity;
        image_channel_num_ = lane_detection_param.imagechannelnum;
        enable_undistortion_ = lane_detection_param.enableundistortion;
        enable_visualization_ = lane_detection_param.enablevisualization;
        visual_debug_folder_ = lane_detection_param.visualdebugfolder;
        visual_camera_ = lane_detection_param.visualcamera;
        output_lanes_channel_name_ = lane_detection_param.outputlaneschannelname;
        default_camera_pitch_ =
            static_cast<float>(lane_detection_param.defaultcamerapitch);
        default_camera_height_ =
            static_cast<float>(lane_detection_param.defaultcameraheight);
        ts_diff_ = lane_detection_param.tsdiff;
        write_visual_img_ = lane_detection_param.writevisualimg;

        std::string format_str = R"(
      LaneDetectionComponent InitConfig success
      camera_names:    %s, %s
      camera_lane_perception_conf_dir:    %s
      camera_lane_perception_conf_file:    %s
      frame_capacity:    %d
      image_channel_num:    %d
      enable_undistortion:    %d
      enable_visualization:    %d
      visual_debug_folder_:     %s
      visual_camera_:     %s
      output_lanes_channel_name:    %s
      write_visual_img_:    %s)";
        std::string config_info_str =
            str(boost::format(format_str.c_str()) % camera_names_[0] %
                camera_names_[1] % camera_perception_init_options_.root_dir %
                camera_perception_init_options_.conf_file % frame_capacity_ %
                image_channel_num_ % enable_undistortion_ % enable_visualization_ %
                visual_debug_folder_ % visual_camera_ % output_lanes_channel_name_ %
                write_visual_img_);
        AINFO << config_info_str;

        return cyber::SUCC;
      }

      int LaneDetectionComponent::InitSensorInfo()
      {
        if (camera_names_.size() != 2)
        {
          AERROR << "invalid camera_names_.size(): " << camera_names_.size();
          return cyber::FAIL;
        }

        auto *sensor_manager = common::SensorManager::Instance();
        for (size_t i = 0; i < camera_names_.size(); ++i)
        {
          if (!sensor_manager->IsSensorExist(camera_names_[i]))
          {
            AERROR << ("sensor_name: " + camera_names_[i] + " not exists.");
            return cyber::FAIL;
          }

          base::SensorInfo sensor_info;
          if (!(sensor_manager->GetSensorInfo(camera_names_[i], &sensor_info)))
          {
            AERROR << "Failed to get sensor info, sensor name: " << camera_names_[i];
            return cyber::FAIL;
          }
          sensor_info_map_[camera_names_[i]] = sensor_info;

          std::string tf_camera_frame_id =
              sensor_manager->GetFrameId(camera_names_[i]);
          tf_camera_frame_id_map_[camera_names_[i]] = tf_camera_frame_id;
          std::shared_ptr<TransformWrapper> trans_wrapper(new TransformWrapper);
          trans_wrapper->Init(tf_camera_frame_id);
          camera2world_trans_wrapper_map_[camera_names_[i]] = trans_wrapper;
        }

        // assume all camera have same image size
        base::BaseCameraModelPtr camera_model_ptr =
            sensor_manager->GetUndistortCameraModel(camera_names_[0]);
        image_width_ = static_cast<int>(camera_model_ptr->get_width());
        image_height_ = static_cast<int>(camera_model_ptr->get_height());

        std::string format_str = R"(
      camera_names: %s %s
      tf_camera_frame_ids: %s %s
      image_width: %d
      image_height: %d
      image_channel_num: %d)";
        std::string sensor_info_str =
            str(boost::format(format_str.c_str()) % camera_names_[0] %
                camera_names_[1] % tf_camera_frame_id_map_[camera_names_[0]] %
                tf_camera_frame_id_map_[camera_names_[1]] % image_width_ %
                image_height_ % image_channel_num_);
        AINFO << sensor_info_str;

        return cyber::SUCC;
      }

      int LaneDetectionComponent::InitAlgorithmPlugin()
      {
        camera_lane_pipeline_.reset(new camera::LaneCameraPerception);
        if (!camera_lane_pipeline_->Init(camera_perception_init_options_))
        {
          AERROR << "camera_lane_pipeline_->Init() failed";
          return cyber::FAIL;
        }
        AINFO << "camera_lane_pipeline_->Init() succeed";
        return cyber::SUCC;
      }

      int LaneDetectionComponent::InitCameraFrames()
      {
        if (camera_names_.size() != 2)
        {
          AERROR << "invalid camera_names_.size(): " << camera_names_.size();
          return cyber::FAIL;
        }
        // fixed size
        camera_frames_.resize(frame_capacity_);
        if (camera_frames_.empty())
        {
          AERROR << "frame_capacity_ must > 0";
          return cyber::FAIL;
        }

        // init data_providers for each camera
        for (const auto &camera_name : camera_names_)
        {
          camera::DataProvider::InitOptions data_provider_init_options;
          
          data_provider_init_options.image_height = image_height_;
          
          data_provider_init_options.image_width = image_width_;
          
          data_provider_init_options.do_undistortion = enable_undistortion_;
          
          data_provider_init_options.sensor_name = camera_name;
          
          int gpu_id = GetGpuId(camera_perception_init_options_);
          
          if (gpu_id == -1)
          {
            return cyber::FAIL;
          }
          data_provider_init_options.device_id = gpu_id;
          AINFO << "data_provider_init_options.device_id: "
                << data_provider_init_options.device_id
                << " camera_name: " << camera_name;

          std::shared_ptr<camera::DataProvider> data_provider(
              new camera::DataProvider);
          
          data_provider->Init(data_provider_init_options);
          data_providers_map_[camera_name] = data_provider;
        }
        

        //  init extrinsic/intrinsic
        for (const auto &camera_name : camera_names_)
        {
          
          base::BaseCameraModelPtr model;
          model =
              common::SensorManager::Instance()->GetUndistortCameraModel(camera_name);
          auto pinhole = static_cast<base::PinholeCameraModel *>(model.get());
          Eigen::Matrix3f intrinsic = pinhole->get_intrinsic_params();
          intrinsic_map_[camera_name] = intrinsic;
          AINFO << "#intrinsics of " << camera_name << ": "
                << intrinsic_map_[camera_name];
          Eigen::Matrix4d extrinsic;
          LoadExtrinsics(FLAGS_obs_sensor_intrinsic_path + "/" + camera_name +
                             "_extrinsics.yaml",
                         &extrinsic);
          extrinsic_map_[camera_name] = extrinsic;
        }

        
        // Init camera height
        for (const auto &camera_name : camera_names_)
        {
          float height = 0.0f;
          SetCameraHeight(camera_name, FLAGS_obs_sensor_intrinsic_path,
                          default_camera_height_, &height);
          camera_height_map_[camera_name] = height;
        }
        

        for (auto &frame : camera_frames_)
        {
          frame.track_feature_blob.reset(new base::Blob<float>());
          frame.lane_detected_blob.reset(new base::Blob<float>());
        }
        
        return cyber::SUCC;
      }

      int LaneDetectionComponent::InitProjectMatrix()
      {
        if (!GetProjectMatrix(camera_names_, extrinsic_map_, intrinsic_map_,
                              &project_matrix_, &pitch_diff_))
        {
          AERROR << "GetProjectMatrix failed";
          return cyber::FAIL;
        }
        AINFO << "project_matrix_: " << project_matrix_;
        AINFO << "pitch_diff_:" << pitch_diff_;
        name_camera_pitch_angle_diff_map_[camera_names_[0]] = 0.f;
        name_camera_pitch_angle_diff_map_[camera_names_[1]] =
            static_cast<float>(pitch_diff_);

        return cyber::SUCC;
      }

      int LaneDetectionComponent::InitMotionService()
      {
        const std::string &channel_name_local = "/apollo/perception/motion_service";
        // std::function<void(const MotionServiceMsgType &)> motion_service_callback =
        //     std::bind(&LaneDetectionComponent::OnMotionService, this,
        //               std::placeholders::_1);
        motion_service_reader =
            node_->CreateReader<Motion_Service>(channel_name_local, std::bind(&LaneDetectionComponent::OnMotionService, this,
                                                                              std::placeholders::_1));
        // initialize motion buffer
        if (mot_buffer_ == nullptr)
        {
          mot_buffer_.reset(new base::MotionBuffer(motion_buffer_size_));
        }
        else
        {
          mot_buffer_->set_capacity(motion_buffer_size_);
        }
        return cyber::SUCC;
      }

      int LaneDetectionComponent::InitCameraListeners()
      {
        for (size_t i = 0; i < camera_names_.size(); ++i)
        {
          const std::string &camera_name = camera_names_[i];
          const std::string &channel_name = input_camera_channel_names_[i];
          const std::string &listener_name = camera_name + "_fusion_camera_listener";
          AINFO << "listener name: " << listener_name;

          // typedef std::shared_ptr<apollo::drivers::Image> ImageMsgType;
          // std::function<void(const ImageMsgType &)> camera_callback =
          //     std::bind(&LaneDetectionComponent::OnReceiveImage, this,
          //               std::placeholders::_1, camera_name);
          auto camera_reader = node_->CreateReader<apollo::drivers::Image>(channel_name, std::bind(&LaneDetectionComponent::OnReceiveImage, this,
                                                                                                   std::placeholders::_1, camera_name));
          camera_listener_.push_back(camera_reader);
        }
        return cyber::SUCC;
      }

      void LaneDetectionComponent::SetCameraHeightAndPitch()
      {
        camera_lane_pipeline_->SetCameraHeightAndPitch(
            camera_height_map_, name_camera_pitch_angle_diff_map_,
            default_camera_pitch_);
      }

      int LaneDetectionComponent::InternalProc(
          const std::shared_ptr<apollo::drivers::Image const> &in_message,
          const std::string &camera_name, apollo::common::ErrorCode *error_code,
          SensorFrameMessage *prefused_message,
          apollo::perception::PerceptionLanes *out_message)
      {
        UNUSED(out_message);
        const double msg_timestamp =
            in_message->measurementtime + timestamp_offset_;
        const int frame_size = static_cast<int>(camera_frames_.size());
        camera::CameraFrame &camera_frame = camera_frames_[frame_id_ % frame_size];

        prefused_message->timestamp_ = msg_timestamp;
        prefused_message->seq_num_ = seq_num_;
        prefused_message->process_stage_ = ProcessStage::MONOCULAR_CAMERA_DETECTION;
        prefused_message->sensor_id_ = camera_name;
        prefused_message->frame_ = base::FramePool::Instance().Get();
        prefused_message->frame_->sensor_info = sensor_info_map_[camera_name];
        prefused_message->frame_->timestamp = msg_timestamp;

        // Get sensor to world pose from TF
        Eigen::Affine3d camera2world_trans;
        if (!camera2world_trans_wrapper_map_[camera_name]->GetSensor2worldTrans(
                msg_timestamp, &camera2world_trans))
        {
          const std::string err_str =
              absl::StrCat("failed to get camera to world pose, ts: ", msg_timestamp,
                           " camera_name: ", camera_name);
          AERROR << err_str;
          *error_code = apollo::common::ErrorCode::PERCEPTION_ERROR_TF;
          prefused_message->error_code_ = *error_code;
          return cyber::FAIL;
        }
        prefused_message->frame_->sensor2world_pose = camera2world_trans;

        // Fill camera frame
        // frame_size != 0, see InitCameraFrames()
        camera_frame.camera2world_pose = camera2world_trans;
        camera_frame.data_provider = data_providers_map_[camera_name].get();
        camera_frame.data_provider->FillImageData(
            image_height_, image_width_,
            reinterpret_cast<const uint8_t *>(in_message->data.data.data()),
            in_message->encoding);

        camera_frame.frame_id = frame_id_;
        camera_frame.timestamp = msg_timestamp;
        // get narrow to short projection matrix
        if (camera_frame.data_provider->sensor_name() == camera_names_[1])
        {
          camera_frame.project_matrix = project_matrix_;
        }
        else
        {
          camera_frame.project_matrix.setIdentity();
        }

        ++frame_id_;
        // Run camera perception pipeline
        camera_lane_pipeline_->GetCalibrationService(
            &camera_frame.calibration_service);

        if (!camera_lane_pipeline_->Perception(camera_perception_options_,
                                               &camera_frame))
        {
          AERROR << "camera_lane_pipeline_->Perception() failed msg_timestamp: "
                 << msg_timestamp;
          *error_code = apollo::common::ErrorCode::PERCEPTION_ERROR_PROCESS;
          prefused_message->error_code_ = *error_code;
          return cyber::FAIL;
        }
        AINFO_EVERY(60000) << "##" << camera_name << ": pitch "
              << camera_frame.calibration_service->QueryPitchAngle()
              << " | camera_grond_height "
              << camera_frame.calibration_service->QueryCameraToGroundHeight();
        prefused_message->frame_->objects = camera_frame.tracked_objects;

        *error_code = apollo::common::ErrorCode::OK;
        prefused_message->error_code_ = *error_code;

        prefused_message->frame_->camera_frame_supplement.on_use = true;
        if (FLAGS_obs_enable_visualization)
        {
          camera::DataProvider::ImageOptions image_options;
          image_options.target_color = base::Color::RGB;

          // Use Blob to pass image data
          prefused_message->frame_->camera_frame_supplement.image_blob.reset(
              new base::Blob<uint8_t>);
          camera_frame.data_provider->GetImageBlob(
              image_options,
              prefused_message->frame_->camera_frame_supplement.image_blob.get());
        }

        // Send msg for visualization
        if (enable_visualization_)
        {
          camera::DataProvider::ImageOptions image_options;
          image_options.target_color = base::Color::BGR;
          std::shared_ptr<base::Blob<uint8_t>> image_blob(new base::Blob<uint8_t>);
          camera_frame.data_provider->GetImageBlob(image_options, image_blob.get());

          cv::Mat output_image(image_height_, image_width_, CV_8UC3,
                               cv::Scalar(0, 0, 0));
          base::Image8U out_image(image_height_, image_width_, base::Color::RGB);
          camera_frame.data_provider->GetImage(image_options, &out_image);
          memcpy(output_image.data, out_image.cpu_data(),
                 out_image.total() * sizeof(uint8_t));
        }

        // send out lane message
        // TODO(yg13): add lanes in world coordinates
        std::shared_ptr<apollo::perception::PerceptionLanes> lanes_msg(
            new (std::nothrow) apollo::perception::PerceptionLanes);
        if (MakeProtobufMsg(msg_timestamp, camera_name, camera_frame,
                            lanes_msg.get()) != cyber::SUCC)
        {
          AERROR << "make lanes_msg failed";
          return cyber::FAIL;
        }
        writer_->Write(lanes_msg);

        return cyber::SUCC;
      }

      int LaneDetectionComponent::ConvertLaneToCameraLaneline(
          const base::LaneLine &lane_line,
          apollo::perception::camera::CameraLaneLine *camera_laneline)
      {
        if (camera_laneline == nullptr)
        {
          AERROR << "camera_laneline is not available";
          return false;
        }
        // fill the lane line attribute
        apollo::perception::camera::LaneLineType line_type =
            static_cast<apollo::perception::camera::LaneLineType>(lane_line.type);
        camera_laneline->type = line_type;
        apollo::perception::camera::LaneLinePositionType pos_type =
            static_cast<apollo::perception::camera::LaneLinePositionType>(
                lane_line.pos_type);
        camera_laneline->postype = pos_type;
        camera_laneline->trackid = lane_line.track_id;
        camera_laneline->confidence = lane_line.confidence;
        apollo::perception::camera::LaneLineUseType use_type =
            static_cast<apollo::perception::camera::LaneLineUseType>(
                lane_line.use_type);
        camera_laneline->usetype = use_type;
        // fill the curve camera coord
        camera_laneline->curvecameracoord.longitudemin =
            lane_line.curve_camera_coord.x_start;
        camera_laneline->curvecameracoord.longitudemax =
            lane_line.curve_camera_coord.x_end;
        camera_laneline->curvecameracoord.a =
            lane_line.curve_camera_coord.a;
        camera_laneline->curvecameracoord.b =
            lane_line.curve_camera_coord.b;
        camera_laneline->curvecameracoord.c =
            lane_line.curve_camera_coord.c;
        camera_laneline->curvecameracoord.d =
            lane_line.curve_camera_coord.d;
        // fill the curve image coord
        camera_laneline->curveimagecoord.longitudemin =
            lane_line.curve_image_coord.x_start;
        camera_laneline->curveimagecoord.longitudemax =
            lane_line.curve_image_coord.x_end;
        camera_laneline->curveimagecoord.a =
            lane_line.curve_image_coord.a;
        camera_laneline->curveimagecoord.b =
            lane_line.curve_image_coord.b;
        camera_laneline->curveimagecoord.c =
            lane_line.curve_image_coord.c;
        camera_laneline->curveimagecoord.d =
            lane_line.curve_image_coord.d;
        // fill the curve image point set
        for (size_t i = 0; i < lane_line.curve_image_point_set.size(); i++)
        {
          const base::Point2DF &image_point2d = lane_line.curve_image_point_set[i];
          apollo::common::Point2D lane_point_2d; //=
                                                 // camera_laneline->add_curve_image_point_set();
          lane_point_2d.x = image_point2d.x;
          lane_point_2d.y = image_point2d.y;

          camera_laneline->curveimagepointset.push_back(lane_point_2d);
        }
        // fill the curve camera point set
        for (size_t i = 0; i < lane_line.curve_camera_point_set.size(); i++)
        {
          const base::Point3DF &point3d = lane_line.curve_camera_point_set[i];
          apollo::common::Point3D lane_point_3d; //=
                                                 // camera_laneline->add_curve_camera_point_set();
          lane_point_3d.x = point3d.x;
          lane_point_3d.y = point3d.y;
          lane_point_3d.z = point3d.z;

          camera_laneline->curvecamerapointset.push_back(lane_point_3d);
        }
        // fill the line end point set
        for (size_t i = 0; i < lane_line.image_end_point_set.size(); i++)
        {
          const base::EndPoints &end_points = lane_line.image_end_point_set[i];
          apollo::perception::camera::EndPoints lane_end_points; //=
                                                                 // camera_laneline->add_image_end_point_set();
          lane_end_points.start.x = end_points.start.x;
          lane_end_points.start.y = end_points.start.y;
          lane_end_points.end.x = end_points.end.x;
          lane_end_points.end.y = end_points.end.y;

          camera_laneline->imageendpointset.push_back(lane_end_points);
        }
        return cyber::SUCC;
      }

      int LaneDetectionComponent::MakeProtobufMsg(
          double msg_timestamp, const std::string &camera_name,
          const camera::CameraFrame &camera_frame,
          apollo::perception::PerceptionLanes *lanes_msg)
      {
        if (lanes_msg == nullptr)
        {
          AERROR << "lanes_msg is not available";
          return false;
        }
        auto itr = std::find(camera_names_.begin(), camera_names_.end(), camera_name);
        if (itr == camera_names_.end())
        {
          AERROR << "invalid camera_name: " << camera_name;
          return cyber::FAIL;
        }
        int input_camera_channel_names_idx =
            static_cast<int>(itr - camera_names_.begin());
        int input_camera_channel_names_size =
            static_cast<int>(input_camera_channel_names_.size());
        if (input_camera_channel_names_idx < 0 ||
            input_camera_channel_names_idx >= input_camera_channel_names_size)
        {
          AERROR << "invalid input_camera_channel_names_idx: "
                 << input_camera_channel_names_idx
                 << " input_camera_channel_names_.size(): "
                 << input_camera_channel_names_.size();
          return cyber::FAIL;
        }
        std::string source_channel_name =
            input_camera_channel_names_[input_camera_channel_names_idx];
        lanes_msg->sourcetopic = source_channel_name;

        // Fill header info.
        apollo::common::Header *header = &lanes_msg->apolloheader;
        header->cameratimestamp = static_cast<uint64_t>(msg_timestamp * 1.0e9);

        // Fill the laneline objects
        const std::vector<base::LaneLine> &lane_objects = camera_frame.lane_objects;
        for (const auto &lane_obj : lane_objects)
        {
          apollo::perception::camera::CameraLaneLine camera_laneline; //=
                                                                      // lanes_msg->add_camera_laneline();
          ConvertLaneToCameraLaneline(lane_obj, &camera_laneline);

          lanes_msg->cameralaneline.push_back(camera_laneline);
        }

        // Fill the calibrator information(pitch angle)
        float pitch_angle = camera_frame.calibration_service->QueryPitchAngle();
        lanes_msg->cameracalibrator.pitchangle = pitch_angle;
        return cyber::SUCC;
      }

    } // namespace onboard
  }   // namespace perception
} // namespace apollo

CYBER_REGISTER_COMPONENT(LaneDetectionComponent);
