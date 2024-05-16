#pragma once
#include "apollo_msgs/msg/apollocommon_point2_d.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPoint2D &msg) ;
    ApollocommonPoint2D from_json_ApollocommonPoint2D (nlohmann::json obj) ;
    template <>
    ApollocommonPoint2D from_json<ApollocommonPoint2D>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPoint2D &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonPoint2D & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPoint2D & dt);
}
