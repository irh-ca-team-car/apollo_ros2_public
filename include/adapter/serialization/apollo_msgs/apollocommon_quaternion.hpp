#pragma once
#include "apollo_msgs/msg/apollocommon_quaternion.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonQuaternion &msg) ;
    ApollocommonQuaternion from_json_ApollocommonQuaternion (nlohmann::json obj) ;
    template <>
    ApollocommonQuaternion from_json<ApollocommonQuaternion>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonQuaternion &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonQuaternion & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonQuaternion & dt);
}
