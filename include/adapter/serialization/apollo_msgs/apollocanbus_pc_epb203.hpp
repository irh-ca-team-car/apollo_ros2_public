#pragma once
#include "apollo_msgs/msg/apollocanbus_pc_epb203.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPcEpb203 &msg) ;
    ApollocanbusPcEpb203 from_json_ApollocanbusPcEpb203 (nlohmann::json obj) ;
    template <>
    ApollocanbusPcEpb203 from_json<ApollocanbusPcEpb203>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPcEpb203 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPcEpb203 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPcEpb203 & dt);
}
