#pragma once
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_vector3.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsVector3 &msg) ;
    ApollocontriblgsvlMsgsVector3 from_json_ApollocontriblgsvlMsgsVector3 (nlohmann::json obj) ;
    template <>
    ApollocontriblgsvlMsgsVector3 from_json<ApollocontriblgsvlMsgsVector3>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsVector3 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsVector3 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsVector3 & dt);
}
