#pragma once
#include "apollo_msgs/msg/apollodriversultrasonic_radar_can_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriverscanbus_can_card_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversultrasonicRadarCanConf &msg) ;
    ApollodriversultrasonicRadarCanConf from_json_ApollodriversultrasonicRadarCanConf (nlohmann::json obj) ;
    template <>
    ApollodriversultrasonicRadarCanConf from_json<ApollodriversultrasonicRadarCanConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversultrasonicRadarCanConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversultrasonicRadarCanConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversultrasonicRadarCanConf & dt);
}
