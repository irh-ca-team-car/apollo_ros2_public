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

#include "modules/localization/rtk/rtk_localization.h"

#include <limits>

#include "cyber/cyber.h"
#include "modules/common/math/quaternion.h"
#include "modules/common/util/string_util.h"
#include "modules/drivers/gnss/proto/gnss_best_pose.pb.h"

namespace apollo
{
  namespace localization
  {

    using apollo::cyber::Clock;
    using ::Eigen::Vector3d;

    RTKLocalization::RTKLocalization()
        : map_offset_{0.0, 0.0, 0.0},
          monitor_logger_(
              apollo::common::monitor::MonitorMessageItem::LOCALIZATION) {}

    void RTKLocalization::InitConfig(const rtk_config::Config &config)
    {
      
      imu_list_max_size_ = config.imulistmaxsize;
      
      gps_imu_time_diff_threshold_ = config.gpsimutimediffthreshold;
      
      map_offset_[0] = config.mapoffsetx;
      
      map_offset_[1] = config.mapoffsety;
      
      map_offset_[2] = config.mapoffsetz;
      
    }

    void RTKLocalization::GpsCallback(
        const std::shared_ptr<localization::Gps> &gps_msg)
    {
      double time_delay = last_received_timestamp_sec_
                              ? Clock::NowInSeconds() - last_received_timestamp_sec_
                              : last_received_timestamp_sec_;
      
      if (time_delay > gps_time_delay_tolerance_)
      {
        
        std::stringstream ss;
        
        ss << "GPS message time interval: " << time_delay;
        
        AWARN_EVERY(60000)<<(ss.str());
      }

      {
        
        //std::unique_lock<std::mutex> lock(imu_list_mutex_);

        
        if (imu_list_.empty())
        {
          
          AERROR_EVERY(60000) << "IMU message buffer is empty.";
          if (service_started_)
          {
            AERROR_EVERY(60000) <<("IMU message buffer is empty.");
          }
          return;
        }
      }

      {
        
        //std::unique_lock<std::mutex> lock(gps_status_list_mutex_);

        
        if (gps_status_list_.empty())
        {
          
          AERROR_EVERY(60000) << "Gps status message buffer is empty.";
          if (service_started_)
          {
            AERROR_EVERY(60000) <<("Gps status message buffer is empty.");
          }
          return;
        }
      }

      
      // publish localization messages
      
      PrepareLocalizationMsg(*gps_msg, &last_localization_result_,
                             &last_localization_status_result_);
      
      service_started_ = true;
      
      if (service_started_time == 0.0)
      {
        
        service_started_time = Clock::NowInSeconds();
      }

      // watch dog
      
      RunWatchDog(gps_msg->apolloheader.timestampsec);

      
      last_received_timestamp_sec_ = Clock::NowInSeconds();
    }

    void RTKLocalization::GpsStatusCallback(
        const std::shared_ptr<drivers::gnss::InsStat> &status_msg)
    {
        auto empty_imu = std::make_shared<localization::CorrectedImu>();
        empty_imu->apolloheader = status_msg->apolloheader;
        ImuCallback(empty_imu);
      // std::unique_lock<std::mutex> lock(gps_status_list_mutex_);
      
      if (gps_status_list_.size() < gps_status_list_max_size_)
      {
        
        gps_status_list_.push_back(*status_msg);
      }
      else
      {
        
        gps_status_list_.pop_front();
        
        gps_status_list_.push_back(*status_msg);
      }
    }

    void RTKLocalization::ImuCallback(
        const std::shared_ptr<localization::CorrectedImu> &imu_msg)
    {
      // std::unique_lock<std::mutex> lock(imu_list_mutex_);
      if (imu_list_.size() < imu_list_max_size_)
      {
        
        imu_list_.push_back(*imu_msg);
      }
      else
      {
        
        imu_list_.pop_front();
        imu_list_.push_back(*imu_msg);
      }
    }

    bool RTKLocalization::IsServiceStarted() { return service_started_; }

    void RTKLocalization::GetLocalization(LocalizationEstimate *localization)
    {
      
      *localization = last_localization_result_;
    }

