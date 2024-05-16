/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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

#include "component/online_visualizer.h"

#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/configs/config_gflags.h"

#include "cyber/cyber.h"
#include "modules/common/math/quaternion.h"
#include "modules/localization/common/localization_gflags.h"
#include "modules/localization/msf/common/io/pcl_point_types.h"
#include "modules/localization/msf/common/io/velodyne_utility.h"
#include "modules/localization/msf/local_pyramid_map/base_map/base_map_config.h"

namespace apollo
{
  namespace localization
  {
    namespace msf
    {

      OnlineVisualizerComponent::~OnlineVisualizerComponent()
      {
        VisualizationManager::GetInstance().StopVisualization();
      }

      bool OnlineVisualizerComponent::Init()
      {

        AINFO << "Setting gflags";

        INIT_FLAG_string(localization_module_name, "localization",
                         "localization module name");

        INIT_FLAG_double(localization_publish_freq, 100,
                         "localization publishing frequency.");

        // features
        INIT_FLAG_bool(enable_gps_imu_interprolate, true, "enable GPU/IMU interprolate");
        INIT_FLAG_bool(enable_map_reference_unify, true,
                       "enable IMU data convert to map reference");
        INIT_FLAG_bool(enable_watchdog, true, "enable watchdog");

        INIT_FLAG_double(gps_time_delay_tolerance, 1.0,
                         "gps message time delay tolerance (sec)");

        INIT_FLAG_double(gps_imu_timestamp_sec_diff_tolerance, 20e-3,
                         "gps/imu timestamp diff tolerance (sec)");

        INIT_FLAG_double(timestamp_sec_tolerance, 10e-7, "timestamp second tolerance");
        // map offset
        INIT_FLAG_double(map_offset_x, 0.0, "map_offsite: x");
        INIT_FLAG_double(map_offset_y, 0.0, "map_offsite: y");
        INIT_FLAG_double(map_offset_z, 0.0, "map_offsite: z");

        INIT_FLAG_int32(report_threshold_err_num, 10, "report threshold error num");
        INIT_FLAG_double(report_gps_imu_time_diff_threshold, 0.02,
                         "report threshold of timestamp diff between gps and imu(sec)");

        INIT_FLAG_bool(enable_gps_timestamp, false,
                       "True to set gps timestamp as localization header timestamp");

        // msf parame
        INIT_FLAG_string(local_map_name, "local_map", "The path of localization map.");
        INIT_FLAG_string(lidar_extrinsics_file,
                         "data/localization/msf/params/velodyne_params/"
                         "velodyne64_novatel_extrinsics_example.yaml",
                         "Lidar extrinsics parameter file.");
        INIT_FLAG_string(lidar_height_file,
                         "data/localization/msf/params/velodyne_params/"
                         "velodyne64_height.yaml",
                         "Velodyne extrinsic path for the vehicle in use, "
                         "where <ros> is the placeholder of ROS root.");
        INIT_FLAG_double(lidar_height_default, 1.80,
                         "The height from the center of velodyne to ground.");
        INIT_FLAG_int32(
            lidar_localization_mode, 2,
            "Localization mode, 0 for intensity, 1 for altitude, 2 for fusion.");
        INIT_FLAG_int32(lidar_yaw_align_mode, 2,
                        "image yaw align mode, 0 for align off, "
                        "1 for fusion, 2 for fusion with multithread.");
        INIT_FLAG_int32(lidar_filter_size, 17, "Lidar filter size");
        INIT_FLAG_double(lidar_imu_max_delay_time, 0.4,
                         "Lidar msg and imu msg max delay time");
        INIT_FLAG_double(lidar_map_coverage_theshold, 0.9,
                         "Threshold to detect whether vehicle is out of map");
        INIT_FLAG_bool(lidar_debug_log_flag, false, "Lidar Debug switch.");
        INIT_FLAG_int32(point_cloud_step, 2, "Point cloud step");
        INIT_FLAG_bool(if_use_avx, false,
                       "if use avx to accelerate lidar localization, "
                       "need cpu to support AVX intel instrinsics");

        // integ module
        INIT_FLAG_bool(integ_ins_can_self_align, false, "");
        INIT_FLAG_bool(integ_sins_align_with_vel, true, "");
        INIT_FLAG_bool(integ_sins_state_check, false, "");
        INIT_FLAG_double(integ_sins_state_span_time, 60.0, "");
        INIT_FLAG_double(integ_sins_state_pos_std, 1.0, "");
        INIT_FLAG_double(vel_threshold_get_yaw, 5.0, "");

        // gnss module
        INIT_FLAG_bool(enable_ins_aid_rtk, false, "");
        INIT_FLAG_string(eph_buffer_path, "", "");
        INIT_FLAG_string(
            ant_imu_leverarm_file,
            "data/localization/msf/params/gnss_params/ant_imu_leverarm.yaml",
            "Ant to imu leferarm.");
        INIT_FLAG_bool(gnss_debug_log_flag, false, "Gnss Debug switch.");
        INIT_FLAG_bool(if_imuant_from_file, true, "Use imu ant from gnss configure file.");
        INIT_FLAG_double(imu_to_ant_offset_x, 0.0, "Imu ant offset x");
        INIT_FLAG_double(imu_to_ant_offset_y, 0.0, "Imu ant offset y");
        INIT_FLAG_double(imu_to_ant_offset_z, 0.0, "Imu ant offset z");
        INIT_FLAG_double(imu_to_ant_offset_ux, 0.0, "Imu ant offset x uncertainty");
        INIT_FLAG_double(imu_to_ant_offset_uy, 0.0, "Imu ant offset y uncertainty");
        INIT_FLAG_double(imu_to_ant_offset_uz, 0.0, "Imu ant offset z uncertainty");

        // common
        INIT_FLAG_double(imu_rate, 1.0, "");
        INIT_FLAG_bool(if_utm_zone_id_from_folder, true,
                       "load utm zone id from local map folder");
        INIT_FLAG_bool(trans_gpstime_to_utctime, true, "");
        INIT_FLAG_int32(gnss_mode, 0, "GNSS Mode, 0 for bestgnss pose, 1 for self gnss.");
        INIT_FLAG_bool(imu_coord_rfu, true, "Right/forward/up");
        INIT_FLAG_bool(gnss_only_init, false,
                       "Whether use bestgnsspose as measure after initializaiton.");
        INIT_FLAG_bool(enable_lidar_localization, true,
                       "Enable lidar-based localization.");

        INIT_FLAG_string(lidar_topic, "/apollo/sensor/lidar128/compensator/PointCloud2",
                         "lidar pointcloud topic");
        INIT_FLAG_string(broadcast_tf_frame_id, "world", "world frame id in tf");
        INIT_FLAG_string(broadcast_tf_child_frame_id, "localization",
                         "localization frame id in tf");
        // imu vehicle extrinsic
        INIT_FLAG_string(vehicle_imu_file,
                         "data/localization/msf/params"
                         "/vehicle_params/vehicle_imu_extrinsics.yaml",
                         "Vehicle coord to imu coord.");
        INIT_FLAG_bool(if_vehicle_imu_from_file, true,
                       "Whether load vehicle imu extrinsic from yaml file");
        INIT_FLAG_double(imu_vehicle_qx, 0.0, "Vehicle imu quaternion qx");
        INIT_FLAG_double(imu_vehicle_qy, 0.0, "Vehicle imu quaternion qy");
        INIT_FLAG_double(imu_vehicle_qz, 0.0, "Vehicle imu quaternion qz");
        INIT_FLAG_double(imu_vehicle_qw, 1.0, "Vehicle imu quaternion qw");

        // visualization
        INIT_FLAG_string(map_visual_dir, "data/map_visual",
                         "The path of map_visual folder.");

        // Status
        INIT_FLAG_double(imu_delay_time_threshold_1, 0.1,
                         "imu delay time is larger than 0.1s");
        INIT_FLAG_double(imu_delay_time_threshold_2, 0.05,
                         "imu delay time is larger than 0.05s");
        INIT_FLAG_double(imu_delay_time_threshold_3, 0.02,
                         "imu delay time is larger than 0.02s");

        INIT_FLAG_double(imu_missing_time_threshold_1, 0.1,
                         "imu missing time is larger than 0.1s");
        INIT_FLAG_double(imu_missing_time_threshold_2, 0.05,
                         "imu missing time is larger than 0.05s");
        INIT_FLAG_double(imu_missing_time_threshold_3, 0.01,
                         "imu missing time is larger than 0.01s");

        INIT_FLAG_double(bestgnsspose_loss_time_threshold, 2.0,
                         "threshold for time gap between imu and bestgnsspose time");
        INIT_FLAG_double(lidar_loss_time_threshold, 2.0,
                         "threshold for time gap between imu and lidar pose time");

        INIT_FLAG_double(localization_std_x_threshold_1, 0.15,
                         "threshold for lateral std of localization result");
        INIT_FLAG_double(localization_std_y_threshold_1, 0.15,
                         "threshold for longitudinal std of localization result");

        INIT_FLAG_double(localization_std_x_threshold_2, 0.3,
                         "threshold for lateral std of localization result");
        INIT_FLAG_double(localization_std_y_threshold_2, 0.3,
                         "threshold for longitudinal std of localization result");

        // ndt localization
        INIT_FLAG_string(ndt_map_dir, "ndt_map", "subdirectory for ndt map");
        INIT_FLAG_bool(ndt_debug_log_flag, false, "NDT Localization log switch");
        INIT_FLAG_double(online_resolution, 2.0, "NDT online pointcloud resolution");
        INIT_FLAG_int32(ndt_max_iterations, 10, "maximum iterations for NDT matching");
        INIT_FLAG_double(ndt_target_resolution, 1.0,
                         "target resolution for ndt localization");
        INIT_FLAG_double(ndt_line_search_step_size, 0.1,
                         "line search step size for ndt matching");
        INIT_FLAG_double(ndt_transformation_epsilon, 0.01,
                         "iteration convergence condition on transformation");
        INIT_FLAG_int32(ndt_filter_size_x, 48, "x size for ndt searching area");
        INIT_FLAG_int32(ndt_filter_size_y, 48, "y size for ndt searching area");
        INIT_FLAG_int32(ndt_bad_score_count_threshold, 10,
                        "count for continuous bad ndt fitness score");
        INIT_FLAG_double(ndt_warnning_ndt_score, 1.0,
                         "warnning ndt fitness score threshold");
        INIT_FLAG_double(ndt_error_ndt_score, 2.0, "error ndt fitness score threshold");
        apollo::common::gflags::init_common(this);
        apollo::common::gflags::init_common_adapter(this);
        AINFO << "Gflags set";
        AINFO << ">>>InitConfig";
        if (!InitConfig())
        {
          AERROR << "InitParams failed.";
          return false;
        }
        AINFO << "<<<InitConfig";
        AINFO << ">>>InitIO";
        if (!InitIO())
        {
          AERROR << "InitIO failed.";
          return false;
        }
        AINFO << "<<<InitIO";
        ADEBUG << "VisualizationManager::GetInstance().StartVisualization()";
        VisualizationManager::GetInstance().StartVisualization();

        return true;
      }

