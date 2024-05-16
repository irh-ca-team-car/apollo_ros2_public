#pragma once
#include "apollo_msgs/msg/apollorouting_default_routings.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_default_routing.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingDefaultRoutings &msg) ;
    ApolloroutingDefaultRoutings from_json_ApolloroutingDefaultRoutings (nlohmann::json obj) ;
    template <>
    ApolloroutingDefaultRoutings from_json<ApolloroutingDefaultRoutings>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingDefaultRoutings &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingDefaultRoutings & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingDefaultRoutings & dt);
}
