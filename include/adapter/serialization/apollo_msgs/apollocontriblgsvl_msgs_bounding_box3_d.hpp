#pragma once
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_bounding_box3_d.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_pose.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_vector3.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsBoundingBox3D &msg) ;
    ApollocontriblgsvlMsgsBoundingBox3D from_json_ApollocontriblgsvlMsgsBoundingBox3D (nlohmann::json obj) ;
    template <>
    ApollocontriblgsvlMsgsBoundingBox3D from_json<ApollocontriblgsvlMsgsBoundingBox3D>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsBoundingBox3D &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsBoundingBox3D & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsBoundingBox3D & dt);
}
