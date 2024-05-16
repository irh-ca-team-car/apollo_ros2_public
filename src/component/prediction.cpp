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

#include "component/prediction.h"

#include "cyber/common/file.h"
#include "cyber/time/clock.h"
#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/util/message_util.h"

#include "modules/prediction/common/feature_output.h"
#include "modules/prediction/common/junction_analyzer.h"
#include "modules/prediction/common/prediction_gflags.h"
#include "modules/prediction/common/prediction_system_gflags.h"
#include "modules/prediction/common/validation_checker.h"
#include "modules/prediction/evaluator/evaluator_manager.h"
#include "modules/prediction/predictor/predictor_manager.h"
#include "modules/prediction/proto/offline_features.pb.h"
#include "modules/prediction/proto/prediction_conf.pb.h"
#include "modules/prediction/scenario/scenario_manager.h"
#include "modules/prediction/util/data_extraction.h"
#include "adapter/serialization/internal/prediction/submodule_output.h"
#include "adapter/serialization/internal/prediction/adc_trajectory_container.h"

namespace apollo
{
    namespace prediction
    {

        using AdapterConfig = apollo_msgs::msg::ApollocommonadapterAdapterConfig;
        using apollo::cyber::Clock;
        using apollo::perception::PerceptionObstacles;
        using ADCTrajectory = apollo_msgs::msg::ApolloplanningADCTrajectory;

        PredictionComponent::~PredictionComponent() {}

        std::string PredictionComponent::Name() const
        {
            return FLAGS_prediction_module_name;
        }

        void PredictionComponent::OfflineProcessFeatureProtoFile(
            const std::string &features_proto_file_name)
        {
            auto obstacles_container_ptr =
                container_manager_->GetContainer<ObstaclesContainer>(
                    apollo::common::adapter::AdapterConfig::PERCEPTION_OBSTACLES);
            obstacles_container_ptr->Clear();
            Features features;
            apollo::cyber::common::GetProtoFromASCIIFile(features_proto_file_name,
                                                         &features);
            for (const Feature &feature : features.feature)
            {
                obstacles_container_ptr->InsertFeatureProto(feature);
                Obstacle *obstacle_ptr = obstacles_container_ptr->GetObstacle(feature.id);
                evaluator_manager_->EvaluateObstacle(obstacle_ptr, obstacles_container_ptr);
            }
        }

        bool PredictionComponent::Init()
        {
            component_start_time_ = Clock::NowInSeconds();
            apollo::PredictionGFlags(this);

            container_manager_ = std::make_shared<ContainerManager>();
            ACHECK(container_manager_!=nullptr);
            evaluator_manager_.reset(new EvaluatorManager());
            ACHECK(evaluator_manager_!=nullptr);
            predictor_manager_.reset(new PredictorManager());
            ACHECK(predictor_manager_!=nullptr);
            scenario_manager_.reset(new ScenarioManager());
            ACHECK(scenario_manager_!=nullptr);

            PredictionConf prediction_conf;
            auto configFilePath = declare_parameter<std::string>("config_file", "<root>/conf/prediction.json");
            replaceRoot(configFilePath);
            ADEBUG << "Config file is at " << configFilePath;
            apollo::cyber::common::GetProtoFromASCIIFile(configFilePath, &prediction_conf);

            AINFO << "Prediction config file is loaded into: "
                  << prediction_conf;

            if (!MessageProcess::Init(container_manager_.get(), evaluator_manager_.get(),
                                      predictor_manager_.get(), prediction_conf))
            {
                return false;
            }

            planning_reader_ = node_->CreateReader<ADCTrajectory>(
                prediction_conf.topicconf.planningtrajectorytopic, nullptr);

            localization_reader_ =
                node_->CreateReader<localization::LocalizationEstimate>(
                    prediction_conf.topicconf.localizationtopic, nullptr);

            storytelling_reader_ = node_->CreateReader<storytelling::Stories>(
                prediction_conf.topicconf.storytellingtopic, nullptr);

            proc_reader_ = node_->CreateReader<apollo_msgs::msg::ApolloperceptionPerceptionObstacles>(
                "/apollo/perception/obstacles",
                [this](auto ptr)
                {
                    Proc(ptr);
                });

            if (!FLAGS_use_lego)
                prediction_writer_ = node_->CreateWriter<PredictionObstacles>(
                    prediction_conf.topicconf.predictiontopic);
            if (FLAGS_use_lego)
                container_writer_ = node_->CreateWriterJson<SubmoduleOutput>(
                    prediction_conf.topicconf.containertopicname);
            if (FLAGS_use_lego)
                adc_container_writer_ = node_->CreateWriterJson<ADCTrajectoryContainer>(
                    prediction_conf.topicconf.adccontainertopicname);
            if (FLAGS_use_lego)
                perception_obstacles_writer_ = node_->CreateWriter<apollo_msgs::msg::ApolloperceptionPerceptionObstacles>(
                    prediction_conf.topicconf.perceptionobstaclestopicname);

            return true;
        }

