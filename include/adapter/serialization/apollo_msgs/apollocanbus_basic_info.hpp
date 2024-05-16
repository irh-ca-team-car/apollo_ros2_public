#pragma once
#include "apollo_msgs/msg/apollocanbus_basic_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBasicInfo &msg) ;
    ApollocanbusBasicInfo from_json_ApollocanbusBasicInfo (nlohmann::json obj) ;
    template <>
    ApollocanbusBasicInfo from_json<ApollocanbusBasicInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBasicInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBasicInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBasicInfo & dt);
}
