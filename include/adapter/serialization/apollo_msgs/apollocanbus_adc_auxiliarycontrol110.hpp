#pragma once
#include "apollo_msgs/msg/apollocanbus_adc_auxiliarycontrol110.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdcAuxiliarycontrol110 &msg) ;
    ApollocanbusAdcAuxiliarycontrol110 from_json_ApollocanbusAdcAuxiliarycontrol110 (nlohmann::json obj) ;
    template <>
    ApollocanbusAdcAuxiliarycontrol110 from_json<ApollocanbusAdcAuxiliarycontrol110>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdcAuxiliarycontrol110 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdcAuxiliarycontrol110 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdcAuxiliarycontrol110 & dt);
}
