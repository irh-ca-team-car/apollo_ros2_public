#pragma once
#include "apollo_msgs/msg/apollocanbus_date_time_rpt40f.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDateTimeRpt40f &msg) ;
    ApollocanbusDateTimeRpt40f from_json_ApollocanbusDateTimeRpt40f (nlohmann::json obj) ;
    template <>
    ApollocanbusDateTimeRpt40f from_json<ApollocanbusDateTimeRpt40f>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDateTimeRpt40f &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDateTimeRpt40f & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDateTimeRpt40f & dt);
}
