#pragma once
#include "apollo_msgs/msg/apollodriversconti_radar_conti_radar_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriversconti_radar_can_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversconti_radar_radar_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscontiRadarContiRadarConf &msg) ;
    ApollodriverscontiRadarContiRadarConf from_json_ApollodriverscontiRadarContiRadarConf (nlohmann::json obj) ;
    template <>
    ApollodriverscontiRadarContiRadarConf from_json<ApollodriverscontiRadarContiRadarConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscontiRadarContiRadarConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriverscontiRadarContiRadarConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscontiRadarContiRadarConf & dt);
}
