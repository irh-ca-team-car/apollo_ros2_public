#pragma once
#include "apollo_msgs/msg/apollothird_party_perception_third_party_perception_device.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollothirdPartyPerceptionThirdPartyPerceptionDevice &msg) ;
    ApollothirdPartyPerceptionThirdPartyPerceptionDevice from_json_ApollothirdPartyPerceptionThirdPartyPerceptionDevice (nlohmann::json obj) ;
    template <>
    ApollothirdPartyPerceptionThirdPartyPerceptionDevice from_json<ApollothirdPartyPerceptionThirdPartyPerceptionDevice>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollothirdPartyPerceptionThirdPartyPerceptionDevice &dt);
    std::ostream & operator<<(std::ostream & os, const ApollothirdPartyPerceptionThirdPartyPerceptionDevice & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollothirdPartyPerceptionThirdPartyPerceptionDevice & dt);
}
