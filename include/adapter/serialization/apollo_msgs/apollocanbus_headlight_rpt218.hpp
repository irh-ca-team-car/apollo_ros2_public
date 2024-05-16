#pragma once
#include "apollo_msgs/msg/apollocanbus_headlight_rpt218.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHeadlightRpt218 &msg) ;
    ApollocanbusHeadlightRpt218 from_json_ApollocanbusHeadlightRpt218 (nlohmann::json obj) ;
    template <>
    ApollocanbusHeadlightRpt218 from_json<ApollocanbusHeadlightRpt218>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHeadlightRpt218 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHeadlightRpt218 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHeadlightRpt218 & dt);
}
