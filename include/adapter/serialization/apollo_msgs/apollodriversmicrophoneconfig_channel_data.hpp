#pragma once
#include "apollo_msgs/msg/apollodriversmicrophoneconfig_channel_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversmicrophoneconfigChannelData &msg) ;
    ApollodriversmicrophoneconfigChannelData from_json_ApollodriversmicrophoneconfigChannelData (nlohmann::json obj) ;
    template <>
    ApollodriversmicrophoneconfigChannelData from_json<ApollodriversmicrophoneconfigChannelData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversmicrophoneconfigChannelData &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversmicrophoneconfigChannelData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversmicrophoneconfigChannelData & dt);
}
