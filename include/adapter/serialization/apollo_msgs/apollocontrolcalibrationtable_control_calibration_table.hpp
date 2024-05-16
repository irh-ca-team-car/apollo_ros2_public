#pragma once
#include "apollo_msgs/msg/apollocontrolcalibrationtable_control_calibration_table.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocontrolcalibrationtable_control_calibration_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolcalibrationtableControlCalibrationTable &msg) ;
    ApollocontrolcalibrationtableControlCalibrationTable from_json_ApollocontrolcalibrationtableControlCalibrationTable (nlohmann::json obj) ;
    template <>
    ApollocontrolcalibrationtableControlCalibrationTable from_json<ApollocontrolcalibrationtableControlCalibrationTable>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolcalibrationtableControlCalibrationTable &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolcalibrationtableControlCalibrationTable & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolcalibrationtableControlCalibrationTable & dt);
}
