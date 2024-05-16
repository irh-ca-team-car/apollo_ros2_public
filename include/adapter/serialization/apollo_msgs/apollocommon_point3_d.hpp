#pragma once
#include "apollo_msgs/msg/apollocommon_point3_d.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPoint3D &msg) ;
    ApollocommonPoint3D from_json_ApollocommonPoint3D (nlohmann::json obj) ;
    template <>
    ApollocommonPoint3D from_json<ApollocommonPoint3D>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPoint3D &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonPoint3D & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPoint3D & dt);
}
