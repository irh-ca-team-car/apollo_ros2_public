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

#pragma once

#include <atomic>
#include <future>
#include <memory>
#include <vector>

#include "cyber/cyber.h"
#include "modules/localization/proto/localization.pb.h"
#include "nav_msgs/msg/odometry.hpp"

namespace apollo
{
  namespace drivers
  {
    namespace adapter
    {

      using apollo::cyber::Component;
      using apollo::cyber::Reader;
      using apollo::cyber::Writer;

      class OdometryAdapterComponent : public Component
      {
      public:
        OdometryAdapterComponent() : Component("OdometryAdapterComponent") {}
        bool Init() override;

      private:
        void Proc(const std::shared_ptr<apollo_msgs::msg::ApollolocalizationLocalizationEstimate> msg);

        std::shared_ptr<Reader<apollo_msgs::msg::ApollolocalizationLocalizationEstimate>> reader_ = nullptr;
        std::shared_ptr<Writer<nav_msgs::msg::Odometry>> writer_ = nullptr;
        std::string world_frame;
      };

    } // namespace camera
  }   // namespace drivers
} // namespace apollo