      bool OnlineVisualizerComponent::InitConfig()
      {
        map_folder_ = FLAGS_map_dir + "/" + FLAGS_local_map_name;
        map_visual_folder_ = FLAGS_map_visual_dir;
        lidar_extrinsic_file_ = FLAGS_lidar_extrinsics_file;

        lidar_local_topic_ = FLAGS_localization_lidar_topic;
        gnss_local_topic_ = FLAGS_localization_gnss_topic;
        fusion_local_topic_ = FLAGS_localization_topic;
        ndt_local_topic_ = FLAGS_localization_ndt_topic;

        Eigen::Affine3d velodyne_extrinsic;
        ADEBUG << "velodyne::LoadExtrinsic";
        bool success =
            velodyne::LoadExtrinsic(lidar_extrinsic_file_, &velodyne_extrinsic);
        if (!success)
        {
          AERROR << "Load lidar extrinsic failed.";
          return false;
        }
        ADEBUG << "Load lidar extrinsic succeed.";

        pyramid_map::BaseMapConfig map_config;
        std::string config_file = map_folder_ + "/config.xml";
        map_config.map_version_ = "lossy_map";
        ADEBUG << "map_config.Load("<<config_file<<")";
        success = map_config.Load(config_file);
        if (!success)
        {
          AERROR << "Load map config failed.";
          return false;
        }
        ADEBUG << "Load map config succeed." ;

        VisualMapParam map_param;
        ADEBUG << ">>>map_param.set";

        map_param.set(map_config.map_resolutions_, map_config.map_node_size_x_,
                      map_config.map_node_size_y_, map_config.map_range_.GetMinX(),
                      map_config.map_range_.GetMinY(),
                      map_config.map_range_.GetMaxX(),
                      map_config.map_range_.GetMaxY());
        ADEBUG << ">>>VisualizationManager::GetInstance().Init";

        success = VisualizationManager::GetInstance().Init(
            map_folder_, map_visual_folder_, velodyne_extrinsic, map_param);
        ADEBUG << "<<<VisualizationManager::GetInstance().Init";
        if (!success)
        {
          return false;
        }
        return true;
      }

