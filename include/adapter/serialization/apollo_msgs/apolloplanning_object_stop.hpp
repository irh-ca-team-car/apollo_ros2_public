#pragma once
#include "apollo_msgs/msg/apolloplanning_object_stop.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectStop &msg) ;
    ApolloplanningObjectStop from_json_ApolloplanningObjectStop (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectStop from_json<ApolloplanningObjectStop>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectStop &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectStop & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectStop & dt);
}
