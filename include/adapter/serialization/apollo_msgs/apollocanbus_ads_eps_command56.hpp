#pragma once
#include "apollo_msgs/msg/apollocanbus_ads_eps_command56.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsEpsCommand56 &msg) ;
    ApollocanbusAdsEpsCommand56 from_json_ApollocanbusAdsEpsCommand56 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdsEpsCommand56 from_json<ApollocanbusAdsEpsCommand56>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsEpsCommand56 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsEpsCommand56 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsEpsCommand56 & dt);
}
