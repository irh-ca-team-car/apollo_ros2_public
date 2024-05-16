#pragma once
#include "apollo_msgs/msg/apollocontrolcalibrationtable_control_calibration_table.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrolcalibrationtable_control_calibration_table.hpp"
namespace apollo::control::calibrationtable{
	typedef apollo_msgs::msg::ApollocontrolcalibrationtableControlCalibrationTable ControlCalibrationTable;
}
#include "apollo_msgs/msg/apollocontrolcalibrationtable_control_calibration_info.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrolcalibrationtable_control_calibration_info.hpp"
namespace apollo::control::calibrationtable{
	typedef apollo_msgs::msg::ApollocontrolcalibrationtableControlCalibrationInfo ControlCalibrationInfo;
}