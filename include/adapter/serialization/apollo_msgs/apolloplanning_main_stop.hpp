#pragma once
#include "apollo_msgs/msg/apolloplanning_main_stop.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainStop &msg) ;
    ApolloplanningMainStop from_json_ApolloplanningMainStop (nlohmann::json obj) ;
    template <>
    ApolloplanningMainStop from_json<ApolloplanningMainStop>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainStop &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainStop & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainStop & dt);
}
