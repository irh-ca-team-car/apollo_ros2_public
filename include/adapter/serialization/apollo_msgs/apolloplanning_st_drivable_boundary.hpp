#pragma once
#include "apollo_msgs/msg/apolloplanning_st_drivable_boundary.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_st_drivable_boundary_instance.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSTDrivableBoundary &msg) ;
    ApolloplanningSTDrivableBoundary from_json_ApolloplanningSTDrivableBoundary (nlohmann::json obj) ;
    template <>
    ApolloplanningSTDrivableBoundary from_json<ApolloplanningSTDrivableBoundary>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSTDrivableBoundary &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSTDrivableBoundary & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSTDrivableBoundary & dt);
}
