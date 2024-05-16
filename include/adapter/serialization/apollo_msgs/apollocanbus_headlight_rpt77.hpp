#pragma once
#include "apollo_msgs/msg/apollocanbus_headlight_rpt77.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHeadlightRpt77 &msg) ;
    ApollocanbusHeadlightRpt77 from_json_ApollocanbusHeadlightRpt77 (nlohmann::json obj) ;
    template <>
    ApollocanbusHeadlightRpt77 from_json<ApollocanbusHeadlightRpt77>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHeadlightRpt77 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHeadlightRpt77 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHeadlightRpt77 & dt);
}
