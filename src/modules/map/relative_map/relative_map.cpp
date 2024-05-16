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

#include "modules/map/relative_map/relative_map.h"
// #include "modules/common/monitor_log/monitor_log_buffer.h"
#include "cyber/cyber.h"
#include "modules/common/math/vec2d.h"
#include "modules/common/util/util.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/map/relative_map/common/relative_map_gflags.h"
#include "modules/common/adapters/adapter_gflags.h"

namespace apollo
{
  namespace relative_map
  {

    using apollo::common::ErrorCode;
    using apollo::common::Status;
    using apollo::common::VehicleStateProvider;
    using apollo_msgs::msg::ApollocanbusChassis;
    // using apollo_msgs::msg::ApollocommonmonitorMonitorMessageItem;
    using apollo_msgs::msg::ApollolocalizationLocalizationEstimate;

    using apollo_msgs::msg::ApolloperceptionPerceptionObstacles;

    RelativeMap::RelativeMap()
        : //  monitor_logger_buffer_(apollo::common::monitor::MonitorMessageItem::RELATIVE_MAP),

          vehicle_state_provider_(nullptr)
    {
    }

    Status RelativeMap::Init(common::VehicleStateProvider *vehicle_state_provider)
    {
      vehicle_state_provider_ = vehicle_state_provider;
      if (!FLAGS_use_navigation_mode)
      {
        AERROR << "FLAGS_use_navigation_mode is false, system is not configured "
                  "for relative map mode";
        return Status(ErrorCode::RELATIVE_MAP_ERROR,
                      "FLAGS_use_navigation_mode is not true.");
      }
      AINFO << "Config";
      config_ = apollo_msgs::msg::ApollorelativeMapRelativeMapConfig();
      auto currentNode = apollo::cyber::currentNode;
      config_.mapparam.defaultleftwidth = currentNode->declare_parameter<double>("default_left_width", 1.875);
      config_.mapparam.defaultrightwidth = currentNode->declare_parameter<double>("default_right_width", 1.875);
      config_.mapparam.defaultspeedlimit = currentNode->declare_parameter<float>("default_speed_limit", 29.06);

      config_.navigationlane.minlanemarkerquality = currentNode->declare_parameter<float>("min_lane_marker_quality", 0.49);

      config_.navigationlane.maxlenfromnavigationline = currentNode->declare_parameter<float>("max_len_from_navigation_line", 250.0);
      config_.navigationlane.minlenfornavigationlane = currentNode->declare_parameter<float>("min_len_for_navigation_lane", 150.0);
      config_.navigationlane.maxlenfornavigationlane = currentNode->declare_parameter<float>("max_len_for_navigation_lane", 250.0);
      config_.navigationlane.rationavigationlanelentospeed = currentNode->declare_parameter<float>("ratio_navigation_lane_len_to_speed", 8.0);
      config_.navigationlane.maxdistancetonavigationline = currentNode->declare_parameter<float>("max_distance_to_navigation_line", 15.0);
      config_.navigationlane.minviewrangetouselanemarker = currentNode->declare_parameter<float>("min_view_range_to_use_lane_marker", 0.5);
      config_.navigationlane.minlanehalfwidth = currentNode->declare_parameter<float>("min_lane_half_width", 1.5);
      config_.navigationlane.maxlanehalfwidth = currentNode->declare_parameter<float>("max_lane_half_width", 2.0);
      config_.navigationlane.lanemarkerweight = currentNode->declare_parameter<float>("lane_marker_weight", 0.1);
      config_.navigationlane.lanesource = currentNode->declare_parameter<int>("lane_source", 2);
      AINFO << "navigation_lane_";
      navigation_lane_.SetConfig(config_.navigationlane);
      AINFO << "SetVehicleStateProvider";
      navigation_lane_.SetVehicleStateProvider(vehicle_state_provider);
      const auto &map_param = config_.mapparam;
      AINFO << "SetDefaultWidth";
      navigation_lane_.SetDefaultWidth(map_param.defaultleftwidth,
                                       map_param.defaultrightwidth);
      AINFO << "Relative map initialized";
      return Status::OK();
    }

