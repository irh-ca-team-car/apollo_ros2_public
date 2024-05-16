#pragma once
#include "apollo_msgs/msg/apolloperceptioncameraapp_calibration_service_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_plugin_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappCalibrationServiceParam &msg) ;
    ApolloperceptioncameraappCalibrationServiceParam from_json_ApolloperceptioncameraappCalibrationServiceParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameraappCalibrationServiceParam from_json<ApolloperceptioncameraappCalibrationServiceParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappCalibrationServiceParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappCalibrationServiceParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappCalibrationServiceParam & dt);
}
