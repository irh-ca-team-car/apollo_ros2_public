#pragma once
#include "apollo_msgs/msg/apollotask_manager_task_manager_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollotask_manager_topic_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotaskManagerTaskManagerConfig &msg) ;
    ApollotaskManagerTaskManagerConfig from_json_ApollotaskManagerTaskManagerConfig (nlohmann::json obj) ;
    template <>
    ApollotaskManagerTaskManagerConfig from_json<ApollotaskManagerTaskManagerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollotaskManagerTaskManagerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollotaskManagerTaskManagerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotaskManagerTaskManagerConfig & dt);
}
