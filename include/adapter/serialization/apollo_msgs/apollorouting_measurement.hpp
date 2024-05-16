#pragma once
#include "apollo_msgs/msg/apollorouting_measurement.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingMeasurement &msg) ;
    ApolloroutingMeasurement from_json_ApolloroutingMeasurement (nlohmann::json obj) ;
    template <>
    ApolloroutingMeasurement from_json<ApolloroutingMeasurement>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingMeasurement &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingMeasurement & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingMeasurement & dt);
}
