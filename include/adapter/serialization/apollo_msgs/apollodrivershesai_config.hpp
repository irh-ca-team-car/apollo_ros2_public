#pragma once
#include "apollo_msgs/msg/apollodrivershesai_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodrivershesaiConfig &msg) ;
    ApollodrivershesaiConfig from_json_ApollodrivershesaiConfig (nlohmann::json obj) ;
    template <>
    ApollodrivershesaiConfig from_json<ApollodrivershesaiConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodrivershesaiConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodrivershesaiConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodrivershesaiConfig & dt);
}
