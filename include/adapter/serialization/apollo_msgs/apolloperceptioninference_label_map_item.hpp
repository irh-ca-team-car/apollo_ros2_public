#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_label_map_item.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceLabelMapItem &msg) ;
    ApolloperceptioninferenceLabelMapItem from_json_ApolloperceptioninferenceLabelMapItem (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceLabelMapItem from_json<ApolloperceptioninferenceLabelMapItem>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceLabelMapItem &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceLabelMapItem & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceLabelMapItem & dt);
}
