#pragma once
#include "apollo_msgs/msg/apolloplanning_object_side_pass.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectSidePass &msg) ;
    ApolloplanningObjectSidePass from_json_ApolloplanningObjectSidePass (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectSidePass from_json<ApolloplanningObjectSidePass>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectSidePass &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectSidePass & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectSidePass & dt);
}
