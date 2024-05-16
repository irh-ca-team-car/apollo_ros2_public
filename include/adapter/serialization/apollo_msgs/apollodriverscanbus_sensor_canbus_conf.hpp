#pragma once
#include "apollo_msgs/msg/apollodriverscanbus_sensor_canbus_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriverscanbus_can_card_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscanbusSensorCanbusConf &msg) ;
    ApollodriverscanbusSensorCanbusConf from_json_ApollodriverscanbusSensorCanbusConf (nlohmann::json obj) ;
    template <>
    ApollodriverscanbusSensorCanbusConf from_json<ApollodriverscanbusSensorCanbusConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscanbusSensorCanbusConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriverscanbusSensorCanbusConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscanbusSensorCanbusConf & dt);
}
