#pragma once
#include "apollo_msgs/msg/apollocanbus_pc_bcm201.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPcBcm201 &msg) ;
    ApollocanbusPcBcm201 from_json_ApollocanbusPcBcm201 (nlohmann::json obj) ;
    template <>
    ApollocanbusPcBcm201 from_json<ApollocanbusPcBcm201>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPcBcm201 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPcBcm201 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPcBcm201 & dt);
}
