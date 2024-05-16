#pragma once
#include "apollo_msgs/msg/apollodriversgnss_glonass_orbit.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssGlonassOrbit &msg) ;
    ApollodriversgnssGlonassOrbit from_json_ApollodriversgnssGlonassOrbit (nlohmann::json obj) ;
    template <>
    ApollodriversgnssGlonassOrbit from_json<ApollodriversgnssGlonassOrbit>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssGlonassOrbit &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssGlonassOrbit & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssGlonassOrbit & dt);
}
