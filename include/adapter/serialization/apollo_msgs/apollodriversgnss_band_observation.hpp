#pragma once
#include "apollo_msgs/msg/apollodriversgnss_band_observation.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssBandObservation &msg) ;
    ApollodriversgnssBandObservation from_json_ApollodriversgnssBandObservation (nlohmann::json obj) ;
    template <>
    ApollodriversgnssBandObservation from_json<ApollodriversgnssBandObservation>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssBandObservation &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssBandObservation & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssBandObservation & dt);
}
