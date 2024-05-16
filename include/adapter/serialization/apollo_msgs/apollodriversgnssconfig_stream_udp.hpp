#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_stream_udp.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStreamUdp &msg) ;
    ApollodriversgnssconfigStreamUdp from_json_ApollodriversgnssconfigStreamUdp (nlohmann::json obj) ;
    template <>
    ApollodriversgnssconfigStreamUdp from_json<ApollodriversgnssconfigStreamUdp>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStreamUdp &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStreamUdp & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStreamUdp & dt);
}
