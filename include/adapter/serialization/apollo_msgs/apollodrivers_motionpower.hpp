#pragma once
#include "apollo_msgs/msg/apollodrivers_motionpower.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversMotionpower &msg) ;
    ApollodriversMotionpower from_json_ApollodriversMotionpower (nlohmann::json obj) ;
    template <>
    ApollodriversMotionpower from_json<ApollodriversMotionpower>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversMotionpower &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversMotionpower & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversMotionpower & dt);
}
