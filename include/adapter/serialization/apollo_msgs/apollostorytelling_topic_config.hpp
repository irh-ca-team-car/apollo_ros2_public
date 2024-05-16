#pragma once
#include "apollo_msgs/msg/apollostorytelling_topic_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingTopicConfig &msg) ;
    ApollostorytellingTopicConfig from_json_ApollostorytellingTopicConfig (nlohmann::json obj) ;
    template <>
    ApollostorytellingTopicConfig from_json<ApollostorytellingTopicConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingTopicConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingTopicConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingTopicConfig & dt);
}