        bool PredictionComponent::Proc(const std::shared_ptr<apollo_msgs::msg::ApolloperceptionPerceptionObstacles> &perception_obstacles)
        {
            if (FLAGS_use_lego)
            {
                return ContainerSubmoduleProcess(perception_obstacles);
            }
            return PredictionEndToEndProc(perception_obstacles);
        }

        bool PredictionComponent::ContainerSubmoduleProcess(
            const std::shared_ptr<PerceptionObstacles> &perception_obstacles)
        {
            constexpr static size_t kHistorySize = 10;
            const auto frame_start_time = Clock::Now();
            // Read localization info. and call OnLocalization to update
            // the PoseContainer.
            localization_reader_->Observe();
            auto ptr_localization_msg = localization_reader_->GetLatestObserved();
            if (ptr_localization_msg == nullptr)
            {
                AERROR << "Prediction: cannot receive any localization message.";
                return false;
            }
            MessageProcess::OnLocalization(container_manager_.get(),
                                           *ptr_localization_msg);

            // Read planning info. of last frame and call OnPlanning to update
            // the ADCTrajectoryContainer
            planning_reader_->Observe();
            auto ptr_trajectory_msg = planning_reader_->GetLatestObserved();
            if (ptr_trajectory_msg != nullptr)
            {
                MessageProcess::OnPlanning(container_manager_.get(), *ptr_trajectory_msg);
            }

            // Read storytelling message and call OnStorytelling to update the
            // StoryTellingContainer
            storytelling_reader_->Observe();
            auto ptr_storytelling_msg = storytelling_reader_->GetLatestObserved();
            if (ptr_storytelling_msg != nullptr)
            {
                MessageProcess::OnStoryTelling(container_manager_.get(),
                                               *ptr_storytelling_msg);
            }

            MessageProcess::ContainerProcess(container_manager_, *perception_obstacles,
                                             scenario_manager_.get());

            auto obstacles_container_ptr =
                container_manager_->GetContainer<ObstaclesContainer>(
                    apollo::common::adapter::AdapterConfig::PERCEPTION_OBSTACLES);
            CHECK_NOTNULL(obstacles_container_ptr);

            auto adc_trajectory_container_ptr =
                container_manager_->GetContainer<ADCTrajectoryContainer>(
                    apollo::common::adapter::AdapterConfig::PLANNING_TRAJECTORY);
            CHECK_NOTNULL(adc_trajectory_container_ptr);

            SubmoduleOutput submodule_output =
                obstacles_container_ptr->GetSubmoduleOutput(kHistorySize,
                                                            frame_start_time);
            submodule_output.set_curr_scenario(scenario_manager_->scenario());

            container_writer_->Write(apollo_msgs::msg::to_json(submodule_output));
            adc_container_writer_->Write(apollo_msgs::msg::to_json(*adc_trajectory_container_ptr));
            perception_obstacles_writer_->Write(*perception_obstacles);
            return true;
        }

