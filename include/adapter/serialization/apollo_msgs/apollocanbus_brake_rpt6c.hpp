#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_rpt6c.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeRpt6c &msg) ;
    ApollocanbusBrakeRpt6c from_json_ApollocanbusBrakeRpt6c (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeRpt6c from_json<ApollocanbusBrakeRpt6c>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeRpt6c &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeRpt6c & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeRpt6c & dt);
}