    void RTKLocalization::GetLocalizationStatus(
        LocalizationStatus *localization_status)
    {
      
      *localization_status = last_localization_status_result_;
    }

    void RTKLocalization::RunWatchDog(double gps_timestamp)
    {
      
      return;
      if (!enable_watch_dog_)
      {
        return;
      }

      // check GPS time stamp against system time
      double gps_delay_sec = Clock::NowInSeconds() - gps_timestamp;
      double gps_service_delay = Clock::NowInSeconds() - service_started_time;
      int64_t gps_delay_cycle_cnt =
          static_cast<int64_t>(gps_delay_sec * localization_publish_freq_);

      bool msg_delay = false;
      if (gps_delay_cycle_cnt > report_threshold_err_num_ &&
          static_cast<int>(gps_service_delay) > service_delay_threshold)
      {
        msg_delay = true;
        std::stringstream ss;
        ss << "Raw GPS Message Delay. GPS message is " << gps_delay_cycle_cnt
           << " cycle " << gps_delay_sec << " sec behind current time.";
        AERROR <<(ss.str());
      }

      // check IMU time stamp against system time
      //std::unique_lock<std::mutex> lock(imu_list_mutex_);
     
      auto imu_msg = imu_list_.back();
      //lock.unlock();
      double imu_delay_sec =
          Clock::NowInSeconds() - imu_msg.apolloheader.timestampsec;
      int64_t imu_delay_cycle_cnt =
          static_cast<int64_t>(imu_delay_sec * localization_publish_freq_);
      if (imu_delay_cycle_cnt > report_threshold_err_num_ &&
          static_cast<int>(gps_service_delay) > service_delay_threshold)
      {
        msg_delay = true;
        std::stringstream ss;
        ss << "Raw IMU Message Delay. IMU message is " << imu_delay_cycle_cnt
           << " cycle " << imu_delay_sec << " sec behind current time.";
        AERROR <<(ss.str());
      }

      // to prevent it from beeping continuously
      if (msg_delay &&
          (last_reported_timestamp_sec_ < 1. ||
           Clock::NowInSeconds() > last_reported_timestamp_sec_ + 1.))
      {
        AERROR << "gps/imu frame Delay!";
        last_reported_timestamp_sec_ = Clock::NowInSeconds();
      }
    }

    void RTKLocalization::PrepareLocalizationMsg(
        const localization::Gps &gps_msg, LocalizationEstimate *localization,
        LocalizationStatus *localization_status)
    {
      // find the matching gps and imu message
      
      double gps_time_stamp = gps_msg.apolloheader.timestampsec;
      
      CorrectedImu imu_msg;
      
      if (FindMatchingIMU(gps_time_stamp, &imu_msg))
      {
        
        ComposeLocalizationMsg(gps_msg, imu_msg, localization);

        
        drivers::gnss::InsStat gps_status;
        
        if (FindNearestGpsStatus(gps_time_stamp, &gps_status))
        {
          
          FillLocalizationStatusMsg(gps_status, localization_status);
        }
      }
    }

    void RTKLocalization::FillLocalizationMsgHeader(
        LocalizationEstimate *localization)
    {
      
      auto *header = &localization->apolloheader;
      
      double timestamp = apollo::cyber::Clock::NowInSeconds();
      // header->module_name=module_name_;
      
      header->timestampsec = timestamp;
      
      // header->sequence_num=static_cast<unsigned int>(++localization_seq_num_);
    }

