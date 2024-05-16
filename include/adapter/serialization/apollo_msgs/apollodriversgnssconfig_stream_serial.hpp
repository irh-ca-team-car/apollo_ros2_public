#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_stream_serial.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStreamSerial &msg) ;
    ApollodriversgnssconfigStreamSerial from_json_ApollodriversgnssconfigStreamSerial (nlohmann::json obj) ;
    template <>
    ApollodriversgnssconfigStreamSerial from_json<ApollodriversgnssconfigStreamSerial>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStreamSerial &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStreamSerial & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStreamSerial & dt);
}
