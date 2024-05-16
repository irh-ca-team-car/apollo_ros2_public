#pragma once
#include "apollo_msgs/msg/apollohdmap_frame_rate.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapFrameRate &msg) ;
    ApollohdmapFrameRate from_json_ApollohdmapFrameRate (nlohmann::json obj) ;
    template <>
    ApollohdmapFrameRate from_json<ApollohdmapFrameRate>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapFrameRate &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapFrameRate & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapFrameRate & dt);
}
