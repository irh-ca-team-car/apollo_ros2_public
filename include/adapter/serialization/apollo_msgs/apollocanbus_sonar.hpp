#pragma once
#include "apollo_msgs/msg/apollocanbus_sonar.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_quaternion.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSonar &msg) ;
    ApollocanbusSonar from_json_ApollocanbusSonar (nlohmann::json obj) ;
    template <>
    ApollocanbusSonar from_json<ApollocanbusSonar>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSonar &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSonar & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSonar & dt);
}
