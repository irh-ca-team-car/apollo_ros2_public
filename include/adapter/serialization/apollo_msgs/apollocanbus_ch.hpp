#pragma once
#include "apollo_msgs/msg/apollocanbus_ch.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_command110.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_command111.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steer_command112.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_turnsignal_command113.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear_command114.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_control_command115.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_status510.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_status511.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steer_status512.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_turnsignal_status513.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear_status514.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ecu_status1515.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ecu_status2516.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ecu_status3517.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusCh &msg) ;
    ApollocanbusCh from_json_ApollocanbusCh (nlohmann::json obj) ;
    template <>
    ApollocanbusCh from_json<ApollocanbusCh>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusCh &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusCh & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusCh & dt);
}
