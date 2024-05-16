#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_stream_ntrip.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStreamNtrip &msg) ;
    ApollodriversgnssconfigStreamNtrip from_json_ApollodriversgnssconfigStreamNtrip (nlohmann::json obj) ;
    template <>
    ApollodriversgnssconfigStreamNtrip from_json<ApollodriversgnssconfigStreamNtrip>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStreamNtrip &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStreamNtrip & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStreamNtrip & dt);
}
