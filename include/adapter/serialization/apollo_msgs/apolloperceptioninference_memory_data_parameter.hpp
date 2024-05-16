#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_memory_data_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceMemoryDataParameter &msg) ;
    ApolloperceptioninferenceMemoryDataParameter from_json_ApolloperceptioninferenceMemoryDataParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceMemoryDataParameter from_json<ApolloperceptioninferenceMemoryDataParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceMemoryDataParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceMemoryDataParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceMemoryDataParameter & dt);
}
