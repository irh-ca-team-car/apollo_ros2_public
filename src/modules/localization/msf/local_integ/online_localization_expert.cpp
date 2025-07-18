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

#include <iomanip>

#include "cyber/cyber.h"
#include "modules/localization/msf/local_integ/online_localization_expert.h"

namespace apollo {
namespace localization {
namespace msf {

bool OnlineLocalizationExpert::Init(const LocalizationIntegParam &param) {
  msf_status_.locallidarconsistency=MSF_LOCAL_LIDAR_CONSISTENCY_03;
  msf_status_.gnssconsistency=MSF_GNSS_CONSISTENCY_03;
  msf_status_.locallidarstatus=MSF_LOCAL_LIDAR_UNDEFINED_STATUS;
  msf_status_.gnsspospositiontype=NONE;
  msf_status_.msfrunningstatus=MSF_RUNNING_INIT;
  msf_status_.locallidarquality=MSF_LOCAL_LIDAR_BAD;

  imu_delay_time_threshold_1_ = param.imu_delay_time_threshold_1;
  imu_delay_time_threshold_2_ = param.imu_delay_time_threshold_2;
  imu_delay_time_threshold_3_ = param.imu_delay_time_threshold_3;

  imu_missing_time_threshold_1_ = param.imu_missing_time_threshold_1;
  imu_missing_time_threshold_2_ = param.imu_missing_time_threshold_2;
  imu_missing_time_threshold_3_ = param.imu_missing_time_threshold_3;

  bestgnsspose_loss_time_threshold_ = param.bestgnsspose_loss_time_threshold;
  lidar_loss_time_threshold_ = param.lidar_loss_time_threshold;

  localization_std_x_threshold_1_ = param.localization_std_x_threshold_1;
  localization_std_y_threshold_1_ = param.localization_std_y_threshold_1;

  localization_std_x_threshold_2_ = param.localization_std_x_threshold_2;
  localization_std_y_threshold_2_ = param.localization_std_y_threshold_2;

  return true;
}

void OnlineLocalizationExpert::AddImu(const ImuData &data) {
  double cur_imu_time = data.measurement_time;
  CheckImuDelayStatus(cur_imu_time);
  CheckImuMissingStatus(cur_imu_time);
  CheckGnssLidarMsfStatus(cur_imu_time);
}

void OnlineLocalizationExpert::AddFusionLocalization(
    const LocalizationEstimate &data) {
  SetLocalizationStatus(data);
}

void OnlineLocalizationExpert::AddLidarLocalization(
    const LocalizationEstimate &data) {
  msf_status_mutex_.lock();
  msf_status_.locallidarstatus=data.msfstatus.locallidarstatus;
  msf_status_.locallidarquality=data.msfstatus.locallidarquality;
  msf_status_mutex_.unlock();
  latest_lidar_timestamp_mutex_.lock();
  latest_lidar_timestamp_ = data.measurementtime;
  latest_lidar_timestamp_mutex_.unlock();
}

void OnlineLocalizationExpert::AddGnssBestPose(
    const drivers::gnss::GnssBestPose &msg, const MeasureData &data) {
  int gnss_solution_status = static_cast<int>(msg.solstatus);
  int gnss_position_type = static_cast<int>(msg.soltype);

  int gnss_status = 0;
  if (gnss_solution_status != 0) {
    gnss_status = 93;
  } else {
    gnss_status = gnss_position_type;
  }

  msf_status_mutex_.lock();
  msf_status_.gnsspospositiontype=
      static_cast<apollo::localization::GnssPositionType>(gnss_status);
  msf_status_mutex_.unlock();

  latest_gnsspos_timestamp_mutex_.lock();
  latest_gnsspos_timestamp_ = data.time;
  latest_gnsspos_timestamp_mutex_.unlock();
}

void OnlineLocalizationExpert::CheckImuDelayStatus(const double &cur_imu_time) {
  sensor_status_.imudelaystatus=apollo::localization::IMU_DELAY_NORMAL;
  double cur_system_time = apollo::cyber::Clock::NowInSeconds();
  double delta_system_time = cur_system_time - cur_imu_time;
  if (delta_system_time > imu_delay_time_threshold_1_) {
    ADEBUG << "the imu delays " << delta_system_time
           << ", the current system time is " << cur_system_time
           << ", the imu timestamp is " << cur_imu_time;
    sensor_status_.imudelaystatus=apollo::localization::IMU_DELAY_3;
  } else if (delta_system_time > imu_delay_time_threshold_2_) {
    ADEBUG << "the imu delays " << delta_system_time
           << ", the current system time is " << cur_system_time
           << ", the imu timestamp is " << cur_imu_time;
    sensor_status_.imudelaystatus=apollo::localization::IMU_DELAY_2;
  } else if (delta_system_time > imu_delay_time_threshold_3_) {
    ADEBUG << "the imu delays " << delta_system_time
           << ", the current system time is " << cur_system_time
           << ", the imu timestamp is " << cur_imu_time;
    sensor_status_.imudelaystatus=apollo::localization::IMU_DELAY_1;
  }
}

void OnlineLocalizationExpert::CheckImuMissingStatus(
    const double &cur_imu_time) {
  sensor_status_.imumissingstatus=
      ImuMsgMissingStatus::IMU_MISSING_NORMAL;
  static double pre_imu_time = cur_imu_time;
  double delta_time = cur_imu_time - pre_imu_time;
  if (delta_time > imu_missing_time_threshold_1_) {
    ADEBUG << "The imu message loss more than 100ms, "
           << "the pre time and current time: " << pre_imu_time << " "
           << cur_imu_time;
    sensor_status_.imumissingstatus=ImuMsgMissingStatus::IMU_MISSING_3;
  } else if (delta_time > imu_missing_time_threshold_2_) {
    ADEBUG << "The imu message loss more than 50ms, "
           << "the pre time and current time: " << pre_imu_time << " "
           << cur_imu_time;
    sensor_status_.imumissingstatus=ImuMsgMissingStatus::IMU_MISSING_2;
  } else if (delta_time > imu_missing_time_threshold_3_) {
    ADEBUG << "The imu message loss more than 10ms, "
           << "the pre time and current time: " << pre_imu_time << " "
           << cur_imu_time;
    sensor_status_.imumissingstatus=ImuMsgMissingStatus::IMU_MISSING_1;
  } else if (delta_time < 0.0) {
    ADEBUG << "Received imu message's time "
           << "is earlier than last imu message,"
           << "the pre time and current time: " << pre_imu_time << " "
           << cur_imu_time;
    sensor_status_.imumissingstatus=
        ImuMsgMissingStatus::IMU_MISSING_ABNORMAL;
  }
  pre_imu_time = cur_imu_time;
}

void OnlineLocalizationExpert::CheckGnssLidarMsfStatus(
    const double &cur_imu_time) {
  latest_gnsspos_timestamp_mutex_.lock();
  if (cur_imu_time - latest_gnsspos_timestamp_ >
      bestgnsspose_loss_time_threshold_) {
    AINFO << "The bestgnsspose msg loses more than 2 seconds: "
          << "imu time and latest gnss time: " << cur_imu_time << " "
          << latest_gnsspos_timestamp_;
    msf_status_.gnsspospositiontype=apollo::localization::MSG_LOSS;
  }
  latest_gnsspos_timestamp_mutex_.unlock();
  latest_lidar_timestamp_mutex_.lock();
  if (cur_imu_time - latest_lidar_timestamp_ > lidar_loss_time_threshold_) {
    AINFO << "The local lidar msg loses more than 2 seconds: "
          << "imu time and latest local lidar time: " << cur_imu_time << " "
          << latest_lidar_timestamp_;
    msf_status_.locallidarstatus=
        LocalLidarStatus::MSF_LOCAL_LIDAR_NO_OUTPUT;
    msf_status_.locallidarquality=LocalLidarQuality::MSF_LOCAL_LIDAR_BAD;
  }
  latest_lidar_timestamp_mutex_.unlock();
}

void OnlineLocalizationExpert::SetLocalizationStatus(
    const LocalizationEstimate &data) {
  apollo::common::Point3D position_std = data.uncertainty.positionstddev;
  if (position_std.x < localization_std_x_threshold_1_ &&
      position_std.y < localization_std_y_threshold_1_) {
    switch (msf_status_.gnsspospositiontype) {
      case apollo::localization::NARROW_INT:
      case apollo::localization::WIDE_INT:
      case apollo::localization::L1_INT:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SOL_LIDAR_GNSS;
          integ_status_.integ_state = LocalizationIntegState::OK;
          integ_status_.state_message = "";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SOL_X_GNSS;
          integ_status_.integ_state = LocalizationIntegState::WARNNING;
          integ_status_.state_message =
              "Warning: Lidar Localization Is Abnormal";
        }
        break;
      case apollo::localization::FLOATCONV:
      case apollo::localization::WIDELANE:
      case apollo::localization::NARROWLANE:
      case apollo::localization::L1_FLOAT:
      case apollo::localization::IONOFREE_FLOAT:
      case apollo::localization::NARROW_FLOAT:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SOL_LIDAR_X;
          integ_status_.integ_state = LocalizationIntegState::WARNNING;
          integ_status_.state_message =
              "Warning: GNSS Localization Is Unstable";
        } else {
          msf_status_.msfrunningstatus=apollo::localization::MSF_SOL_X_X;
          integ_status_.integ_state = LocalizationIntegState::ERROR;
          integ_status_.state_message =
              "ERROR: Both GNSS and Lidar Localization Is Unstable";
        }
        break;
      case apollo::localization::SINGLE:
      case apollo::localization::PSRDIFF:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SOL_LIDAR_XX;
          integ_status_.integ_state = LocalizationIntegState::WARNNING;
          integ_status_.state_message =
              "Warning: GNSS Localization Is Abnormal";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SOL_X_XX;
          integ_status_.integ_state = LocalizationIntegState::ERROR;
          integ_status_.state_message =
              "ERROR: Both GNSS and Lidar Localization Is Abnormal";
        }
        break;
      default:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SOL_LIDAR_XXX;
          integ_status_.integ_state = LocalizationIntegState::WARNNING;
          integ_status_.state_message =
              "WARNNING: GNSS Localization Is Invalid";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SOL_X_XXX;
          integ_status_.integ_state = LocalizationIntegState::ERROR;
          integ_status_.state_message =
              "ERROR: Both GNSS and Lidar Localization Is Invalid";
        }
        break;
    }
  } else if (position_std.x < localization_std_x_threshold_2_ &&
             position_std.y < localization_std_y_threshold_2_) {
    switch (msf_status_.gnsspospositiontype) {
      case apollo::localization::NARROW_INT:
      case apollo::localization::WIDE_INT:
      case apollo::localization::L1_INT:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SSOL_LIDAR_GNSS;
          integ_status_.integ_state = LocalizationIntegState::CRITIAL_ERROR;
          integ_status_.state_message =
              "CRITIAL_ERROR: Current Localization Is Unstable";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SSOL_X_GNSS;
          integ_status_.integ_state = LocalizationIntegState::CRITIAL_ERROR;
          integ_status_.state_message =
              "CRITIAL_ERROR: Current Localization Is Unstable, "
              "Lidar Localization is Abnormal";
        }
        break;
      case apollo::localization::FLOATCONV:
      case apollo::localization::WIDELANE:
      case apollo::localization::NARROWLANE:
      case apollo::localization::L1_FLOAT:
      case apollo::localization::IONOFREE_FLOAT:
      case apollo::localization::NARROW_FLOAT:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SSOL_LIDAR_X;
          integ_status_.integ_state = LocalizationIntegState::CRITIAL_ERROR;
          integ_status_.state_message =
              "CRITIAL_ERROR: Current Localization Is Unstable, "
              "GNSS Localization is Abnormal";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SSOL_X_X;
          integ_status_.integ_state = LocalizationIntegState::CRITIAL_ERROR;
          integ_status_.state_message =
              "CRITIAL_ERROR: Current Localization Is Unstable, "
              "Both GNSS And Lidar Localization Is Abnormal";
        }
        break;
      case apollo::localization::SINGLE:
      case apollo::localization::PSRDIFF:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SSOL_LIDAR_XX;
          integ_status_.integ_state = LocalizationIntegState::CRITIAL_ERROR;
          integ_status_.state_message =
              "CRITIAL_ERROR: Current Localization Is Unstable, "
              "GNSS Localization Is Abnormal";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SSOL_X_XX;
          integ_status_.integ_state = LocalizationIntegState::CRITIAL_ERROR;
          integ_status_.state_message =
              "CRITIAL_ERROR: Current Localization Is Unstable, "
              "Both GNSS And Lidar Localization Is Abnormal";
        }
        break;
      default:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SSOL_LIDAR_XXX;
          integ_status_.integ_state = LocalizationIntegState::CRITIAL_ERROR;
          integ_status_.state_message =
              "CRITIAL_ERROR: Current Localization Is Unstable, "
              "GNSS Localization Is Abnormal";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_SSOL_X_XXX;
          integ_status_.integ_state = LocalizationIntegState::CRITIAL_ERROR;
          integ_status_.state_message =
              "CRITIAL_ERROR: Current Localization Is Unstable, "
              "Both GNSS And Lidar Localization Is Abnormal";
        }
        break;
    }

  } else {
    switch (msf_status_.gnsspospositiontype) {
      case apollo::localization::NARROW_INT:
      case apollo::localization::WIDE_INT:
      case apollo::localization::L1_INT:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_NOSOL_LIDAR_GNSS;
          integ_status_.integ_state = LocalizationIntegState::FATAL_ERROR;
          integ_status_.state_message =
              "FATAL_ERROR: Current Localization Is NOT Available";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_NOSOL_X_GNSS;
          integ_status_.integ_state = LocalizationIntegState::FATAL_ERROR;
          integ_status_.state_message =
              "FATAL_ERROR: Current Localization Is NOT Available, "
              "Lidar Localization Is Abnormal";
        }
        break;
      case apollo::localization::FLOATCONV:
      case apollo::localization::WIDELANE:
      case apollo::localization::NARROWLANE:
      case apollo::localization::L1_FLOAT:
      case apollo::localization::IONOFREE_FLOAT:
      case apollo::localization::NARROW_FLOAT:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_NOSOL_LIDAR_X;
          integ_status_.integ_state = LocalizationIntegState::FATAL_ERROR;
          integ_status_.state_message =
              "FATAL_ERROR: Current Localization Is NOT Available, "
              "GNSS Localization Is Unstable";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_NOSOL_X_X;
          integ_status_.integ_state = LocalizationIntegState::FATAL_ERROR;
          integ_status_.state_message =
              "FATAL_ERROR: Current Localization Is NOT Available, "
              "Both GNSS And Lidar Localization Is Unstable";
        }
        break;
      case apollo::localization::SINGLE:
      case apollo::localization::PSRDIFF:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_NOSOL_LIDAR_XX;
          integ_status_.integ_state = LocalizationIntegState::FATAL_ERROR;
          integ_status_.state_message =
              "FATAL_ERROR: Current Localization Is NOT Available, "
              "GNSS Localization Is Abnormal";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_NOSOL_X_XX;
          integ_status_.integ_state = LocalizationIntegState::FATAL_ERROR;
          integ_status_.state_message =
              "FATAL_ERROR: Current Localization Is NOT Available, "
              "Both GNSS And Lidar Localization Is Abnormal";
        }
        break;
      default:
        if (msf_status_.locallidarstatus ==
            apollo::localization::MSF_LOCAL_LIDAR_NORMAL) {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_NOSOL_LIDAR_XXX;
          integ_status_.integ_state = LocalizationIntegState::FATAL_ERROR;
          integ_status_.state_message =
              "FATAL_ERROR: Current Localization Is NOT Available, "
              "GNSS Localization Is Invalid";
        } else {
          msf_status_.msfrunningstatus=
              apollo::localization::MSF_NOSOL_X_XXX;
          integ_status_.integ_state = LocalizationIntegState::FATAL_ERROR;
          integ_status_.state_message =
              "FATAL_ERROR: Current Localization Is NOT Available, "
              "Both GNSS And Lidar Localization Is Invalid";
        }
        break;
    }
  }
}

