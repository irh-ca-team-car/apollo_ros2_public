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

/**
 * @file
 **/

#include "modules/planning/scenarios/scenario.h"

#include "cyber/common/file.h"
#include "cyber/common/log.h"
#include "modules/planning/common/frame.h"

namespace apollo
{
  namespace planning
  {
    namespace scenario
    {

      Scenario::Scenario(const apollo_msgs::msg::ApolloplanningScenarioConfig &config, const ScenarioContext *context,
                         const std::shared_ptr<DependencyInjector> &injector)
          : config_(config), scenario_context_(context), injector_(injector)
      {
#ifdef enum_case
#undef enum_case
#endif
#define enum_case(NM)                                      \
  case apollo::planning::ScenarioConfig::ScenarioType::NM: \
  {                                                        \
    name_ = #NM;                                           \
    break;                                                 \
  }
        switch ((apollo::planning::ScenarioConfig::ScenarioType)config.scenariotype)
        {
          enum_case(LANE_FOLLOW); // default scenario

          // intersection involved
          enum_case(BARE_INTERSECTION_UNPROTECTED);
          enum_case(STOP_SIGN_PROTECTED);
          enum_case(STOP_SIGN_UNPROTECTED);
          enum_case(TRAFFIC_LIGHT_PROTECTED);
          enum_case(TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN);
          enum_case(TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN);
          enum_case(YIELD_SIGN);

          // parking
          enum_case(PULL_OVER);
          enum_case(VALET_PARKING);

          enum_case(EMERGENCY_PULL_OVER);
          enum_case(EMERGENCY_STOP);

          // misc
          enum_case(NARROW_STREET_U_TURN);
          enum_case(PARK_AND_GO);

          // learning model sample
          enum_case(LEARNING_MODEL_SAMPLE);
        }
      }

      bool Scenario::LoadConfig(const std::string &config_file,
                                apollo_msgs::msg::ApolloplanningScenarioConfig *config)
      {
        return apollo::cyber::common::GetProtoFromFile(config_file, config);
      }

      void Scenario::Init()
      {
        // set scenario_type in PlanningContext
        auto *scenario = &injector_->planning_context()
                             ->mutable_planning_status()
                             ->scenario;
        *scenario=apollo_msgs::msg::ApolloplanningScenarioStatus();
        scenario->set__scenariotype(scenario_type());

        for (const apollo_msgs::msg::ApolloplanningStageConfig &stage_config : config_.stageconfig)
        {
          stage_config_map_[(apollo::planning::ScenarioConfig::StageType)stage_config.stagetype] = &stage_config;
        }
        for (size_t i = 0; i < config_.stagetype.size(); ++i)
        {
          apollo::planning::ScenarioConfig::StageType stage_type = (apollo::planning::ScenarioConfig::StageType)config_.stagetype.at(i);
          //auto cond=common::util::ContainsKey(stage_config_map_, stage_type);
          bool cond = stage_config_map_.find(stage_type) != stage_config_map_.end();
          ACHECK(cond)
              << "stage type : " << ((apollo::planning::ScenarioConfig::StageType)stage_type)
              << " has no config";
        }
        ADEBUG << "init stage "
               << ((apollo::planning::ScenarioConfig::StageType)config_.stagetype.at(0));
        current_stage_ =
            CreateStage(*stage_config_map_[(apollo::planning::ScenarioConfig::StageType)config_.stagetype.at(0)], injector_);
      }

      Scenario::ScenarioStatus Scenario::Process(
          const common::TrajectoryPoint &planning_init_point, Frame *frame)
      {
        if (current_stage_ == nullptr)
        {
          AWARN << "Current stage is a null pointer.";
          return STATUS_UNKNOWN;
        }
        if (current_stage_->stage_type() == ScenarioConfig::NO_STAGE)
        {
          scenario_status_ = STATUS_DONE;
          return scenario_status_;
        }
        auto ret = current_stage_->Process(planning_init_point, frame);
        switch (ret)
        {
        case Stage::ERROR:
        {
          AERROR << "Stage '" << current_stage_->Name() << "' returns error";
          scenario_status_ = STATUS_UNKNOWN;
          break;
        }
        case Stage::RUNNING:
        {
          scenario_status_ = STATUS_PROCESSING;
          break;
        }
        case Stage::FINISHED:
        {
          auto next_stage = current_stage_->NextStage();
          if (next_stage != current_stage_->stage_type())
          {
            AINFO << "switch stage from " << current_stage_->Name() << " to "
                  << ScenarioConfig::StageType_Name(next_stage);
            if (next_stage == ScenarioConfig::NO_STAGE)
            {
              scenario_status_ = STATUS_DONE;
              return scenario_status_;
            }
            if (stage_config_map_.find(next_stage) == stage_config_map_.end())
            {
              AERROR << "Failed to find config for stage: " << next_stage;
              scenario_status_ = STATUS_UNKNOWN;
              return scenario_status_;
            }
            current_stage_ = CreateStage(*stage_config_map_[next_stage], injector_);
            if (current_stage_ == nullptr)
            {
              AWARN << "Current stage is a null pointer.";
              return STATUS_UNKNOWN;
            }
          }
          if (current_stage_ != nullptr &&
              current_stage_->stage_type() != ScenarioConfig::NO_STAGE)
          {
            scenario_status_ = STATUS_PROCESSING;
          }
          else
          {
            scenario_status_ = STATUS_DONE;
          }
          break;
        }
        default:
        {
          AWARN << "Unexpected Stage return value: " << ret;
          scenario_status_ = STATUS_UNKNOWN;
        }
        }
        return scenario_status_;
      }

      const std::string &Scenario::Name() const { return name_; }

    } // namespace scenario
  }   // namespace planning
} // namespace apollo