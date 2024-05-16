#pragma once
#include "apollo_msgs/msg/apolloplanning_main_mission_complete.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainMissionComplete &msg) ;
    ApolloplanningMainMissionComplete from_json_ApolloplanningMainMissionComplete (nlohmann::json obj) ;
    template <>
    ApolloplanningMainMissionComplete from_json<ApolloplanningMainMissionComplete>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainMissionComplete &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainMissionComplete & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainMissionComplete & dt);
}
