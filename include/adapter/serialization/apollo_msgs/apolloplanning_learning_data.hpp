#pragma once
#include "apollo_msgs/msg/apolloplanning_learning_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_learning_data_frame.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLearningData &msg) ;
    ApolloplanningLearningData from_json_ApolloplanningLearningData (nlohmann::json obj) ;
    template <>
    ApolloplanningLearningData from_json<ApolloplanningLearningData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLearningData &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLearningData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLearningData & dt);
}
