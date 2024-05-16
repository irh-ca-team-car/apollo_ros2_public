#pragma once
#include "apollo_msgs/msg/apollodrivers_point_cloud.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_point_xyzit.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversPointCloud &msg) ;
    ApollodriversPointCloud from_json_ApollodriversPointCloud (nlohmann::json obj) ;
    template <>
    ApollodriversPointCloud from_json<ApollodriversPointCloud>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversPointCloud &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversPointCloud & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversPointCloud & dt);
}
