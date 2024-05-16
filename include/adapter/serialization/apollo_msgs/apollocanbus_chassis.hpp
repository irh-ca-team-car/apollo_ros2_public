#pragma once
#include "apollo_msgs/msg/apollocanbus_chassis.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_signal.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_chassis_gps.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_engage_advice.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wheel_speed.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_surround.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_license.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_id.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusChassis &msg) ;
    ApollocanbusChassis from_json_ApollocanbusChassis (nlohmann::json obj) ;
    template <>
    ApollocanbusChassis from_json<ApollocanbusChassis>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusChassis &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusChassis & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusChassis & dt);
}
