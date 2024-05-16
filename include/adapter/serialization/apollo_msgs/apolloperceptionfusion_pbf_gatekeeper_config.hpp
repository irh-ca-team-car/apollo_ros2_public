#pragma once
#include "apollo_msgs/msg/apolloperceptionfusion_pbf_gatekeeper_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionPbfGatekeeperConfig &msg) ;
    ApolloperceptionfusionPbfGatekeeperConfig from_json_ApolloperceptionfusionPbfGatekeeperConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionfusionPbfGatekeeperConfig from_json<ApolloperceptionfusionPbfGatekeeperConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionPbfGatekeeperConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionPbfGatekeeperConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionPbfGatekeeperConfig & dt);
}
