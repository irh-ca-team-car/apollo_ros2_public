#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_hdf5_output_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceHDF5OutputParameter &msg) ;
    ApolloperceptioninferenceHDF5OutputParameter from_json_ApolloperceptioninferenceHDF5OutputParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceHDF5OutputParameter from_json<ApolloperceptioninferenceHDF5OutputParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceHDF5OutputParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceHDF5OutputParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceHDF5OutputParameter & dt);
}
