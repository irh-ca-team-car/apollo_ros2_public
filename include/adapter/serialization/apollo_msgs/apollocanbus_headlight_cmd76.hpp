#pragma once
#include "apollo_msgs/msg/apollocanbus_headlight_cmd76.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHeadlightCmd76 &msg) ;
    ApollocanbusHeadlightCmd76 from_json_ApollocanbusHeadlightCmd76 (nlohmann::json obj) ;
    template <>
    ApollocanbusHeadlightCmd76 from_json<ApollocanbusHeadlightCmd76>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHeadlightCmd76 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHeadlightCmd76 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHeadlightCmd76 & dt);
}
