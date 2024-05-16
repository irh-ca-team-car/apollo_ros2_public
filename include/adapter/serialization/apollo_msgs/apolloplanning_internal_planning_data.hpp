#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_planning_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollolocalization_localization_estimate.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_chassis.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_routing_response.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_path.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_speed_plan.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_sl_frame_debug.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_signal_light_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_obstacle_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_reference_line_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_dp_poly_graph_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_lattice_st_training.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_map_msg.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_auto_tuning_training_data.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_scenario_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_open_space_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_smoother_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_pull_over_debug.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_hybrid_model_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalPlanningData &msg) ;
    ApolloplanningInternalPlanningData from_json_ApolloplanningInternalPlanningData (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalPlanningData from_json<ApolloplanningInternalPlanningData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalPlanningData &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalPlanningData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalPlanningData & dt);
}
