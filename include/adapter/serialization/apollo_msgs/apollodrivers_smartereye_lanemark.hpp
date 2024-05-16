#pragma once
#include "apollo_msgs/msg/apollodrivers_smartereye_lanemark.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_data_packs.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversSmartereyeLanemark &msg) ;
    ApollodriversSmartereyeLanemark from_json_ApollodriversSmartereyeLanemark (nlohmann::json obj) ;
    template <>
    ApollodriversSmartereyeLanemark from_json<ApollodriversSmartereyeLanemark>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversSmartereyeLanemark &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversSmartereyeLanemark & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversSmartereyeLanemark & dt);
}
