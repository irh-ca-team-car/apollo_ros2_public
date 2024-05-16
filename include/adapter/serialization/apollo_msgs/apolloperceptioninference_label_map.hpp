#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_label_map.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_label_map_item.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceLabelMap &msg) ;
    ApolloperceptioninferenceLabelMap from_json_ApolloperceptioninferenceLabelMap (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceLabelMap from_json<ApolloperceptioninferenceLabelMap>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceLabelMap &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceLabelMap & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceLabelMap & dt);
}
