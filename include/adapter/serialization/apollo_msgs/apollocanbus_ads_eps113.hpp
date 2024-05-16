#pragma once
#include "apollo_msgs/msg/apollocanbus_ads_eps113.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsEps113 &msg) ;
    ApollocanbusAdsEps113 from_json_ApollocanbusAdsEps113 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdsEps113 from_json<ApollocanbusAdsEps113>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsEps113 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsEps113 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsEps113 & dt);
}
