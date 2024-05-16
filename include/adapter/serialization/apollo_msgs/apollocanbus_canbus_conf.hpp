#pragma once
#include "apollo_msgs/msg/apollocanbus_canbus_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apollodriverscanbus_can_card_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusCanbusConf &msg) ;
    ApollocanbusCanbusConf from_json_ApollocanbusCanbusConf (nlohmann::json obj) ;
    template <>
    ApollocanbusCanbusConf from_json<ApollocanbusCanbusConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusCanbusConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusCanbusConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusCanbusConf & dt);
}