    void RTKLocalization::FillLocalizationStatusMsg(
        const drivers::gnss::InsStat &status,
        LocalizationStatus *localization_status)
    {
      
      apollo::common::Header *header = &localization_status->apolloheader;
      
      double timestamp = apollo::cyber::Clock::NowInSeconds();
      
      header->timestampsec = timestamp;
      
      localization_status->measurementtime = status.apolloheader.timestampsec;

      
      if (status.postype == 0)
      {
        localization_status->fusionstatus = MeasureState::ERROR;
        localization_status->statemessage =
            "Error: Current Localization Status Is Missing.";
        return;
      }

      
      auto pos_type = static_cast<drivers::gnss::SolutionType>(status.postype);
      switch (pos_type)
      {
      case drivers::gnss::SolutionType::INS_RTKFIXED:
        
        localization_status->fusionstatus = MeasureState::OK;
        localization_status->statemessage = "";
        break;
      case drivers::gnss::SolutionType::INS_RTKFLOAT:
        
        localization_status->fusionstatus = MeasureState::WARNNING;
        localization_status->statemessage =
            "Warning: Current Localization Is Unstable.";
        break;
      default:
        
        localization_status->fusionstatus = MeasureState::ERROR;
        localization_status->statemessage =
            "Error: Current Localization Is Very Unstable.";
        break;
      }
    }

    void RTKLocalization::ComposeLocalizationMsg(
        const localization::Gps &gps_msg, const localization::CorrectedImu &imu_msg,
        LocalizationEstimate *localization)
    {
      
      *localization = apollo_msgs::msg::ApollolocalizationLocalizationEstimate();

      
      FillLocalizationMsgHeader(localization);

      
      localization->measurementtime = gps_msg.apolloheader.timestampsec;

      // combine gps and imu
      
      auto mutable_pose = &localization->pose;
      if (gps_msg.localization != apollo_msgs::msg::ApollolocalizationPose())
      {
        const auto &pose = gps_msg.localization;

        if (pose.position != apollo_msgs::msg::ApollocommonPointENU())
        {
          // position
          // world frame -> map frame
          mutable_pose->position.x = pose.position.x -
                                     map_offset_[0];
          mutable_pose->position.y = pose.position.y -
                                     map_offset_[1];
          mutable_pose->position.z = pose.position.z -
                                     map_offset_[2];
        }

        // orientation
        if (pose.orientation != apollo_msgs::msg::ApollocommonQuaternion())
        {
          mutable_pose->orientation = pose.orientation;
          double heading = common::math::QuaternionToHeading(
              pose.orientation.qw, pose.orientation.qy,
              pose.orientation.qx, pose.orientation.qz);
          mutable_pose->heading = heading;
        }
        {
          mutable_pose->heading = pose.heading;
        }
        // linear velocity
        if (pose.linearvelocity != apollo_msgs::msg::ApollocommonPoint3D())
        {
          mutable_pose->linearvelocity = pose.linearvelocity;
        }
      }

      
      if (imu_msg.imu != apollo_msgs::msg::ApollolocalizationPose())
      {
        const auto &imu = imu_msg.imu;
        // linear acceleration
        if (imu.linearacceleration != apollo_msgs::msg::ApollocommonPoint3D())
        {
          if (localization->pose.orientation != apollo_msgs::msg::ApollocommonQuaternion())
          {
            // linear_acceleration:
            // convert from vehicle reference to map reference
            Vector3d orig(imu.linearacceleration.x,
                          imu.linearacceleration.y,
                          imu.linearacceleration.z);
            Vector3d vec = common::math::QuaternionRotate(
                localization->pose.orientation, orig);
            mutable_pose->linearacceleration.x = vec[0];
            mutable_pose->linearacceleration.y = vec[1];
            mutable_pose->linearacceleration.z = vec[2];

            // linear_acceleration_vfr
            mutable_pose->linearaccelerationvrf =
                imu.linearacceleration;
          }
          else
          {
            AERROR << "[PrepareLocalizationMsg]: "
                   << "fail to convert linear_acceleration";
          }
        }

        // angular velocity
        
        if (imu.angularvelocity != apollo_msgs::msg::ApollocommonPoint3D())
        {
          if (localization->pose.orientation != apollo_msgs::msg::ApollocommonQuaternion())
          {
            // angular_velocity:
            // convert from vehicle reference to map reference
            Vector3d orig(imu.angularvelocity.x, imu.angularvelocity.y,
                          imu.angularvelocity.z);
            Vector3d vec = common::math::QuaternionRotate(
                localization->pose.orientation, orig);
            mutable_pose->angularvelocity.x = vec[0];
            mutable_pose->angularvelocity.y = vec[1];
            mutable_pose->angularvelocity.z = vec[2];

            // angular_velocity_vf
            mutable_pose->angularvelocityvrf =
                imu.angularvelocity;
          }
          else
          {
            AERROR << "[PrepareLocalizationMsg]: fail to convert angular_velocity";
          }
        }

        // euler angle
        
        if (imu.eulerangles != apollo_msgs::msg::ApollocommonPoint3D())
        {
          mutable_pose->eulerangles = imu.eulerangles;
        }
      }
    }

