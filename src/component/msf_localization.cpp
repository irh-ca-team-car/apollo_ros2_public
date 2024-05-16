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

#include "component/msf_localization.h"

#include "cyber/cyber.h"
#include "modules/common/math/quaternion.h"

#include "modules/common/adapters/adapter_gflags.h"
#include "modules/localization/common/localization_gflags.h"

namespace apollo {
namespace localization {

using apollo::cyber::Clock;

bool MSFLocalizationComponent::Init() {

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

  AINFO << "Gflags set";
  
  publisher_.reset(new LocalizationMsgPublisher(this->node_));

  if (!InitConfig()) {
    AERROR << "Init Config failed.";
    return false;
  }

  if (!InitIO()) {
    AERROR << "Init IO failed.";
    return false;
  }

  return true;
}

bool MSFLocalizationComponent::InitConfig() {
  lidar_topic_ = FLAGS_lidar_topic;
  bestgnsspos_topic_ = FLAGS_gnss_best_pose_topic;
  gnss_heading_topic_ = FLAGS_heading_topic;

  if (!publisher_->InitConfig()) {
    AERROR << "Init publisher config failed.";
    return false;
  }

  if (!localization_.Init().ok()) {
    AERROR << "Init class MSFLocalization failed.";
    return false;
  }

  return true;
}

bool MSFLocalizationComponent::InitIO() {
  cyber::ReaderConfig reader_config;
  reader_config.channel_name = lidar_topic_;
  reader_config.pending_queue_size = 1;

  std::function<void(const std::shared_ptr<drivers::PointCloud>&)>
      lidar_register_call = std::bind(&MSFLocalization::OnPointCloud,
                                      &localization_, std::placeholders::_1);

  lidar_listener_ = this->node_->CreateReader<drivers::PointCloud>(
      reader_config, lidar_register_call);

  std::function<void(const std::shared_ptr<drivers::gnss::GnssBestPose>&)>
      bestgnsspos_register_call =
          std::bind(&MSFLocalization::OnGnssBestPose, &localization_,
                    std::placeholders::_1);
  bestgnsspos_listener_ =
      this->node_->CreateReader<drivers::gnss::GnssBestPose>(
          bestgnsspos_topic_, bestgnsspos_register_call);

  std::function<void(const std::shared_ptr<drivers::gnss::Heading>&)>
      gnss_heading_call = std::bind(&MSFLocalization::OnGnssHeading,
                                    &localization_, std::placeholders::_1);
  gnss_heading_listener_ = this->node_->CreateReader<drivers::gnss::Heading>(
      gnss_heading_topic_, gnss_heading_call);
      
  dag_reader_ = node_->CreateReader<drivers::gnss::Imu>("/apollo/sensor/gnss/imu", std::bind(&MSFLocalizationComponent::Proc, this, std::placeholders::_1));

  // init writer
  if (!publisher_->InitIO()) {
    AERROR << "Init publisher io failed.";
    return false;
  }

  localization_.SetPublisher(publisher_);

  return true;
}

bool MSFLocalizationComponent::Proc(
    const std::shared_ptr<drivers::gnss::Imu>& imu_msg) {
  localization_.OnRawImuCache(imu_msg);
  return true;
}

LocalizationMsgPublisher::LocalizationMsgPublisher(
    cyber::ComponentBase *node) {node_=node; tf2_broadcaster_.reset(new apollo::transform::TransformBroadcaster(node));}

bool LocalizationMsgPublisher::InitConfig() {
  localization_topic_ = FLAGS_localization_topic;
  broadcast_tf_frame_id_ = FLAGS_broadcast_tf_frame_id;
  broadcast_tf_child_frame_id_ = FLAGS_broadcast_tf_child_frame_id;
  lidar_local_topic_ = FLAGS_localization_lidar_topic;
  gnss_local_topic_ = FLAGS_localization_gnss_topic;
  localization_status_topic_ = FLAGS_localization_msf_status;

  return true;
}

bool LocalizationMsgPublisher::InitIO() {
  localization_talker_ =
      node_->CreateWriter<LocalizationEstimate>(localization_topic_);

  lidar_local_talker_ =
      node_->CreateWriter<LocalizationEstimate>(lidar_local_topic_);

  gnss_local_talker_ =
      node_->CreateWriter<LocalizationEstimate>(gnss_local_topic_);

  localization_status_talker_ =
      node_->CreateWriter<LocalizationStatus>(localization_status_topic_);
  return true;
}

void LocalizationMsgPublisher::PublishPoseBroadcastTF(
    const LocalizationEstimate& localization) {
  // broadcast tf message
  apollo::transform::TransformStamped tf2_msg;

  auto mutable_head = &tf2_msg.header;
  mutable_head->stamp.sec=localization.measurementtime;
  mutable_head->frame_id=broadcast_tf_frame_id_;
  tf2_msg.child_frame_id=broadcast_tf_child_frame_id_;

  auto mutable_translation = &tf2_msg.transform.translation;
  mutable_translation->x=localization.pose.position.x;
  mutable_translation->y=localization.pose.position.y;
  mutable_translation->z=localization.pose.position.z;

  auto mutable_rotation = &tf2_msg.transform.rotation;
  mutable_rotation->x=localization.pose.orientation.qx;
  mutable_rotation->y=localization.pose.orientation.qy;
  mutable_rotation->z=localization.pose.orientation.qz;
  mutable_rotation->w=localization.pose.orientation.qw;

  tf2_broadcaster_->SendTransform(tf2_msg);
}

void LocalizationMsgPublisher::PublishPoseBroadcastTopic(
    const LocalizationEstimate& localization) {
  double cur_system_time = localization.apolloheader.timestampsec;
  if (pre_system_time_ > 0.0 && cur_system_time - pre_system_time_ > 0.02) {
    AERROR << std::setprecision(16)
           << "the localization processing time enlonged more than 2 times "
              "according to system time, "
           << "the pre system time and current system time: "
           << pre_system_time_ << " " << cur_system_time;
  } else if (pre_system_time_ > 0.0 &&
             cur_system_time - pre_system_time_ < 0.0) {
    AERROR << std::setprecision(16)
           << "published localization message's time is eary than last imu "
              "message "
              "according to system time, "
           << "the pre system time and current system time: "
           << pre_system_time_ << " " << cur_system_time;
  }
  pre_system_time_ = cur_system_time;
  localization_talker_->Write(localization);
}

void LocalizationMsgPublisher::PublishLocalizationMsfGnss(
    const LocalizationEstimate& localization) {
  gnss_local_talker_->Write(localization);
}

void LocalizationMsgPublisher::PublishLocalizationMsfLidar(
    const LocalizationEstimate& localization) {
  lidar_local_talker_->Write(localization);
}

void LocalizationMsgPublisher::PublishLocalizationStatus(
    const LocalizationStatus& localization_status) {
  localization_status_talker_->Write(localization_status);
}

}  // namespace localization
}  // namespace apollo

CYBER_REGISTER_COMPONENT(MSFLocalizationComponent);
