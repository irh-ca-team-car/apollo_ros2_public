#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_stream_tcp.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStreamTcp &msg) ;
    ApollodriversgnssconfigStreamTcp from_json_ApollodriversgnssconfigStreamTcp (nlohmann::json obj) ;
    template <>
    ApollodriversgnssconfigStreamTcp from_json<ApollodriversgnssconfigStreamTcp>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStreamTcp &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStreamTcp & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStreamTcp & dt);
}
