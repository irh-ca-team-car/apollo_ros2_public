#pragma once
#include "apollo_msgs/msg/apollodriversracobit_radar_can_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriverscanbus_can_card_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversracobitRadarCanConf &msg) ;
    ApollodriversracobitRadarCanConf from_json_ApollodriversracobitRadarCanConf (nlohmann::json obj) ;
    template <>
    ApollodriversracobitRadarCanConf from_json<ApollodriversracobitRadarCanConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversracobitRadarCanConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversracobitRadarCanConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversracobitRadarCanConf & dt);
}
