#pragma once
#include "apollo_msgs/msg/apollocanbus_headlight_aux_rpt318.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHeadlightAuxRpt318 &msg) ;
    ApollocanbusHeadlightAuxRpt318 from_json_ApollocanbusHeadlightAuxRpt318 (nlohmann::json obj) ;
    template <>
    ApollocanbusHeadlightAuxRpt318 from_json<ApollocanbusHeadlightAuxRpt318>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHeadlightAuxRpt318 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHeadlightAuxRpt318 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHeadlightAuxRpt318 & dt);
}
