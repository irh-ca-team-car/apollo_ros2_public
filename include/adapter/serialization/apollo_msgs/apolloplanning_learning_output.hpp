#pragma once
#include "apollo_msgs/msg/apolloplanning_learning_output.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_trajectory_point_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLearningOutput &msg) ;
    ApolloplanningLearningOutput from_json_ApolloplanningLearningOutput (nlohmann::json obj) ;
    template <>
    ApolloplanningLearningOutput from_json<ApolloplanningLearningOutput>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLearningOutput &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLearningOutput & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLearningOutput & dt);
}
