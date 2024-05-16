#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_hdf5_data_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceHDF5DataParameter &msg) ;
    ApolloperceptioninferenceHDF5DataParameter from_json_ApolloperceptioninferenceHDF5DataParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceHDF5DataParameter from_json<ApolloperceptioninferenceHDF5DataParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceHDF5DataParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceHDF5DataParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceHDF5DataParameter & dt);
}
