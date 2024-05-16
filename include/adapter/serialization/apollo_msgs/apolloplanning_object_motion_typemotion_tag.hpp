#pragma once
#include "apollo_msgs/msg/apolloplanning_object_motion_typemotion_tag.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectMotionTypemotionTag &msg) ;
    ApolloplanningObjectMotionTypemotionTag from_json_ApolloplanningObjectMotionTypemotionTag (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectMotionTypemotionTag from_json<ApolloplanningObjectMotionTypemotionTag>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectMotionTypemotionTag &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectMotionTypemotionTag & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectMotionTypemotionTag & dt);
}
