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

#include "component/routing.h"

#include <utility>

#include "modules/common/adapters/adapter_gflags.h"
#include "modules/routing/common/routing_gflags.h"

namespace apollo
{
    namespace routing
    {
        bool RoutingComponent::Init()
        {

            INIT_FLAG_string(routing_node_name, "routing", "the name for this node");

            INIT_FLAG_double(min_length_for_lane_change, 1.0,
                             "meters, which is 100 feet.  Minimum distance needs to travel on "
                             "a lane before making a lane change. Recommended by "
                             "https://www.oregonlaws.org/ors/811.375");

            INIT_FLAG_bool(enable_change_lane_in_result, true,
                           "contain change lane operator in result");

            INIT_FLAG_int64(routing_response_history_interval_ms, 1000,
                      "ms, emit routing resposne for this time interval");
            apollo::common::gflags::init_common(this);
            apollo::common::gflags::init_common_adapter(this);

            RoutingConfig routing_conf;
            routing_conf.basespeed = declare_parameter<double>("base_speed", 4.167);
            routing_conf.leftturnpenalty = declare_parameter<double>("left_turn_penalty", 50.0);
            routing_conf.rightturnpenalty = declare_parameter<double>("right_turn_penalty", 20.0);
            routing_conf.uturnpenalty = declare_parameter<double>("uturn_penalty", 100.0);
            routing_conf.changepenalty = declare_parameter<double>("change_penalty", 500.0);
            routing_conf.basechanginglength = declare_parameter<double>("base_changing_length", 50.0);
            routing_conf.topicconfig.routingresponsetopic = declare_parameter<std::string>("topic_config.routing_response_topic", "/apollo/routing_response");
            routing_conf.topicconfig.routingresponsehistorytopic = declare_parameter<std::string>("topic_config.routing_response_history_topic", "/apollo/routing_response_history");

            response_writer_ = node_->CreateWriter<RoutingResponse>(routing_conf.topicconfig.routingresponsetopic);

            response_history_writer_ = node_->CreateWriter<RoutingResponse>(routing_conf.topicconfig.routingresponsehistorytopic);
            std::weak_ptr<RoutingComponent> self =
                std::dynamic_pointer_cast<RoutingComponent>(shared_from_this());

            timer_=(node_->create_wall_timer(std::chrono::milliseconds(FLAGS_routing_response_history_interval_ms),
                    [self, this]() {
                        auto ptr = self.lock();
                        if (ptr)
                        {
                            if (this->response_ != nullptr)
                            {
                                auto timestamp = apollo::cyber::Clock::NowInSeconds();
                                response_->apolloheader.timestampsec=(timestamp);
                                this->response_history_writer_->Write(*response_);
                            }
                        }
                    }));

            proc_reader = CreateReader<RoutingRequest>("/apollo/routing_request",
                                                       std::bind(&RoutingComponent::Proc, this, std::placeholders::_1));

            return routing_.Init()
                       .ok() &&
                   routing_.Start().ok();
        }

        bool RoutingComponent::Proc(const std::shared_ptr<RoutingRequest> &request)
        {
            auto response = std::make_shared<RoutingResponse>();
            if (!routing_.Process(request, response.get()))
            {
                return false;
            }
            node_->FillHeader(node_->get_name(), response.get());
            response_writer_->Write(response);
            {
                response_ = std::move(response);
            }
            return true;
        }

    } // namespace routing
} // namespace apollo

CYBER_REGISTER_COMPONENT(RoutingComponent)