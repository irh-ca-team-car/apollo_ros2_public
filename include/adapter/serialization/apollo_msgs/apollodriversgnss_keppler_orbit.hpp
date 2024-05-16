#pragma once
#include "apollo_msgs/msg/apollodriversgnss_keppler_orbit.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssKepplerOrbit &msg) ;
    ApollodriversgnssKepplerOrbit from_json_ApollodriversgnssKepplerOrbit (nlohmann::json obj) ;
    template <>
    ApollodriversgnssKepplerOrbit from_json<ApollodriversgnssKepplerOrbit>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssKepplerOrbit &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssKepplerOrbit & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssKepplerOrbit & dt);
}
