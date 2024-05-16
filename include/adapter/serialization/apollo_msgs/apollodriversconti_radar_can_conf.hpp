#pragma once
#include "apollo_msgs/msg/apollodriversconti_radar_can_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriverscanbus_can_card_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscontiRadarCanConf &msg) ;
    ApollodriverscontiRadarCanConf from_json_ApollodriverscontiRadarCanConf (nlohmann::json obj) ;
    template <>
    ApollodriverscontiRadarCanConf from_json<ApollodriverscontiRadarCanConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscontiRadarCanConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriverscontiRadarCanConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscontiRadarCanConf & dt);
}
