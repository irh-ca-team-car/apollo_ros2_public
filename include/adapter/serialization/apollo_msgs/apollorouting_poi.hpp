#pragma once
#include "apollo_msgs/msg/apollorouting_poi.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollorouting_landmark.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingPOI &msg) ;
    ApolloroutingPOI from_json_ApolloroutingPOI (nlohmann::json obj) ;
    template <>
    ApolloroutingPOI from_json<ApolloroutingPOI>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingPOI &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingPOI & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingPOI & dt);
}