        bool PredictionComponent::PredictionEndToEndProc(
            const std::shared_ptr<PerceptionObstacles> &perception_obstacles)
        {
            if (FLAGS_prediction_test_mode &&
                (Clock::NowInSeconds() - component_start_time_ >
                 FLAGS_prediction_test_duration))
            {
                ADEBUG << "Prediction finished running in test mode";
            }
            // Update relative map if needed
            if (FLAGS_use_navigation_mode && !PredictionMap::Ready())
            {
                AERROR << "Relative map is empty.";
                return false;
            }

            frame_start_time_ = Clock::NowInSeconds();
            auto end_time1 = std::chrono::system_clock::now();

            // Read localization info. and call OnLocalization to update
            // the PoseContainer.
            localization_reader_->Observe();
            auto ptr_localization_msg = localization_reader_->GetLatestObserved();
            if (ptr_localization_msg == nullptr)
            {
                AERROR << "Prediction: cannot receive any localization message.";
                return false;
            }
            MessageProcess::OnLocalization(container_manager_.get(),
                                           *ptr_localization_msg);
            auto end_time2 = std::chrono::system_clock::now();
            std::chrono::duration<double> diff = end_time2 - end_time1;
            ADEBUG << "Time for updating PoseContainer: " << diff.count() * 1000
                   << " msec.";

            // Read storytelling message and call OnStorytelling to update the
            // StoryTellingContainer
            storytelling_reader_->Observe();
            auto ptr_storytelling_msg = storytelling_reader_->GetLatestObserved();
            if (ptr_storytelling_msg != nullptr)
            {
                MessageProcess::OnStoryTelling(container_manager_.get(),
                                               *ptr_storytelling_msg);
            }

            // Read planning info. of last frame and call OnPlanning to update
            // the ADCTrajectoryContainer
            planning_reader_->Observe();
            auto ptr_trajectory_msg = planning_reader_->GetLatestObserved();
            if (ptr_trajectory_msg != nullptr)
            {
                MessageProcess::OnPlanning(container_manager_.get(), *ptr_trajectory_msg);
            }
            auto end_time3 = std::chrono::system_clock::now();
            diff = end_time3 - end_time2;
            ADEBUG << "Time for updating ADCTrajectoryContainer: " << diff.count() * 1000
                   << " msec.";

            // Get all perception_obstacles of this frame and call OnPerception to
            // process them all.
            auto perception_msg = *perception_obstacles;
            PredictionObstacles prediction_obstacles;
            MessageProcess::OnPerception(
                perception_msg, container_manager_, evaluator_manager_.get(),
                predictor_manager_.get(), scenario_manager_.get(), &prediction_obstacles);
            auto end_time4 = std::chrono::system_clock::now();
            diff = end_time4 - end_time3;
            ADEBUG << "Time for updating PerceptionContainer: " << diff.count() * 1000
                   << " msec.";

            // Postprocess prediction obstacles message
            prediction_obstacles.set__starttimestamp(frame_start_time_);
            prediction_obstacles.set__endtimestamp(Clock::NowInSeconds());
            /*  prediction_obstacles.header.set__lidartimestamp(
                  perception_msg.header.lidartimestamp);
              prediction_obstacles.header.set_camera_timestamp(
                  perception_msg.header().camera_timestamp());
              prediction_obstacles.header->set_radar_timestamp(
                  perception_msg.header().radar_timestamp());*/

            prediction_obstacles.set__perceptionerrorcode(perception_msg.errorcode);
            if (FLAGS_prediction_test_mode)
            {
                for (auto const &prediction_obstacle :
                     prediction_obstacles.predictionobstacle)
                {
                    for (auto const &trajectory : prediction_obstacle.trajectory)
                    {
                        for (auto const &trajectory_point : trajectory.trajectorypoint)
                        {
                            if (!ValidationChecker::ValidTrajectoryPoint(trajectory_point))
                            {
                                AERROR << "Invalid trajectory point ["
                                       << trajectory_point << "]";
                                break;
                            }
                        }
                    }
                }
            }

            auto end_time5 = std::chrono::system_clock::now();
            diff = end_time5 - end_time1;
            ADEBUG << "End to end time elapsed: " << diff.count() * 1000 << " msec.";

            // Publish output
            node_->FillHeader(node_->get_name(), prediction_obstacles);
            prediction_writer_->Write(prediction_obstacles);
            return true;
        }

    } // namespace prediction
} // namespace apollo

CYBER_REGISTER_COMPONENT(PredictionComponent)