#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerasmoke_dimension_statistics.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasmokeDimensionStatistics &msg) ;
    ApolloperceptioncamerasmokeDimensionStatistics from_json_ApolloperceptioncamerasmokeDimensionStatistics (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerasmokeDimensionStatistics from_json<ApolloperceptioncamerasmokeDimensionStatistics>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasmokeDimensionStatistics &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasmokeDimensionStatistics & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasmokeDimensionStatistics & dt);
}
