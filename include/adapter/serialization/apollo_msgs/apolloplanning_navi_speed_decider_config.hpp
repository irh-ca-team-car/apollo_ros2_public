#pragma once
#include "apollo_msgs/msg/apolloplanning_navi_speed_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningNaviSpeedDeciderConfig &msg) ;
    ApolloplanningNaviSpeedDeciderConfig from_json_ApolloplanningNaviSpeedDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningNaviSpeedDeciderConfig from_json<ApolloplanningNaviSpeedDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningNaviSpeedDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningNaviSpeedDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningNaviSpeedDeciderConfig & dt);
}
