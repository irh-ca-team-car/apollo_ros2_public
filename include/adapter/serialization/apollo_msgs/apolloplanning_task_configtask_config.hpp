#pragma once
#include "apollo_msgs/msg/apolloplanning_task_configtask_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_creep_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_lane_change_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_fall_back_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_pre_stop_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_roi_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_bounds_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_lane_borrow_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_reference_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_path_reuse_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_rule_based_stop_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_speed_bounds_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_st_bounds_decider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_trajectory_partition_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_trajectory_provider_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_nonlinear_speed_optimizer_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_path_optimizer_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_speed_optimizer_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_speed_heuristic_optimizer_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_learning_model_inference_task_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_learning_model_inference_trajectory_task_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTaskConfigtaskConfig &msg) ;
    ApolloplanningTaskConfigtaskConfig from_json_ApolloplanningTaskConfigtaskConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningTaskConfigtaskConfig from_json<ApolloplanningTaskConfigtaskConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTaskConfigtaskConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTaskConfigtaskConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTaskConfigtaskConfig & dt);
}
