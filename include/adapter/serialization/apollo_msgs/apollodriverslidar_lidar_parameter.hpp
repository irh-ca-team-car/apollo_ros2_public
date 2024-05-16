#pragma once
#include "apollo_msgs/msg/apollodriverslidar_lidar_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverslidarLidarParameter &msg) ;
    ApollodriverslidarLidarParameter from_json_ApollodriverslidarLidarParameter (nlohmann::json obj) ;
    template <>
    ApollodriverslidarLidarParameter from_json<ApollodriverslidarLidarParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverslidarLidarParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriverslidarLidarParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverslidarLidarParameter & dt);
}
