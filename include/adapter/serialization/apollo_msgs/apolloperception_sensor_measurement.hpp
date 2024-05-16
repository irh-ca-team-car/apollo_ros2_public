#pragma once
#include "apollo_msgs/msg/apolloperception_sensor_measurement.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_b_box2_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionSensorMeasurement &msg) ;
    ApolloperceptionSensorMeasurement from_json_ApolloperceptionSensorMeasurement (nlohmann::json obj) ;
    template <>
    ApolloperceptionSensorMeasurement from_json<ApolloperceptionSensorMeasurement>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionSensorMeasurement &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionSensorMeasurement & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionSensorMeasurement & dt);
}
