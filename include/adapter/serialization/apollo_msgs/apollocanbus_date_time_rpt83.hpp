#pragma once
#include "apollo_msgs/msg/apollocanbus_date_time_rpt83.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDateTimeRpt83 &msg) ;
    ApollocanbusDateTimeRpt83 from_json_ApollocanbusDateTimeRpt83 (nlohmann::json obj) ;
    template <>
    ApollocanbusDateTimeRpt83 from_json<ApollocanbusDateTimeRpt83>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDateTimeRpt83 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDateTimeRpt83 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDateTimeRpt83 & dt);
}
