#pragma once
#include "apollo_msgs/msg/apolloplanning_planning_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_bare_intersection_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_change_lane_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_creep_decider_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_crosswalk_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_destination_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_emergency_stop_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_park_and_go_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_decider_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_pull_over_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_rerouting_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_speed_decider_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_stop_sign_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_yield_sign_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningStatus &msg) ;
    ApolloplanningPlanningStatus from_json_ApolloplanningPlanningStatus (nlohmann::json obj) ;
    template <>
    ApolloplanningPlanningStatus from_json<ApolloplanningPlanningStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningStatus & dt);
}
