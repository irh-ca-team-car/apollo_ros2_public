#pragma once
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_vector3.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsTwist &msg) ;
    ApollocontriblgsvlMsgsTwist from_json_ApollocontriblgsvlMsgsTwist (nlohmann::json obj) ;
    template <>
    ApollocontriblgsvlMsgsTwist from_json<ApollocontriblgsvlMsgsTwist>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsTwist &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsTwist & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsTwist & dt);
}