      bool OnlineVisualizerComponent::InitIO()
      {
        // Lidar localization
        std::function<void(const std::shared_ptr<LocalizationEstimate> &)>
            lidar_local_call =
                std::bind(&OnlineVisualizerComponent::OnLidarLocalization, this,
                          std::placeholders::_1);
        lidar_local_listener_ = this->node_->CreateReader<LocalizationEstimate>(
            lidar_local_topic_, lidar_local_call);

        // GNSS localization
        std::function<void(const std::shared_ptr<LocalizationEstimate> &)>
            gnss_local_call =
                std::bind(&OnlineVisualizerComponent::OnGNSSLocalization, this,
                          std::placeholders::_1);
        gnss_local_listener_ = this->node_->CreateReader<LocalizationEstimate>(
            gnss_local_topic_, gnss_local_call);

        // Fusion localization
        std::function<void(const std::shared_ptr<LocalizationEstimate> &)>
            fusion_local_call =
                std::bind(&OnlineVisualizerComponent::OnFusionLocalization, this,
                          std::placeholders::_1);
        fusion_local_listener_ = this->node_->CreateReader<LocalizationEstimate>(
            fusion_local_topic_, fusion_local_call);

        // Ndt Localization
        std::function<void(const std::shared_ptr<LocalizationEstimate> &)>
            ndt_local_call =
                std::bind(&OnlineVisualizerComponent::OnLidarLocalization, this,
                          std::placeholders::_1);
        lidar_local_listener_ = this->node_->CreateReader<LocalizationEstimate>(
            ndt_local_topic_, ndt_local_call);

        dag_reader_ = node_->CreateReader<drivers::PointCloud>("/apollo/sensor/lidar128/compensator/PointCloud2", std::bind(&OnlineVisualizerComponent::Proc, this, std::placeholders::_1));

        return true;
      }

