#pragma once
#include "apollo_msgs/msg/apolloplanning_object_motion_type.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_object_motion_typemotion_tag.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectMotionType &msg) ;
    ApolloplanningObjectMotionType from_json_ApolloplanningObjectMotionType (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectMotionType from_json<ApolloplanningObjectMotionType>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectMotionType &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectMotionType & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectMotionType & dt);
}
