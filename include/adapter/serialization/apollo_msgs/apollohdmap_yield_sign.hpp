#pragma once
#include "apollo_msgs/msg/apollohdmap_yield_sign.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_curve.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapYieldSign &msg) ;
    ApollohdmapYieldSign from_json_ApollohdmapYieldSign (nlohmann::json obj) ;
    template <>
    ApollohdmapYieldSign from_json<ApollohdmapYieldSign>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapYieldSign &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapYieldSign & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapYieldSign & dt);
}