      bool OnlineVisualizerComponent::Proc(
          const std::shared_ptr<drivers::PointCloud> &msg)
      {
        LidarVisFrame lidar_vis_frame;
        lidar_vis_frame.timestamp = cyber::Time(msg->measurementtime).ToSecond();

        std::vector<unsigned char> intensities;
        ParsePointCloudMessage(msg, &lidar_vis_frame.pt3ds, &intensities);

        static unsigned int id = 1;
        lidar_vis_frame.frame_id = id;
        VisualizationManager::GetInstance().AddLidarFrame(lidar_vis_frame);

        id++;
        return true;
      }

      void OnlineVisualizerComponent::OnLidarLocalization(
          const std::shared_ptr<LocalizationEstimate> &msg)
      {
        LocalizationMsg lidar_loc_msg;

        lidar_loc_msg.timestamp = msg->measurementtime;
        lidar_loc_msg.x = msg->pose.position.x;
        lidar_loc_msg.y = msg->pose.position.y;
        lidar_loc_msg.z = msg->pose.position.z;

        lidar_loc_msg.qx = msg->pose.orientation.qx;
        lidar_loc_msg.qy = msg->pose.orientation.qy;
        lidar_loc_msg.qz = msg->pose.orientation.qz;
        lidar_loc_msg.qw = msg->pose.orientation.qw;

        if (
            !std::isnan(msg->uncertainty.positionstddev.x) &&
            !std::isnan(msg->uncertainty.positionstddev.y) &&
            msg->uncertainty.positionstddev.x > 0 &&
            msg->uncertainty.positionstddev.y > 0)
        {
          lidar_loc_msg.std_x = msg->uncertainty.positionstddev.x;
          lidar_loc_msg.std_y = msg->uncertainty.positionstddev.y;
          lidar_loc_msg.std_z = msg->uncertainty.positionstddev.z;
        }

        VisualizationManager::GetInstance().AddLidarLocMessage(lidar_loc_msg);
      }

