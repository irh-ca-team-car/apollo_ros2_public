#pragma once
#include "apollo_msgs/msg/apolloplanning_adc_trajectory.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_e_stop.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_path_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_decision_result.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_latency_stats.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_engage_advice.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_rss_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningADCTrajectory &msg) ;
    ApolloplanningADCTrajectory from_json_ApolloplanningADCTrajectory (nlohmann::json obj) ;
    template <>
    ApolloplanningADCTrajectory from_json<ApolloplanningADCTrajectory>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningADCTrajectory &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningADCTrajectory & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningADCTrajectory & dt);
}
