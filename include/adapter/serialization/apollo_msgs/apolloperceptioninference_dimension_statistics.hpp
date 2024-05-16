#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_dimension_statistics.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDimensionStatistics &msg) ;
    ApolloperceptioninferenceDimensionStatistics from_json_ApolloperceptioninferenceDimensionStatistics (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDimensionStatistics from_json<ApolloperceptioninferenceDimensionStatistics>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDimensionStatistics &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDimensionStatistics & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDimensionStatistics & dt);
}
