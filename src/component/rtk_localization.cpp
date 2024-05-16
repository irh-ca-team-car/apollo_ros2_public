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

#include "component/rtk_localization.h"
#include "cyber/cyber.h"
#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/configs/config_gflags.h"

namespace apollo
{
  namespace localization
  {

    bool RTKLocalizationComponent::Init()
    {
      ADEBUG << ">>>InitConfig";
      if (!InitConfig())
      {
        AERROR << "Init Config falseed.";
        return false;
      }
      ADEBUG << "<<<InitConfig";
      ADEBUG << ">>>tf2_broadcaster_.reset";
      tf2_broadcaster_.reset(new apollo::transform::TransformBroadcaster(node_));
      ADEBUG << "<<<tf2_broadcaster_.reset";

      ADEBUG << ">>>InitIO";

      if (!InitIO())
      {
        AERROR << "Init Interval falseed.";
        return false;
      }
      ADEBUG << "<<<InitIO";
      ADEBUG << "RTK activated";
      
      return true;
    }

    bool RTKLocalizationComponent::InitConfig()
    {
      rtk_config::Config rtk_config;
      /* if (!apollo::cyber::common::GetProtoFromFile(config_file_path_,
                                                   &rtk_config)) {
        return false;
      }*/
      ADEBUG << "Rtk localization config:";
#define DUMP(A) AINFO << #A << " = " << A
      rtk_config.localizationtopic = declare_parameter<std::string>("localization_topic", "/apollo/localization/pose");
      DUMP(rtk_config.localizationtopic);
      rtk_config.localizationstatustopic = declare_parameter<std::string>("localization_status_topic", "/apollo/localization/msf_status");
      DUMP(rtk_config.localizationstatustopic);
      rtk_config.imutopic = declare_parameter<std::string>("imu_topic", "/apollo/sensor/gnss/corrected_imu");
      DUMP(rtk_config.imutopic);
      rtk_config.gpstopic = declare_parameter<std::string>("gps_topic", "/apollo/sensor/gnss/odometry");
      DUMP(rtk_config.gpstopic);
      rtk_config.gpsstatustopic = declare_parameter<std::string>("gps_status_topic", "/apollo/sensor/gnss/ins_stat");
      DUMP(rtk_config.gpsstatustopic);
      rtk_config.broadcasttfframeid = declare_parameter<std::string>("broadcast_tf_frame_id", "world");
      DUMP(rtk_config.broadcasttfframeid);
      rtk_config.broadcasttfchildframeid = declare_parameter<std::string>("broadcast_tf_child_frame_id", "localization");
      DUMP(rtk_config.broadcasttfchildframeid);
      rtk_config.imulistmaxsize = declare_parameter<int>("imu_list_max_size", 2048);
      DUMP(rtk_config.imulistmaxsize);
      rtk_config.gpsimutimediffthreshold = declare_parameter<float>("gps_imu_time_diff_threshold", 0.02);
      DUMP(rtk_config.gpsimutimediffthreshold);
      rtk_config.mapoffsetx = declare_parameter<float>("map_offset_x", 0.0);
      rtk_config.mapoffsety = declare_parameter<float>("map_offset_y", 0.0);
      rtk_config.mapoffsetz = declare_parameter<float>("map_offset_z", 0.0);
      apollo::common::gflags::init_common(this);
      apollo::common::gflags::init_common_adapter(this);

      
      localization_topic_ = rtk_config.localizationtopic;
      
      localization_status_topic_ = rtk_config.localizationstatustopic;
      
      imu_topic_ = rtk_config.imutopic;
      
      gps_topic_ = rtk_config.gpstopic;
      
      gps_status_topic_ = rtk_config.gpsstatustopic;
      
      broadcast_tf_frame_id_ = rtk_config.broadcasttfframeid;
      
      broadcast_tf_child_frame_id_ = rtk_config.broadcasttfchildframeid;
      
      ADEBUG << ">>>localization_->InitConfig(rtk_config);";

      localization_->InitConfig(rtk_config);
      
      ADEBUG << "<<<localization_->InitConfig(rtk_config);";
      return true;
    }

    bool RTKLocalizationComponent::InitIO()
    {
      
      corrected_imu_listener_ = node_->CreateReader<localization::CorrectedImu>(
          imu_topic_, std::bind(&RTKLocalization::ImuCallback, localization_.get(),
                                std::placeholders::_1));
      
      ACHECK(corrected_imu_listener_);

      
      gps_status_listener_ = node_->CreateReader<drivers::gnss::InsStat>(
          gps_status_topic_, std::bind(&RTKLocalization::GpsStatusCallback,
                                       localization_.get(), std::placeholders::_1));
      
      ACHECK(gps_status_listener_);

      
      localization_talker_ =
          node_->CreateWriter<LocalizationEstimate>(localization_topic_);
      
      ACHECK(localization_talker_);

      
      localization_status_talker_ =
          node_->CreateWriter<LocalizationStatus>(localization_status_topic_);

      
      dag_reader_ = node_->CreateReader<localization::Gps>("/apollo/sensor/gnss/odometry", std::bind(&RTKLocalizationComponent::Proc, this, std::placeholders::_1));

      
      ACHECK(localization_status_talker_);
      return true;
    }

    bool RTKLocalizationComponent::Proc(
        const std::shared_ptr<localization::Gps> &gps_msg)
    {
      localization_->GpsCallback(gps_msg);
      

      if (localization_->IsServiceStarted())
      {
        
        LocalizationEstimate localization;
        
        localization_->GetLocalization(&localization);
        
        LocalizationStatus localization_status;
        
        localization_->GetLocalizationStatus(&localization_status);

        
        // publish localization messages
        
        PublishPoseBroadcastTopic(localization);
        
        PublishPoseBroadcastTF(localization);
        
        PublishLocalizationStatus(localization_status);
        
        ADEBUG << "[OnTimer]: Localization message publish success!";
      }

      return true;
    }

    void RTKLocalizationComponent::PublishPoseBroadcastTF(
        const LocalizationEstimate &localization)
    {
      // broadcast tf message
      
      apollo::transform::TransformStamped tf2_msg;

      
      auto mutable_head = &tf2_msg.header;
      
      mutable_head->stamp.sec = (int)cyber::Clock::NowInSeconds();
      
      mutable_head->frame_id = broadcast_tf_frame_id_;
      
      tf2_msg.child_frame_id = broadcast_tf_child_frame_id_;

      
      auto mutable_translation = &tf2_msg.transform.translation;
      
      mutable_translation->x = localization.pose.position.x;
      
      mutable_translation->y = localization.pose.position.y;
      
      mutable_translation->z = localization.pose.position.z;

      
      auto mutable_rotation = &tf2_msg.transform.rotation;
      
      mutable_rotation->x = localization.pose.orientation.qx;
      
      mutable_rotation->y = localization.pose.orientation.qy;
      
      mutable_rotation->z = localization.pose.orientation.qz;
      
      mutable_rotation->w = localization.pose.orientation.qw;

      
      tf2_broadcaster_->SendTransform(tf2_msg);
      
    }

    void RTKLocalizationComponent::PublishPoseBroadcastTopic(
        const LocalizationEstimate &localization)
    {
      
      localization_talker_->Write(localization);
    }

    void RTKLocalizationComponent::PublishLocalizationStatus(
        const LocalizationStatus &localization_status)
    {
      
      localization_status_talker_->Write(localization_status);
    }

  } // namespace localization
} // namespace apollo

CYBER_REGISTER_COMPONENT(RTKLocalizationComponent);
