#pragma once
#include "apollo_msgs/msg/apollodrivers_racobit_radar_obs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRacobitRadarObs &msg) ;
    ApollodriversRacobitRadarObs from_json_ApollodriversRacobitRadarObs (nlohmann::json obj) ;
    template <>
    ApollodriversRacobitRadarObs from_json<ApollodriversRacobitRadarObs>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRacobitRadarObs &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversRacobitRadarObs & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRacobitRadarObs & dt);
}
