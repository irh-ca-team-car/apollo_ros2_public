#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_datum.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDatum &msg) ;
    ApolloperceptioninferenceDatum from_json_ApolloperceptioninferenceDatum (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDatum from_json<ApolloperceptioninferenceDatum>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDatum &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDatum & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDatum & dt);
}
