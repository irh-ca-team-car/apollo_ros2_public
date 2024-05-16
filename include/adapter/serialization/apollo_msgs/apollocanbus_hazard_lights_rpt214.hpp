#pragma once
#include "apollo_msgs/msg/apollocanbus_hazard_lights_rpt214.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHazardLightsRpt214 &msg) ;
    ApollocanbusHazardLightsRpt214 from_json_ApollocanbusHazardLightsRpt214 (nlohmann::json obj) ;
    template <>
    ApollocanbusHazardLightsRpt214 from_json<ApollocanbusHazardLightsRpt214>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHazardLightsRpt214 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHazardLightsRpt214 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHazardLightsRpt214 & dt);
}
