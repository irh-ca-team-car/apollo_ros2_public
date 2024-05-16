#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_auto_tuning_training_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_cost_components.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalAutoTuningTrainingData &msg) ;
    ApolloplanningInternalAutoTuningTrainingData from_json_ApolloplanningInternalAutoTuningTrainingData (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalAutoTuningTrainingData from_json<ApolloplanningInternalAutoTuningTrainingData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalAutoTuningTrainingData &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalAutoTuningTrainingData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalAutoTuningTrainingData & dt);
}
