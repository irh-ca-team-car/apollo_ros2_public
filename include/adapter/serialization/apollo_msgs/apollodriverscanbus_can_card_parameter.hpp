#pragma once
#include "apollo_msgs/msg/apollodriverscanbus_can_card_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscanbusCANCardParameter &msg) ;
    ApollodriverscanbusCANCardParameter from_json_ApollodriverscanbusCANCardParameter (nlohmann::json obj) ;
    template <>
    ApollodriverscanbusCANCardParameter from_json<ApollodriverscanbusCANCardParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscanbusCANCardParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriverscanbusCANCardParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscanbusCANCardParameter & dt);
}
