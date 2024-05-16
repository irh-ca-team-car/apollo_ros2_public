#pragma once
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_bounding_box2_d.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsBoundingBox2D &msg) ;
    ApollocontriblgsvlMsgsBoundingBox2D from_json_ApollocontriblgsvlMsgsBoundingBox2D (nlohmann::json obj) ;
    template <>
    ApollocontriblgsvlMsgsBoundingBox2D from_json<ApollocontriblgsvlMsgsBoundingBox2D>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsBoundingBox2D &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsBoundingBox2D & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsBoundingBox2D & dt);
}
