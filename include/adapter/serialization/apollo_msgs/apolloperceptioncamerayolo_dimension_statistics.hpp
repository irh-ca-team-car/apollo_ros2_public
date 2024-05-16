#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerayolo_dimension_statistics.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerayoloDimensionStatistics &msg) ;
    ApolloperceptioncamerayoloDimensionStatistics from_json_ApolloperceptioncamerayoloDimensionStatistics (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerayoloDimensionStatistics from_json<ApolloperceptioncamerayoloDimensionStatistics>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerayoloDimensionStatistics &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerayoloDimensionStatistics & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerayoloDimensionStatistics & dt);
}
