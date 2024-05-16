#pragma once
#include "apollo_msgs/msg/apollodrivers_point_xyzit.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversPointXYZIT &msg) ;
    ApollodriversPointXYZIT from_json_ApollodriversPointXYZIT (nlohmann::json obj) ;
    template <>
    ApollodriversPointXYZIT from_json<ApollodriversPointXYZIT>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversPointXYZIT &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversPointXYZIT & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversPointXYZIT & dt);
}
