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

#include "component/third_party_perception.h"

#include "modules/common/adapters/adapter_gflags.h"
#include "modules/third_party_perception/proto/third_party_perception_component.pb.h"
#include "modules/perception/factories.h"

namespace apollo
{
  namespace third_party_perception
  {

    bool ThirdPartyPerceptionComponent::Init()
    {
      //InitFactories();
      AINFO << "Flags";
      INIT_FLAG_string(third_party_perception_node_name, "third_party_perception",
                       "Node name");
      AINFO << ".";
      INIT_FLAG_double(third_party_perception_freq, 10,
                    "third party perception timer frequency.");
      AINFO << ".";

      INIT_FLAG_bool(enable_radar, true, "switch to turn on/off radar obstacles");
      AINFO << ".";

      // flags to calibrate mobileye, radar and localization
      INIT_FLAG_double(mobileye_pos_adjust, 3.0,
                    "adjust mobileye objects's position due to distance between "
                    "mobileye and gps.");
      AINFO << ".";

      INIT_FLAG_double(smartereye_pos_adjust, 3.0,
                    "adjust smartereye objects's position due to distance between "
                    "smartereye and gps.");
      AINFO << ".";

      INIT_FLAG_double(
          radar_pos_adjust, 3.0,
          "adjust radar objects's position due to distance between radar and gps.");
      AINFO << ".";

      // object id offset
      INIT_FLAG_int32(mobileye_id_offset, 0, "id offset for mobileye");
      INIT_FLAG_int32(smartereye_id_offset, 0, "id offset for smartereye");
      INIT_FLAG_int32(radar_id_offset, 1000, "id offset for radar");
      AINFO << ".";

      // flags to create fake bounding box
      INIT_FLAG_double(default_car_length, 5.0, "default car length for bounding box.");
      INIT_FLAG_double(default_truck_length, 10.0,
                    "default truck length for bounding box.");
      AINFO << ".";

      INIT_FLAG_double(default_bike_length, 2.0,
                    "default bike length for bounding box.");
      INIT_FLAG_double(default_ped_length, 0.5, "default ped length for bounding box.");
      INIT_FLAG_double(default_unknown_length, 5.0,
      
                    "default unknown length for bounding box.");
      AINFO << ".";

      INIT_FLAG_double(default_car_width, 3.0, "default car width for bounding box.");
      INIT_FLAG_double(default_truck_width, 5.0,
                    "default truck width for bounding box.");
      INIT_FLAG_double(default_bike_width, 1.0, "default bike width for bounding box.");
      INIT_FLAG_double(default_ped_width, 0.5, "default ped width for bounding box.");
      INIT_FLAG_double(default_unknown_width, 3.0,
                    "default unknown width for bounding box.");
      INIT_FLAG_double(default_height, 3.0, "default height for bounding box.");
      AINFO << ".";

      // flags to filter radar obstacles
      INIT_FLAG_double(
          filter_y_distance, 7.5,
          "fiter the radar objects far away from the main vehicle on y-axis.");
      INIT_FLAG_double(movable_speed_threshold, 6.7,
                    "a radar object is considered as moving in a frame "
                    "if its speed > movable_speed_threshold");
      INIT_FLAG_double(
          movable_heading_threshold, 1.5,
          "a radar object is considered as moving in a frame "
          "if the difference between its heading and the main vehicle's heading "
          "< movable_speed_threshold");
      INIT_FLAG_int32(
          movable_frames_count_threshold, 5,
          "a radar object is considered as a movable "
          "if it is moving for consecutive movable_frames_count_threshold frames");
      INIT_FLAG_int32(keep_radar_frames, 5, "number of delphi esr frames to keep");
      AINFO << ".";

      // TODO(QiL) : remove this temporary gflags
      INIT_FLAG_bool(use_conti_radar, true,
                  "use conti or delphi radar, true is conti, false is delphi");

      INIT_FLAG_double(max_mobileye_obstacle_length, 31.2,
                    "maximum mobileye obstacle length");

      INIT_FLAG_double(max_mobileye_obstacle_width, 12.7,
                    "maximum mobileye obstacle length");

      INIT_FLAG_bool(overwrite_mobileye_theta, true,
                  "overrite mobileye raw theta output");
      AINFO << ".";
      
      apollo::common::gflags::init_common_adapter(this);
      AINFO << "|";

      apollo::third_party_perception::ThirdPartyPerceptionDevice
          third_party_perception_param;
      third_party_perception_param.devicetype = ThirdPartyPerceptionDeviceType::MOBILEYE;

      ThirdPartyPerceptionDeviceType device_type = (ThirdPartyPerceptionDeviceType)
                                                       third_party_perception_param.devicetype;

      if (device_type == ThirdPartyPerceptionDeviceType::MOBILEYE)
      {
        AINFO << "ThirdPartyPerceptionDeviceType::MOBILEYE";
        perception_ = std::make_shared<ThirdPartyPerceptionMobileye>(node_);
      }
      else
      {
        perception_ = std::make_shared<ThirdPartyPerception>(node_);
      }
      AINFO << "Init";
      if (!perception_->Init().ok())
      {
        return false;
      }
      AINFO << "writer";
      writer_ = node_->CreateWriter<apollo::perception::PerceptionObstacles>(
          FLAGS_perception_obstacle_topic);
      AINFO << "Start";
      return perception_->Start().ok();
    }

    bool ThirdPartyPerceptionComponent::Proc()
    {
      auto response = std::make_shared<apollo::perception::PerceptionObstacles>();
      if (!perception_->Process(response.get()))
      {
        return false;
      }
      writer_->Write(response);
      return true;
    }

  } // namespace third_party_perception
} // namespace apollo
CYBER_REGISTER_COMPONENT(ThirdPartyPerceptionComponent)
