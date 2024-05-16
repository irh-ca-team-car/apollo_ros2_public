#pragma once
#include "apollo_msgs/msg/apollocanbus_component_rpt20.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusComponentRpt20 &msg) ;
    ApollocanbusComponentRpt20 from_json_ApollocanbusComponentRpt20 (nlohmann::json obj) ;
    template <>
    ApollocanbusComponentRpt20 from_json<ApollocanbusComponentRpt20>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusComponentRpt20 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusComponentRpt20 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusComponentRpt20 & dt);
}
