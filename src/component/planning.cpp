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
#include "component/planning.h"

#include "cyber/common/file.h"
#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/configs/config_gflags.h"
#include "modules/common/util/message_util.h"
#include "modules/common/util/util.h"
#include "modules/map/hdmap/hdmap_util.h"
#include "modules/map/pnc_map/pnc_map.h"
#include "modules/planning/common/history.h"
#include "modules/planning/common/planning_context.h"
#include "modules/planning/navi_planning.h"
#include "modules/planning/on_lane_planning.h"
#include "adapter/serialization/std_msgs/header.hpp"

typedef apollo::cyber::adapter::Sync<apollo_msgs::msg::ApollocanbusChassis, apollo_msgs::msg::ApollolocalizationLocalizationEstimate> __sync__;

namespace apollo
{
  namespace planning
  {

    using apollo::cyber::ComponentBase;
    using apollo::hdmap::HDMapUtil;
    using apollo::routing::RoutingRequest;
    using apollo::routing::RoutingResponse;
    using apollo::storytelling::Stories;

    bool PlanningComponent::Init()
    {
      injector_ = std::make_shared<DependencyInjector>();
      apollo::common::gflags::init_common(this);
      apollo::common::gflags::init_common_adapter(this);
      apollo::planning::gflags::init_planning(this);

      if (FLAGS_use_navigation_mode)
      {
        AINFO << "Navi planning ...";
        planning_base_ = std::make_unique<NaviPlanning>(injector_);
      }
      else
      {
        AINFO << "On lane planning ...";
        planning_base_ = std::make_unique<OnLanePlanning>(injector_);
      }

      auto configFilePath = declare_parameter<std::string>("config_file", "config.json");

      ACHECK(apollo::cyber::common::GetProtoFromASCIIFile(configFilePath, &config_))
          << "failed to load planning config file "
          << configFilePath;
      if (FLAGS_planning_offline_learning ||
          config_.learningmode != PlanningConfig::NO_LEARNING)
      {
        if (!message_process_.Init(config_, injector_))
        {
          AERROR << "failed to init MessageProcess";
          return false;
        }
      }

      planning_base_->Init(config_);

      routing_reader_ = node_->CreateReader<RoutingResponse>(
          config_.topicconfig.routingresponsetopic,
          [this](const std::shared_ptr<RoutingResponse> &routing)
          {
            AINFO << "Received routing data: run routing callback."
                  << apollo_msgs::msg::to_json(routing->apolloheader).dump();
            routing_ = (*routing);
          });

      traffic_light_reader_ = node_->CreateReader<apollo_msgs::msg::ApolloperceptionTrafficLightDetection>(
          config_.topicconfig.trafficlightdetectiontopic,
          [this](const std::shared_ptr<apollo_msgs::msg::ApolloperceptionTrafficLightDetection> &traffic_light)
          {
            ADEBUG << "Received traffic light data: run traffic light callback.";
            traffic_light_ = (*traffic_light);
          });

      pad_msg_reader_ = node_->CreateReader<PadMessage>(
          config_.topicconfig.planningpadtopic,
          [this](const std::shared_ptr<PadMessage> &pad_msg)
          {
            ADEBUG << "Received pad data: run pad callback.";
            pad_msg_ = (*pad_msg);
          });

      story_telling_reader_ = node_->CreateReader<Stories>(
          config_.topicconfig.storytellingtopic,
          [this](const std::shared_ptr<Stories> &stories)
          {
            ADEBUG << "Received story_telling data: run story_telling callback.";
            stories_ = (*stories);
          });

      if (FLAGS_use_navigation_mode)
      {
        relative_map_reader_ = node_->CreateReader<apollo_msgs::msg::ApollorelativeMapMapMsg>(
            config_.topicconfig.relativemaptopic,
            [this](const std::shared_ptr<apollo_msgs::msg::ApollorelativeMapMapMsg> &map_message)
            {
              ADEBUG << "Received relative map data: run relative map callback.";
              relative_map_ = (*map_message);
            });
      }

      planning_writer_ = node_->CreateWriter<apollo_msgs::msg::ApolloplanningADCTrajectory>(
          config_.topicconfig.planningtrajectorytopic);

      rerouting_writer_ = node_->CreateWriter<RoutingRequest>(
          config_.topicconfig.routingrequesttopic);

      planning_learning_data_writer_ = node_->CreateWriter<PlanningLearningData>(
          config_.topicconfig.planninglearningdatatopic);

      sync_.proc = std::bind(&PlanningComponent::Proc, this, std::placeholders::_1, std::placeholders::_2);
      r0_ = CreateReader<apollo_msgs::msg::ApollocanbusChassis>(FLAGS_chassis_topic, std::bind(&__sync__::callback0, &sync_, std::placeholders::_1));
      r1_ = CreateReader<localization::LocalizationEstimate>(FLAGS_localization_topic, std::bind(&__sync__::callback1, &sync_, std::placeholders::_1));
      
      
      return true;
    }

