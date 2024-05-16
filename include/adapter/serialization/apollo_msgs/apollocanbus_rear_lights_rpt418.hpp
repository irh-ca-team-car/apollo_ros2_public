#pragma once
#include "apollo_msgs/msg/apollocanbus_rear_lights_rpt418.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusRearLightsRpt418 &msg) ;
    ApollocanbusRearLightsRpt418 from_json_ApollocanbusRearLightsRpt418 (nlohmann::json obj) ;
    template <>
    ApollocanbusRearLightsRpt418 from_json<ApollocanbusRearLightsRpt418>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusRearLightsRpt418 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusRearLightsRpt418 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusRearLightsRpt418 & dt);
}