      void OnlineVisualizerComponent::OnGNSSLocalization(
          const std::shared_ptr<LocalizationEstimate> &msg)
      {
        LocalizationMsg gnss_loc_msg;

        gnss_loc_msg.timestamp = msg->measurementtime;
        gnss_loc_msg.x = msg->pose.position.x;
        gnss_loc_msg.y = msg->pose.position.y;
        gnss_loc_msg.z = msg->pose.position.z;

        gnss_loc_msg.qx = msg->pose.orientation.qx;
        gnss_loc_msg.qy = msg->pose.orientation.qy;
        gnss_loc_msg.qz = msg->pose.orientation.qz;
        gnss_loc_msg.qw = msg->pose.orientation.qw;

        if (
            !std::isnan(msg->uncertainty.positionstddev.x) &&
            !std::isnan(msg->uncertainty.positionstddev.y) &&
            msg->uncertainty.positionstddev.x > 0 &&
            msg->uncertainty.positionstddev.y > 0)
        {
          gnss_loc_msg.std_x = msg->uncertainty.positionstddev.x;
          gnss_loc_msg.std_y = msg->uncertainty.positionstddev.y;
          gnss_loc_msg.std_z = msg->uncertainty.positionstddev.z;
        }

        VisualizationManager::GetInstance().AddGNSSLocMessage(gnss_loc_msg);
      }

      void OnlineVisualizerComponent::OnFusionLocalization(
          const std::shared_ptr<LocalizationEstimate> &msg)
      {
        LocalizationMsg fusion_loc_msg;

        fusion_loc_msg.timestamp = msg->measurementtime;
        fusion_loc_msg.x = msg->pose.position.x;
        fusion_loc_msg.y = msg->pose.position.y;
        fusion_loc_msg.z = msg->pose.position.z;

        fusion_loc_msg.qx = msg->pose.orientation.qx;
        fusion_loc_msg.qy = msg->pose.orientation.qy;
        fusion_loc_msg.qz = msg->pose.orientation.qz;
        fusion_loc_msg.qw = msg->pose.orientation.qw;

        if (
            !std::isnan(msg->uncertainty.positionstddev.x) &&
            !std::isnan(msg->uncertainty.positionstddev.y) &&
            msg->uncertainty.positionstddev.x > 0 &&
            msg->uncertainty.positionstddev.y > 0)
        {
          fusion_loc_msg.std_x = msg->uncertainty.positionstddev.x;
          fusion_loc_msg.std_y = msg->uncertainty.positionstddev.y;
          fusion_loc_msg.std_z = msg->uncertainty.positionstddev.z;
        }

        VisualizationManager::GetInstance().AddFusionLocMessage(fusion_loc_msg);
      }

      void OnlineVisualizerComponent::ParsePointCloudMessage(
          const std::shared_ptr<drivers::PointCloud> &msg,
          ::apollo::common::EigenVector3dVec *pt3ds,
          std::vector<unsigned char> *intensities)
      {
        CHECK_NOTNULL(pt3ds);
        CHECK_NOTNULL(intensities);

        if (msg->height > 1 && msg->width > 1)
        {
          for (unsigned int i = 0; i < msg->height; ++i)
          {
            for (unsigned int j = 0; j < msg->width; ++j)
            {
              Eigen::Vector3d pt3d;
              pt3d[0] = static_cast<double>(msg->point.at(i * msg->width + j).x);
              pt3d[1] = static_cast<double>(msg->point.at(i * msg->width + j).y);
              pt3d[2] = static_cast<double>(msg->point.at(i * msg->width + j).z);
              if (!std::isnan(pt3d[0]))
              {
                unsigned char intensity = static_cast<unsigned char>(
                    msg->point.at(i * msg->width + j).intensity);
                pt3ds->push_back(pt3d);
                intensities->push_back(intensity);
              }
            }
          }
        }
        else
        {
          AINFO << "Receiving un-organized-point-cloud, width " << msg->width
                << " height " << msg->height << "size " << msg->point.size();
          for (size_t i = 0; i < msg->point.size(); ++i)
          {
            Eigen::Vector3d pt3d;
            pt3d[0] = static_cast<double>(msg->point.at(i).x);
            pt3d[1] = static_cast<double>(msg->point.at(i).y);
            pt3d[2] = static_cast<double>(msg->point.at(i).z);
            if (!std::isnan(pt3d[0]))
            {
              unsigned char intensity =
                  static_cast<unsigned char>(msg->point.at(i).intensity);
              pt3ds->push_back(pt3d);
              intensities->push_back(intensity);
            }
          }
        }
      }

    } // namespace msf
  }   // namespace localization
} // namespace apollo
CYBER_REGISTER_COMPONENT(OnlineVisualizerComponent);
