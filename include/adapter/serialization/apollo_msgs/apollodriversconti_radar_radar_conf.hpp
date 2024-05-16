#pragma once
#include "apollo_msgs/msg/apollodriversconti_radar_radar_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscontiRadarRadarConf &msg) ;
    ApollodriverscontiRadarRadarConf from_json_ApollodriverscontiRadarRadarConf (nlohmann::json obj) ;
    template <>
    ApollodriverscontiRadarRadarConf from_json<ApollodriverscontiRadarRadarConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscontiRadarRadarConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriverscontiRadarRadarConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscontiRadarRadarConf & dt);
}
