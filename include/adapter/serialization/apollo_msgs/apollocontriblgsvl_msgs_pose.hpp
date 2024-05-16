#pragma once
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_pose.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_quaternion.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsPose &msg) ;
    ApollocontriblgsvlMsgsPose from_json_ApollocontriblgsvlMsgsPose (nlohmann::json obj) ;
    template <>
    ApollocontriblgsvlMsgsPose from_json<ApollocontriblgsvlMsgsPose>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsPose &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsPose & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsPose & dt);
}