    bool RTKLocalization::FindMatchingIMU(const double gps_timestamp_sec,
                                          CorrectedImu *imu_msg)
    {
      
      if (imu_msg == nullptr)
      {
        AERROR << "imu_msg should NOT be nullptr.";
        return false;
      }

      
      // std::unique_lock<std::mutex> lock(imu_list_mutex_);
      auto imu_list = imu_list_;
      //lock.unlock();

      if (imu_list.empty())
      {
        AERROR_EVERY(60000) << "Cannot find Matching IMU. "
               << "IMU message Queue is empty! GPS timestamp[" << gps_timestamp_sec
               << "]";
        *imu_msg = CorrectedImu();
        imu_msg->imu.orientation.qw=1;
        return true;
      }

      // scan imu buffer, find first imu message that is newer than the given
      // timestamp
      auto imu_it = imu_list.begin();
      for (; imu_it != imu_list.end(); ++imu_it)
      {
        if ((*imu_it).apolloheader.timestampsec - gps_timestamp_sec >
            std::numeric_limits<double>::min())
        {
          break;
        }
      }

      if (imu_it != imu_list.end())
      { // found one
        if (imu_it == imu_list.begin())
        {
          AERROR_EVERY(60000) << "IMU queue too short or request too old. "
                 << "Oldest timestamp[" << imu_list.front().apolloheader.timestampsec
                 << "], Newest timestamp["
                 << imu_list.back().apolloheader.timestampsec << "], GPS timestamp["
                 << gps_timestamp_sec << "]";
          *imu_msg = imu_list.front(); // the oldest imu
        }
        else
        {
          // here is the normal case
          auto imu_it_1 = imu_it;
          imu_it_1--;
          if ((*imu_it).apolloheader == apollo::common::Header() || (*imu_it_1).apolloheader == apollo::common::Header())
          {
            AERROR << "imu1 and imu_it_1 must both have header.";
            return false;
          }
          if (!InterpolateIMU(*imu_it_1, *imu_it, gps_timestamp_sec, imu_msg))
          {
            AERROR << "failed to interpolate IMU";
            return false;
          }
        }
      }
      else
      {
        
        // give the newest imu, without extrapolation
        *imu_msg = imu_list.back();
        if (imu_msg == nullptr)
        {
          AERROR << "Fail to get latest observed imu_msg.";
          return false;
        }

        /*if (imu_msg->apolloheader == apollo::common::Header())
        {
          AERROR << "imu_msg must have header.";
          return false;
        }*/

        if (std::fabs(imu_msg->apolloheader.timestampsec - gps_timestamp_sec) >
            gps_imu_time_diff_threshold_)
        {
          // 20ms threshold to report error
          AERROR << "Cannot find Matching IMU. IMU messages too old. "
                 << "Newest timestamp[" << imu_list.back().apolloheader.timestampsec
                 << "], GPS timestamp[" << gps_timestamp_sec << "]";
        }
      }
      
      return true;
    }

