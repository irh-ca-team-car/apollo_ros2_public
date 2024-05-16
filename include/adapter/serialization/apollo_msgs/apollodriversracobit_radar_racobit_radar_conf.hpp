#pragma once
#include "apollo_msgs/msg/apollodriversracobit_radar_racobit_radar_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriversracobit_radar_can_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversracobit_radar_radar_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversracobitRadarRacobitRadarConf &msg) ;
    ApollodriversracobitRadarRacobitRadarConf from_json_ApollodriversracobitRadarRacobitRadarConf (nlohmann::json obj) ;
    template <>
    ApollodriversracobitRadarRacobitRadarConf from_json<ApollodriversracobitRadarRacobitRadarConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversracobitRadarRacobitRadarConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversracobitRadarRacobitRadarConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversracobitRadarRacobitRadarConf & dt);
}
