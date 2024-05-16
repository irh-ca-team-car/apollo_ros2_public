#pragma once
#include "apollo_msgs/msg/apolloplanning_planning_learning_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_learning_data_frame.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningLearningData &msg) ;
    ApolloplanningPlanningLearningData from_json_ApolloplanningPlanningLearningData (nlohmann::json obj) ;
    template <>
    ApolloplanningPlanningLearningData from_json<ApolloplanningPlanningLearningData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningLearningData &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningLearningData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningLearningData & dt);
}
