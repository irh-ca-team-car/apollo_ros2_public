#pragma once
#include "apollo_msgs/msg/apollocanbus_epb.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEpb &msg) ;
    ApollocanbusEpb from_json_ApollocanbusEpb (nlohmann::json obj) ;
    template <>
    ApollocanbusEpb from_json<ApollocanbusEpb>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEpb &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEpb & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEpb & dt);
}
