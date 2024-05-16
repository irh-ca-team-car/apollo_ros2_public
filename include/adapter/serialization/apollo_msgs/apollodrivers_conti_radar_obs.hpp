#pragma once
#include "apollo_msgs/msg/apollodrivers_conti_radar_obs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversContiRadarObs &msg) ;
    ApollodriversContiRadarObs from_json_ApollodriversContiRadarObs (nlohmann::json obj) ;
    template <>
    ApollodriversContiRadarObs from_json<ApollodriversContiRadarObs>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversContiRadarObs &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversContiRadarObs & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversContiRadarObs & dt);
}
