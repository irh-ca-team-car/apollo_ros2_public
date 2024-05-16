#pragma once
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_detection2_d.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_bounding_box2_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_twist.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsDetection2D &msg) ;
    ApollocontriblgsvlMsgsDetection2D from_json_ApollocontriblgsvlMsgsDetection2D (nlohmann::json obj) ;
    template <>
    ApollocontriblgsvlMsgsDetection2D from_json<ApollocontriblgsvlMsgsDetection2D>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsDetection2D &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsDetection2D & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsDetection2D & dt);
}
