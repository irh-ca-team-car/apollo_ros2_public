#pragma once
#include "apollo_msgs/msg/apollodriversgnss_satellite_observation.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriversgnss_band_observation.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssSatelliteObservation &msg) ;
    ApollodriversgnssSatelliteObservation from_json_ApollodriversgnssSatelliteObservation (nlohmann::json obj) ;
    template <>
    ApollodriversgnssSatelliteObservation from_json<ApollodriversgnssSatelliteObservation>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssSatelliteObservation &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssSatelliteObservation & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssSatelliteObservation & dt);
}
