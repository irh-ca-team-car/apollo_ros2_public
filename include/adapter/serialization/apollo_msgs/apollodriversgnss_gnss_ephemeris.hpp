#pragma once
#include "apollo_msgs/msg/apollodriversgnss_gnss_ephemeris.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriversgnss_keppler_orbit.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_glonass_orbit.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssGnssEphemeris &msg) ;
    ApollodriversgnssGnssEphemeris from_json_ApollodriversgnssGnssEphemeris (nlohmann::json obj) ;
    template <>
    ApollodriversgnssGnssEphemeris from_json<ApollodriversgnssGnssEphemeris>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssGnssEphemeris &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssGnssEphemeris & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssGnssEphemeris & dt);
}
