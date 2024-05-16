#pragma once
#include "apollo_msgs/msg/apolloplanning_st_drivable_boundary_instance.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSTDrivableBoundaryInstance &msg) ;
    ApolloplanningSTDrivableBoundaryInstance from_json_ApolloplanningSTDrivableBoundaryInstance (nlohmann::json obj) ;
    template <>
    ApolloplanningSTDrivableBoundaryInstance from_json<ApolloplanningSTDrivableBoundaryInstance>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSTDrivableBoundaryInstance &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSTDrivableBoundaryInstance & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSTDrivableBoundaryInstance & dt);
}
