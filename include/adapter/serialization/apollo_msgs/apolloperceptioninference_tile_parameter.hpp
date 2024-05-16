#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_tile_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceTileParameter &msg) ;
    ApolloperceptioninferenceTileParameter from_json_ApolloperceptioninferenceTileParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceTileParameter from_json<ApolloperceptioninferenceTileParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceTileParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceTileParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceTileParameter & dt);
}
