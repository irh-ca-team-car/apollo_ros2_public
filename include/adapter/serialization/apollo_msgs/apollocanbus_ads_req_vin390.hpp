#pragma once
#include "apollo_msgs/msg/apollocanbus_ads_req_vin390.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsReqVin390 &msg) ;
    ApollocanbusAdsReqVin390 from_json_ApollocanbusAdsReqVin390 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdsReqVin390 from_json<ApollocanbusAdsReqVin390>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsReqVin390 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsReqVin390 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsReqVin390 & dt);
}