    void LogErrorStatus(apollo_msgs::msg::ApollorelativeMapMapMsg *map_msg, const std::string &error_msg)
    {
      map_msg->apolloheader.frameid = error_msg;
    }

    apollo::common::Status RelativeMap::Start()
    {
      // monitor_logger_buffer_.INFO("RelativeMap started");
      AINFO << "Relative map started";
      return Status::OK();
    }

    bool RelativeMap::Process(apollo_msgs::msg::ApollorelativeMapMapMsg *const map_msg)
    {
      {
        return CreateMapFromNavigationLane(map_msg);
      }
      return true;
    }

    void RelativeMap::OnNavigationInfo(apollo_msgs::msg::ApollorelativeMapNavigationInfo::SharedPtr navigation_info)
    {
      {
        navigation_lane_.UpdateNavigationInfo(navigation_info);
      }
    }

    void RelativeMap::OnPerception(apollo_msgs::msg::ApolloperceptionPerceptionObstacles::SharedPtr perception_obstacles)
    {
      {
        perception_obstacles_ = perception_obstacles;
      }
    }

    void RelativeMap::OnChassis(apollo_msgs::msg::ApollocanbusChassis::SharedPtr chassis)
    {
      {
        chassis_ = chassis;
      }
    }

    void RelativeMap::OnLocalization(apollo_msgs::msg::ApollolocalizationLocalizationEstimate::SharedPtr localization)
    {
      {
        localization_ = localization;
      }
    }

    bool RelativeMap::CreateMapFromNavigationLane(apollo_msgs::msg::ApollorelativeMapMapMsg *map_msg)
    {
      CHECK_NOTNULL(map_msg);

      // update vehicle state from localization and chassis
      if (localization_ == nullptr || chassis_ == nullptr)
      {
        if (localization_ == nullptr)
          AWARN_EVERY(10000) << "localization_==nullptr";
        if (chassis_ == nullptr)
          AWARN_EVERY(10000) << "chassis_==nullptr";
        return false;
      }

      apollo_msgs::msg::ApollolocalizationLocalizationEstimate localization = *localization_;
      apollo_msgs::msg::ApollocanbusChassis chassis = *chassis_;

      vehicle_state_provider_->Update(localization, chassis);

      map_msg->localization = *localization_;

      // update navigationlane from perception_obstacles (lane marker)

      if (perception_obstacles_ == nullptr)
      {
        AERROR_EVERY(10000) << "perception_obstacles_==nullptr";
        return false;
      }
      apollo_msgs::msg::ApolloperceptionPerceptionObstacles::SharedPtr perception = perception_obstacles_;
      navigation_lane_.UpdatePerception(perception);

      map_msg->lanemarker = perception_obstacles_->lanemarker;

      AINFO_EVERY(10000) << "navigation_lane_.GeneratePath()";
      //NavigationInfo waypoints are pruned according to the vehicle pose, then, converted to FLU coordinates
      //and merged with perception generated path using config.lanemarkerweight.
      if (!navigation_lane_.GeneratePath())
      {
        // LogErrorStatus(map_msg, "Failed to generate a navigation path.");
        AERROR_EVERY(10000) << "Failed to generate a navigation path.";
        return false;
      }

      if (navigation_lane_.Path().path.pathpoint.size() < 1)
      {
        // LogErrorStatus(map_msg,
        //                "There is no path point in currnet navigation path.");
        AERROR_EVERY(10000) << "There is no path point in currnet navigation path.";
        return false;
      }

      // create map proto from navigation_path containing one road.
      if (!navigation_lane_.CreateMap(config_.mapparam, map_msg))
      {
        // LogErrorStatus(map_msg,
        //                "Failed to create map from current navigation path.");
        AERROR_EVERY(10000) << "Failed to create map from navigation path.";
        return false;
      }

      ADEBUG_EVERY(10000) << "There is/are " << map_msg->navigationpath.size()
             << " navigation path(s) in the current reltative map.";
      return true;
    }

    void RelativeMap::Stop()
    {
      // monitor_logger_buffer_.INFO("RelativeMap stopped");
    }

  } // namespace relative_map
} // namespace apollo