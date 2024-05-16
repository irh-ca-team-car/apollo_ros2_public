#pragma once
#include "apollo_msgs/msg/apollodrivers_racobit_object_list_status60_a.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRacobitObjectListStatus60A &msg) ;
    ApollodriversRacobitObjectListStatus60A from_json_ApollodriversRacobitObjectListStatus60A (nlohmann::json obj) ;
    template <>
    ApollodriversRacobitObjectListStatus60A from_json<ApollodriversRacobitObjectListStatus60A>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRacobitObjectListStatus60A &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversRacobitObjectListStatus60A & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRacobitObjectListStatus60A & dt);
}
