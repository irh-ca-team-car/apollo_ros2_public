#pragma once
#include "apollo_msgs/msg/apolloplanning_decision_result.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_main_decision.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_decisions.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_signal.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDecisionResult &msg) ;
    ApolloplanningDecisionResult from_json_ApolloplanningDecisionResult (nlohmann::json obj) ;
    template <>
    ApolloplanningDecisionResult from_json<ApolloplanningDecisionResult>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDecisionResult &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDecisionResult & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDecisionResult & dt);
}
