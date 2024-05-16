#pragma once
#include "apollo_msgs/msg/apollotask_manager_cycle_routing_task.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_routing_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotaskManagerCycleRoutingTask &msg) ;
    ApollotaskManagerCycleRoutingTask from_json_ApollotaskManagerCycleRoutingTask (nlohmann::json obj) ;
    template <>
    ApollotaskManagerCycleRoutingTask from_json<ApollotaskManagerCycleRoutingTask>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollotaskManagerCycleRoutingTask &dt);
    std::ostream & operator<<(std::ostream & os, const ApollotaskManagerCycleRoutingTask & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotaskManagerCycleRoutingTask & dt);
}
