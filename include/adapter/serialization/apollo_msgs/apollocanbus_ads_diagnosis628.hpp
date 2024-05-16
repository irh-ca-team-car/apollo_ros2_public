#pragma once
#include "apollo_msgs/msg/apollocanbus_ads_diagnosis628.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsDiagnosis628 &msg) ;
    ApollocanbusAdsDiagnosis628 from_json_ApollocanbusAdsDiagnosis628 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdsDiagnosis628 from_json<ApollocanbusAdsDiagnosis628>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsDiagnosis628 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsDiagnosis628 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsDiagnosis628 & dt);
}