void OnlineLocalizationExpert::GetFusionStatus(
    MsfStatus *msf_status, MsfSensorMsgStatus *sensor_status,
    LocalizationIntegStatus *integ_status) {
  {
    std::unique_lock<std::mutex> lock(msf_status_mutex_);
    msf_status->locallidarconsistency=
        msf_status_.locallidarconsistency;
    msf_status->gnssconsistency=msf_status_.gnssconsistency;
    msf_status->locallidarstatus=msf_status_.locallidarstatus;
    msf_status->gnsspospositiontype=msf_status_.gnsspospositiontype;
    msf_status->msfrunningstatus=msf_status_.msfrunningstatus;
    msf_status->locallidarquality=msf_status_.locallidarquality;
  }

  sensor_status->imudelaystatus=sensor_status_.imudelaystatus;
  sensor_status->imumissingstatus=sensor_status_.imumissingstatus;
  sensor_status->imudatastatus=sensor_status_.imudatastatus;

  *integ_status = integ_status_;
}

void OnlineLocalizationExpert::GetGnssStatus(MsfStatus *msf_status) {
  std::unique_lock<std::mutex> lock(msf_status_mutex_);
  msf_status->gnsspospositiontype=msf_status_.gnsspospositiontype;
}

}  // namespace msf
}  // namespace localization
}  // namespace apollo
