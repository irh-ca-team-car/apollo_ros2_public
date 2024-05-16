#pragma once
#include "apollo_msgs/msg/apolloplanning_open_space_roi_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceRoiDeciderConfig &msg) ;
    ApolloplanningOpenSpaceRoiDeciderConfig from_json_ApolloplanningOpenSpaceRoiDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningOpenSpaceRoiDeciderConfig from_json<ApolloplanningOpenSpaceRoiDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceRoiDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceRoiDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceRoiDeciderConfig & dt);
}
