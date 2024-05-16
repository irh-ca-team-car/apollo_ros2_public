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
#include "modules/drivers/proto/conti_radar.pb.h"
#include "radar_conti_ars408_msgs/msg/object_list.hpp"
#include "radar_conti_ars408_msgs/msg/radar_state.hpp"
#include "radar_conti_ars408_msgs/msg/object_status.hpp"
#include "radar_conti_ars408_msgs/msg/cluster_status.hpp"
namespace apollo
{
  namespace drivers
  {
    namespace adapter
    {
      using apollo::cyber::Component;
      using apollo::cyber::Reader;
      using apollo::cyber::Writer;
      using radar_conti_ars408_msgs::msg::ClusterStatus;
      using radar_conti_ars408_msgs::msg::ObjectList;
      using radar_conti_ars408_msgs::msg::ObjectStatus;
      using radar_conti_ars408_msgs::msg::RadarState;

      class RadarAdapterComponent : public Component
      {
      public:
        RadarAdapterComponent() : Component("RadarAdapterComponent") {}
        bool Init() override;

      private:
        void Proc(const std::shared_ptr<ObjectList> obj_list);
        void ProcState(const std::shared_ptr<RadarState> obj_list);
        apollo::drivers::ContiRadar msg;
        RadarState state;

        std::shared_ptr<Reader<ObjectList>> reader_ = nullptr;
        std::shared_ptr<Reader<RadarState>> reader_state_ = nullptr;
        std::shared_ptr<Reader<ObjectStatus>> reader_object_ = nullptr;
        std::shared_ptr<Reader<ClusterStatus>> reader_cluster_ = nullptr;
        std::shared_ptr<Writer<apollo::drivers::ContiRadar>> writer_ = nullptr;
      };

    } // namespace camera
  }   // namespace drivers
} // namespace apollo