#pragma once
#include "apollo_msgs/msg/apollotask_manager_topic_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotaskManagerTopicConfig &msg) ;
    ApollotaskManagerTopicConfig from_json_ApollotaskManagerTopicConfig (nlohmann::json obj) ;
    template <>
    ApollotaskManagerTopicConfig from_json<ApollotaskManagerTopicConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollotaskManagerTopicConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollotaskManagerTopicConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotaskManagerTopicConfig & dt);
}
