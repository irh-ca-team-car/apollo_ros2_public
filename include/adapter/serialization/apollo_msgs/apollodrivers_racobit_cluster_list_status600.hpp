#pragma once
#include "apollo_msgs/msg/apollodrivers_racobit_cluster_list_status600.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRacobitClusterListStatus600 &msg) ;
    ApollodriversRacobitClusterListStatus600 from_json_ApollodriversRacobitClusterListStatus600 (nlohmann::json obj) ;
    template <>
    ApollodriversRacobitClusterListStatus600 from_json<ApollodriversRacobitClusterListStatus600>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRacobitClusterListStatus600 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversRacobitClusterListStatus600 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRacobitClusterListStatus600 & dt);
}
