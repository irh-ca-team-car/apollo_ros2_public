#pragma once
#include "apollo_msgs/msg/apolloplanning_task_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_task_configtask_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTaskConfig &msg) ;
    ApolloplanningTaskConfig from_json_ApolloplanningTaskConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningTaskConfig from_json<ApolloplanningTaskConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTaskConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTaskConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTaskConfig & dt);
}
