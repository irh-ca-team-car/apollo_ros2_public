#pragma once
#include "apollo_msgs/msg/apollocanbus_door_rpt417.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDoorRpt417 &msg) ;
    ApollocanbusDoorRpt417 from_json_ApollocanbusDoorRpt417 (nlohmann::json obj) ;
    template <>
    ApollocanbusDoorRpt417 from_json<ApollocanbusDoorRpt417>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDoorRpt417 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDoorRpt417 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDoorRpt417 & dt);
}
