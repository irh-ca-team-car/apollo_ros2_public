#pragma once
#include "apollo_msgs/msg/apollocanbus_detected_object_rpt411.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDetectedObjectRpt411 &msg) ;
    ApollocanbusDetectedObjectRpt411 from_json_ApollocanbusDetectedObjectRpt411 (nlohmann::json obj) ;
    template <>
    ApollocanbusDetectedObjectRpt411 from_json<ApollocanbusDetectedObjectRpt411>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDetectedObjectRpt411 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDetectedObjectRpt411 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDetectedObjectRpt411 & dt);
}
