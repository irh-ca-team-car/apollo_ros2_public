#pragma once
#include "apollo_msgs/msg/apolloplanning_stage_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_task_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStageConfig &msg) ;
    ApolloplanningStageConfig from_json_ApolloplanningStageConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningStageConfig from_json<ApolloplanningStageConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStageConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStageConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStageConfig & dt);
}
