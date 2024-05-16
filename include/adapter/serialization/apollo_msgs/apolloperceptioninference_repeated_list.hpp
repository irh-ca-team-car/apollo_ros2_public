#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_repeated_list.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceRepeatedList &msg) ;
    ApolloperceptioninferenceRepeatedList from_json_ApolloperceptioninferenceRepeatedList (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceRepeatedList from_json<ApolloperceptioninferenceRepeatedList>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceRepeatedList &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceRepeatedList & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceRepeatedList & dt);
}
