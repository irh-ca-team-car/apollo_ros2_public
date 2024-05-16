#pragma once
#include "apollo_msgs/msg/apollodriverssmartereyeconfig_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverssmartereyeconfigConfig &msg) ;
    ApollodriverssmartereyeconfigConfig from_json_ApollodriverssmartereyeconfigConfig (nlohmann::json obj) ;
    template <>
    ApollodriverssmartereyeconfigConfig from_json<ApollodriverssmartereyeconfigConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverssmartereyeconfigConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriverssmartereyeconfigConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverssmartereyeconfigConfig & dt);
}
