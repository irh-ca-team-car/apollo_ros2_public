#pragma once
#include "apollo_msgs/msg/apolloplanning_learning_model_inference_task_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLearningModelInferenceTaskConfig &msg) ;
    ApolloplanningLearningModelInferenceTaskConfig from_json_ApolloplanningLearningModelInferenceTaskConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningLearningModelInferenceTaskConfig from_json<ApolloplanningLearningModelInferenceTaskConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLearningModelInferenceTaskConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLearningModelInferenceTaskConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLearningModelInferenceTaskConfig & dt);
}