    bool RTKLocalization::InterpolateIMU(const CorrectedImu &imu1,
                                         const CorrectedImu &imu2,
                                         const double timestamp_sec,
                                         CorrectedImu *imu_msg)
    {
      
      if (!(imu1.apolloheader.timestampsec != 0 &&
            imu2.apolloheader.timestampsec != 0))
      {
        AERROR << "imu1 and imu2 has no header or no timestamp_sec in header";
        return false;
      }
      if (timestamp_sec < imu1.apolloheader.timestampsec)
      {
        AERROR << "[InterpolateIMU1]: the given time stamp["
               << FORMAT_TIMESTAMP(timestamp_sec)
               << "] is older than the 1st message["
               << FORMAT_TIMESTAMP(imu1.apolloheader.timestampsec) << "]";
        *imu_msg = imu1;
      }
      else if (timestamp_sec > imu2.apolloheader.timestampsec)
      {
        AERROR << "[InterpolateIMU2]: the given time stamp[" << timestamp_sec
               << "] is newer than the 2nd message["
               << imu2.apolloheader.timestampsec << "]";
        *imu_msg = imu2;
      }
      else
      {
        *imu_msg = imu1;
        imu_msg->apolloheader.timestampsec = timestamp_sec;

        double time_diff =
            imu2.apolloheader.timestampsec - imu1.apolloheader.timestampsec;
        if (fabs(time_diff) >= 0.001)
        {
          double frac1 =
              (timestamp_sec - imu1.apolloheader.timestampsec) / time_diff;

          if (imu1.imu.angularvelocity != apollo_msgs::msg::ApollocommonPoint3D() &&
              imu2.imu.angularvelocity != apollo_msgs::msg::ApollocommonPoint3D())
          {
            auto val = InterpolateXYZ(imu1.imu.angularvelocity,
                                      imu2.imu.angularvelocity, frac1);
            imu_msg->imu.angularvelocity = val;
          }

          if (imu1.imu.linearacceleration != apollo_msgs::msg::ApollocommonPoint3D() &&
              imu2.imu.linearacceleration != apollo_msgs::msg::ApollocommonPoint3D())
          {
            auto val = InterpolateXYZ(imu1.imu.linearacceleration,
                                      imu2.imu.linearacceleration, frac1);
            imu_msg->imu.linearacceleration = val;
          }

          if (imu1.imu.eulerangles != apollo_msgs::msg::ApollocommonPoint3D() && imu2.imu.eulerangles != apollo_msgs::msg::ApollocommonPoint3D())
          {
            auto val = InterpolateXYZ(imu1.imu.eulerangles,
                                      imu2.imu.eulerangles, frac1);
            imu_msg->imu.eulerangles = val;
          }
        }
      }
      
      return true;
    }

    template <class T>
    T RTKLocalization::InterpolateXYZ(const T &p1, const T &p2,
                                      const double frac1)
    {
      T p;
      double frac2 = 1.0 - frac1;
      if (p1.x != 0 && !std::isnan(p1.x) && p2.x != 0 && !std::isnan(p2.x))
      {
        p.x = p1.x * frac2 + p2.x * frac1;
      }
      if (p1.y != 0 && !std::isnan(p1.y) && p2.y != 0 && !std::isnan(p2.y))
      {
        p.y = p1.y * frac2 + p2.y * frac1;
      }
      if (p1.z != 0 && !std::isnan(p1.z) && p2.z != 0 && !std::isnan(p2.z))
      {
        p.z = p1.z * frac2 + p2.z * frac1;
      }
      return p;
    }

    bool RTKLocalization::FindNearestGpsStatus(const double gps_timestamp_sec,
                                               drivers::gnss::InsStat *status)
    {
      CHECK_NOTNULL(status);

      //std::unique_lock<std::mutex> lock(gps_status_list_mutex_);
      auto gps_status_list = gps_status_list_;
      //lock.unlock();

      double timestamp_diff_sec = 1e8;
      auto nearest_itr = gps_status_list.end();
      for (auto itr = gps_status_list.begin(); itr != gps_status_list.end();
           ++itr)
      {
        double diff = std::abs(itr->apolloheader.timestampsec - gps_timestamp_sec);
        if (diff < timestamp_diff_sec)
        {
          timestamp_diff_sec = diff;
          nearest_itr = itr;
        }
      }

      if (nearest_itr == gps_status_list.end())
      {
        return false;
      }

      if (timestamp_diff_sec > gps_status_time_diff_threshold_)
      {
        return false;
      }

      *status = *nearest_itr;
      return true;
    }

  } // namespace localization
} // namespace apollo