    bool PlanningComponent::Proc(const std::shared_ptr<apollo_msgs::msg::ApollocanbusChassis> &chassis,
                                 const std::shared_ptr<apollo_msgs::msg::ApollolocalizationLocalizationEstimate> &
                                     localization_estimate)
    {
      //ACHECK(prediction_obstacles != nullptr);

      // check and process possible rerouting request
      CheckRerouting();

      // process fused input data
      //local_view_.prediction_obstacles = prediction_obstacles;
      local_view_.chassis = chassis;
        localization_estimate->pose.heading *= -1;
        localization_estimate->pose.heading += M_PI;
      local_view_.localization_estimate = localization_estimate;
      
      if(!FLAGS_use_navigation_mode){
        if (!local_view_.routing ||
            hdmap::PncMap::IsNewRouting(*local_view_.routing, routing_))
        {
          local_view_.routing =
              std::make_shared<routing::RoutingResponse>(routing_);
        }
      }
      {
          local_view_.traffic_light =
              std::make_shared<apollo_msgs::msg::ApolloperceptionTrafficLightDetection>(traffic_light_);
        local_view_.relative_map = std::make_shared<apollo_msgs::msg::ApollorelativeMapMapMsg>(relative_map_);
      }
      {
        local_view_.pad_msg = std::make_shared<PadMessage>(pad_msg_);
      }
      {
        local_view_.stories = std::make_shared<Stories>(stories_);
      }

      if (!CheckInput())
      {
        AERROR << "Input check failed";
        return false;
      }

      if (config_.learningmode != PlanningConfig::NO_LEARNING)
      {
        // data process for online training
        message_process_.OnChassis(*local_view_.chassis);
        //message_process_.OnPrediction(*local_view_.prediction_obstacles);
        message_process_.OnRoutingResponse(*local_view_.routing);
        message_process_.OnStoryTelling(*local_view_.stories);
        if (local_view_.traffic_light)
          message_process_.OnTrafficLightDetection(*local_view_.traffic_light);
        message_process_.OnLocalization(*local_view_.localization_estimate);
      }

      // publish learning data frame for RL test
      if (config_.learningmode == PlanningConfig::RL_TEST)
      {
        PlanningLearningData planning_learning_data;
        LearningDataFrame *learning_data_frame =
            injector_->learning_based_data()->GetLatestLearningDataFrame();
        if (learning_data_frame)
        {
          planning_learning_data.learningdataframe = (*learning_data_frame);
          FillHeader(node_->get_name(), &planning_learning_data);
          planning_learning_data_writer_->Write(planning_learning_data);
        }
        else
        {
          AERROR << "fail to generate learning data frame";
          return false;
        }
        return true;
      }
      
      apollo_msgs::msg::ApolloplanningADCTrajectory adc_trajectory_pb;
      planning_base_->RunOnce(local_view_, &adc_trajectory_pb);
      FillHeader(node_->get_name(), &adc_trajectory_pb);

      // modify trajectory relative time due to the timestamp change in header
      auto start_time = adc_trajectory_pb.apolloheader.timestampsec;
      const double dt = start_time - adc_trajectory_pb.apolloheader.timestampsec;
      apollo_msgs::msg::ApollolocalizationPose pose = injector_->vehicle_state()->original_pose();
      for (auto &p : adc_trajectory_pb.trajectorypoint)
      {
        p.set__relativetime(p.relativetime + dt);

        double cos_angle = std::cos(pose.heading);
        double sin_angle = std::sin(pose.heading);
        apollo_msgs::msg::ApolloplanningCommonPathPointFeature ppp;
        ppp.x = cos_angle * p.pathpoint.x - sin_angle * p.pathpoint.y + pose.position.x;
        ppp.y = sin_angle * p.pathpoint.x + cos_angle * p.pathpoint.y + pose.position.y;
        
        p.pathpoint.x = (ppp.x);
        p.pathpoint.y = (ppp.y);
      }
      planning_writer_->Write(adc_trajectory_pb);

      // record in history
      auto *history = injector_->history();
      history->Add(adc_trajectory_pb);

      return true;
    }

    void PlanningComponent::CheckRerouting()
    {
      auto *rerouting = &injector_->planning_context()
                             ->mutable_planning_status()
                             ->rerouting;
      if (!rerouting->needrerouting)
      {
        return;
      }
      FillHeader(node_->get_name(), &rerouting->routingrequest);
      rerouting->set__needrerouting(false);
      rerouting_writer_->Write(rerouting->routingrequest);
    }

    bool PlanningComponent::CheckInput()
    {
      apollo_msgs::msg::ApolloplanningADCTrajectory trajectory_pb;
      auto *not_ready = &trajectory_pb.decision.maindecision.task.notready;

      if (local_view_.localization_estimate == nullptr)
      {
        not_ready->set__reason("localization not ready");
      }
      else if (local_view_.chassis == nullptr)
      {
        not_ready->set__reason("chassis not ready");
      }
      else if (HDMapUtil::BaseMapPtr() == nullptr)
      {
        not_ready->set__reason("map not ready");
      }
      else
      {
        // nothing
      }

      if (FLAGS_use_navigation_mode)
      {
        if (local_view_.relative_map->apolloheader == apollo::common::Header())
        {
          not_ready->set__reason("relative map not ready");
        }
      }
      else
      {
        if (local_view_.routing->apolloheader == apollo::common::Header())
        {
          not_ready->set__reason("routing not ready");
        }
      }

      if (not_ready->reason != std::string())
      {
        AERROR << not_ready->reason << "; skip the planning cycle.";
        FillHeader(node_->get_name(), &trajectory_pb);
        planning_writer_->Write(trajectory_pb);
        return false;
      }
      return true;
    }

  } // namespace planning
} // namespace apollo
CYBER_REGISTER_COMPONENT(PlanningComponent)