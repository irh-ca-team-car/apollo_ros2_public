#pragma once
#include "apollo_msgs/msg/apollodriversultrasonic_radar_ultrasonic_radar_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriversultrasonic_radar_can_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversultrasonicRadarUltrasonicRadarConf &msg) ;
    ApollodriversultrasonicRadarUltrasonicRadarConf from_json_ApollodriversultrasonicRadarUltrasonicRadarConf (nlohmann::json obj) ;
    template <>
    ApollodriversultrasonicRadarUltrasonicRadarConf from_json<ApollodriversultrasonicRadarUltrasonicRadarConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversultrasonicRadarUltrasonicRadarConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversultrasonicRadarUltrasonicRadarConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversultrasonicRadarUltrasonicRadarConf & dt);
}
