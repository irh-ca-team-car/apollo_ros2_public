#pragma once
#include "apollo_msgs/msg/apollorouting_passage.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_lane_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingPassage &msg) ;
    ApolloroutingPassage from_json_ApolloroutingPassage (nlohmann::json obj) ;
    template <>
    ApolloroutingPassage from_json<ApolloroutingPassage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingPassage &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingPassage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingPassage & dt);
}
