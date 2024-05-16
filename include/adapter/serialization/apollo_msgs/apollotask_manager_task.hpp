#pragma once
#include "apollo_msgs/msg/apollotask_manager_task.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollotask_manager_cycle_routing_task.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotaskManagerTask &msg) ;
    ApollotaskManagerTask from_json_ApollotaskManagerTask (nlohmann::json obj) ;
    template <>
    ApollotaskManagerTask from_json<ApollotaskManagerTask>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollotaskManagerTask &dt);
    std::ostream & operator<<(std::ostream & os, const ApollotaskManagerTask & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotaskManagerTask & dt);
}
