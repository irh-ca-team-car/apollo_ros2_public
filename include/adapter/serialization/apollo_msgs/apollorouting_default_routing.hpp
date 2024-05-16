#pragma once
#include "apollo_msgs/msg/apollorouting_default_routing.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingDefaultRouting &msg) ;
    ApolloroutingDefaultRouting from_json_ApolloroutingDefaultRouting (nlohmann::json obj) ;
    template <>
    ApolloroutingDefaultRouting from_json<ApolloroutingDefaultRouting>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingDefaultRouting &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingDefaultRouting & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingDefaultRouting & dt);
}
