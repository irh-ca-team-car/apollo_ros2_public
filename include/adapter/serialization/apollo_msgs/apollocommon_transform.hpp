#pragma once
#include "apollo_msgs/msg/apollocommon_transform.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_quaternion.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonTransform &msg) ;
    ApollocommonTransform from_json_ApollocommonTransform (nlohmann::json obj) ;
    template <>
    ApollocommonTransform from_json<ApollocommonTransform>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonTransform &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonTransform & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonTransform & dt);
}
