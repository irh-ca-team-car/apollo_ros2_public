#pragma once
#include "apollo_msgs/msg/apolloplanning_object_overtake.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectOvertake &msg) ;
    ApolloplanningObjectOvertake from_json_ApolloplanningObjectOvertake (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectOvertake from_json<ApolloplanningObjectOvertake>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectOvertake &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectOvertake & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectOvertake & dt);
}
