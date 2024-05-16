#pragma once
#include "apollo_msgs/msg/apolloplanning_adc_trajectory_critical_region.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningADCTrajectoryCriticalRegion &msg) ;
    ApolloplanningADCTrajectoryCriticalRegion from_json_ApolloplanningADCTrajectoryCriticalRegion (nlohmann::json obj) ;
    template <>
    ApolloplanningADCTrajectoryCriticalRegion from_json<ApolloplanningADCTrajectoryCriticalRegion>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningADCTrajectoryCriticalRegion &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningADCTrajectoryCriticalRegion & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningADCTrajectoryCriticalRegion & dt);
}
