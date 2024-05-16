#pragma once
#include "apollo_msgs/msg/apollocanbus_pas2nd_data312.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPas2ndData312 &msg) ;
    ApollocanbusPas2ndData312 from_json_ApollocanbusPas2ndData312 (nlohmann::json obj) ;
    template <>
    ApollocanbusPas2ndData312 from_json<ApollocanbusPas2ndData312>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPas2ndData312 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPas2ndData312 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPas2ndData312 & dt);
}
