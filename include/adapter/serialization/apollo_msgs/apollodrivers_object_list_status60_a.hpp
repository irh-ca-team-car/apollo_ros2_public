#pragma once
#include "apollo_msgs/msg/apollodrivers_object_list_status60_a.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversObjectListStatus60A &msg) ;
    ApollodriversObjectListStatus60A from_json_ApollodriversObjectListStatus60A (nlohmann::json obj) ;
    template <>
    ApollodriversObjectListStatus60A from_json<ApollodriversObjectListStatus60A>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversObjectListStatus60A &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversObjectListStatus60A & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversObjectListStatus60A & dt);
}
