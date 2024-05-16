#pragma once
#include "apollo_msgs/msg/apolloperception_sensor_meta.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionSensorMeta &msg) ;
    ApolloperceptionSensorMeta from_json_ApolloperceptionSensorMeta (nlohmann::json obj) ;
    template <>
    ApolloperceptionSensorMeta from_json<ApolloperceptionSensorMeta>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionSensorMeta &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionSensorMeta & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionSensorMeta & dt);
}
