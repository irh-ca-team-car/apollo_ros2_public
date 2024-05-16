#pragma once
#include "apollo_msgs/msg/apollocanbus_shift_aux_rpt328.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusShiftAuxRpt328 &msg) ;
    ApollocanbusShiftAuxRpt328 from_json_ApollocanbusShiftAuxRpt328 (nlohmann::json obj) ;
    template <>
    ApollocanbusShiftAuxRpt328 from_json<ApollocanbusShiftAuxRpt328>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusShiftAuxRpt328 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusShiftAuxRpt328 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusShiftAuxRpt328 & dt);
}
