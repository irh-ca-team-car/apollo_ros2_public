#pragma once
#include "apollo_msgs/msg/apolloperception_multi_sensor_meta.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_sensor_meta.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionMultiSensorMeta &msg) ;
    ApolloperceptionMultiSensorMeta from_json_ApolloperceptionMultiSensorMeta (nlohmann::json obj) ;
    template <>
    ApolloperceptionMultiSensorMeta from_json<ApolloperceptionMultiSensorMeta>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionMultiSensorMeta &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionMultiSensorMeta & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionMultiSensorMeta & dt);
}
