#pragma once
#include "apollo_msgs/msg/apollocanbus_ads338e.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAds338e &msg) ;
    ApollocanbusAds338e from_json_ApollocanbusAds338e (nlohmann::json obj) ;
    template <>
    ApollocanbusAds338e from_json<ApollocanbusAds338e>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAds338e &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAds338e & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAds338e & dt);
}
