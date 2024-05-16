#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_cmd104.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeCmd104 &msg) ;
    ApollocanbusBrakeCmd104 from_json_ApollocanbusBrakeCmd104 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeCmd104 from_json<ApollocanbusBrakeCmd104>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeCmd104 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeCmd104 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeCmd104 & dt);
}
