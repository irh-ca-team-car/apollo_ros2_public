#pragma once
#include "apollo_msgs/msg/apollocanbus_ads_shifter115.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsShifter115 &msg) ;
    ApollocanbusAdsShifter115 from_json_ApollocanbusAdsShifter115 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdsShifter115 from_json<ApollocanbusAdsShifter115>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsShifter115 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsShifter115 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsShifter115 & dt);
}
