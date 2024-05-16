#pragma once
#include "apollo_msgs/msg/apolloplanning_hybrid_a_star_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningHybridAStarConfig &msg) ;
    ApolloplanningHybridAStarConfig from_json_ApolloplanningHybridAStarConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningHybridAStarConfig from_json<ApolloplanningHybridAStarConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningHybridAStarConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningHybridAStarConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningHybridAStarConfig & dt);
}
