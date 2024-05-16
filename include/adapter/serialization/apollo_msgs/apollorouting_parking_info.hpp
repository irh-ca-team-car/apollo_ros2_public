#pragma once
#include "apollo_msgs/msg/apollorouting_parking_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingParkingInfo &msg) ;
    ApolloroutingParkingInfo from_json_ApolloroutingParkingInfo (nlohmann::json obj) ;
    template <>
    ApolloroutingParkingInfo from_json<ApolloroutingParkingInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingParkingInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloroutingParkingInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingParkingInfo & dt);
}
