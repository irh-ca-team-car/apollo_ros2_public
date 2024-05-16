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
#include "modules/drivers/proto/sensor_image.pb.h"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "image_transport/image_transport.hpp"

namespace apollo
{
  namespace drivers
  {
    namespace camera
    {

      using apollo::cyber::Component;
      using apollo::cyber::Reader;
      using apollo::cyber::Writer;

      class CameraAdapterComponent : public Component
      {
      public:
        CameraAdapterComponent() : Component("CameraAdapterComponent") {}
        bool Init() override;

      private:
        void Proc(const sensor_msgs::msg::Image::ConstSharedPtr & msg);
        int width=1920,height=1080;
        std::shared_ptr<Reader<sensor_msgs::msg::Image>> reader_ = nullptr;
        std::shared_ptr<Writer<apollo::drivers::Image>> writer_ = nullptr;
            };

    } // namespace camera
  }   // namespace drivers
} // namespace apollo