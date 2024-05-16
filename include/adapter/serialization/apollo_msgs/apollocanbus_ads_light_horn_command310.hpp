#pragma once
#include "apollo_msgs/msg/apollocanbus_ads_light_horn_command310.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsLightHornCommand310 &msg) ;
    ApollocanbusAdsLightHornCommand310 from_json_ApollocanbusAdsLightHornCommand310 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdsLightHornCommand310 from_json<ApollocanbusAdsLightHornCommand310>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsLightHornCommand310 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsLightHornCommand310 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsLightHornCommand310 & dt);
}
