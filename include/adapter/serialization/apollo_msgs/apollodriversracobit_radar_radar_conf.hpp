#pragma once
#include "apollo_msgs/msg/apollodriversracobit_radar_radar_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversracobitRadarRadarConf &msg) ;
    ApollodriversracobitRadarRadarConf from_json_ApollodriversracobitRadarRadarConf (nlohmann::json obj) ;
    template <>
    ApollodriversracobitRadarRadarConf from_json<ApollodriversracobitRadarRadarConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversracobitRadarRadarConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversracobitRadarRadarConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversracobitRadarRadarConf & dt);
}
