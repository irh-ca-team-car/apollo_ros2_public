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

#include "modules/prediction/container/container_manager.h"

#include "modules/prediction/container/adc_trajectory/adc_trajectory_container.h"
#include "modules/prediction/container/obstacles/obstacles_container.h"
#include "modules/prediction/container/pose/pose_container.h"
#include "modules/prediction/container/storytelling/storytelling_container.h"

namespace apollo
{
    namespace prediction
    {

        using apollo::common::adapter::AdapterManagerConfig;

        void ContainerManager::Init(const AdapterManagerConfig &config)
        {
            config_=(config);
            RegisterContainers();
        }

        void ContainerManager::RegisterContainers()
        {
            for (const auto &adapter_config : config_.config)
            {
                if (adapter_config.type != 0 &&
                    (adapter_config.mode == apollo::common::adapter::AdapterConfig::RECEIVE_ONLY ||
                     adapter_config.mode == apollo::common::adapter::AdapterConfig::DUPLEX))
                {
                    RegisterContainer((apollo::common::adapter::AdapterConfig::MessageType)adapter_config.type);
                }
            }
        }

        std::unique_ptr<Container> ContainerManager::CreateContainer(
            const apollo::common::adapter::AdapterConfig::MessageType &type)
        {
            std::unique_ptr<Container> container_ptr(nullptr);
            if (type == apollo::common::adapter::AdapterConfig::PERCEPTION_OBSTACLES)
            {
                container_ptr.reset(new ObstaclesContainer());
            }
            else if (type == apollo::common::adapter::AdapterConfig::LOCALIZATION)
            {
                container_ptr.reset(new PoseContainer());
            }
            else if (type == apollo::common::adapter::AdapterConfig::PLANNING_TRAJECTORY)
            {
                container_ptr.reset(new ADCTrajectoryContainer());
            }
            else if (type == apollo::common::adapter::AdapterConfig::STORYTELLING)
            {
                container_ptr.reset(new StoryTellingContainer());
            }
            return container_ptr;
        }

        void ContainerManager::RegisterContainer(
            const apollo::common::adapter::AdapterConfig::MessageType &type)
        {
            containers_[static_cast<int>(type)] = CreateContainer(type);
            AINFO << "Container [" << type << "] is registered.";
        }

    } // namespace prediction
} // namespace apollo
