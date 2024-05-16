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
#include "modules/drivers/gnss/proto/imu.pb.h"
#include "sensor_msgs/msg/imu.hpp"
#include "modules/localization/proto/imu.pb.h"
namespace apollo
{
  namespace drivers
  {
    namespace adapter
    {
      using apollo::cyber::Component;
      using apollo::cyber::Reader;
      using apollo::cyber::Writer;

      class IMUAdapterComponent : public Component
      {
      public:
        IMUAdapterComponent() : Component("IMUAdapterComponent") {}
        bool Init() override;

      private:
        void Proc(const std::shared_ptr<sensor_msgs::msg::Imu> msg);

        std::shared_ptr<Reader<sensor_msgs::msg::Imu>> reader_ = nullptr;
        std::shared_ptr<Writer<apollo::drivers::gnss::Imu>> writer_ = nullptr;
        std::shared_ptr<Writer<apollo::localization::CorrectedImu>> writer_c_ = nullptr;
            };

    } // namespace camera
  }   // namespace drivers
} // namespace apollo