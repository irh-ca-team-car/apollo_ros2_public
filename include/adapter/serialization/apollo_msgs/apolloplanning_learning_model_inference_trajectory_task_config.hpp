#pragma once
#include "apollo_msgs/msg/apolloplanning_learning_model_inference_trajectory_task_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLearningModelInferenceTrajectoryTaskConfig &msg) ;
    ApolloplanningLearningModelInferenceTrajectoryTaskConfig from_json_ApolloplanningLearningModelInferenceTrajectoryTaskConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningLearningModelInferenceTrajectoryTaskConfig from_json<ApolloplanningLearningModelInferenceTrajectoryTaskConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLearningModelInferenceTrajectoryTaskConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLearningModelInferenceTrajectoryTaskConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLearningModelInferenceTrajectoryTaskConfig & dt);
}
