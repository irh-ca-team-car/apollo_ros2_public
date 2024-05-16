#pragma once
#include "apollo_msgs/msg/apollocanbus_interior_lights_rpt416.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusInteriorLightsRpt416 &msg) ;
    ApollocanbusInteriorLightsRpt416 from_json_ApollocanbusInteriorLightsRpt416 (nlohmann::json obj) ;
    template <>
    ApollocanbusInteriorLightsRpt416 from_json<ApollocanbusInteriorLightsRpt416>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusInteriorLightsRpt416 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusInteriorLightsRpt416 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusInteriorLightsRpt416 & dt);
}
