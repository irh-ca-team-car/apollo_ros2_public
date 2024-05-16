#pragma once
#include "apollo_msgs/msg/apollocanbus_global_cmd69.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGlobalCmd69 &msg) ;
    ApollocanbusGlobalCmd69 from_json_ApollocanbusGlobalCmd69 (nlohmann::json obj) ;
    template <>
    ApollocanbusGlobalCmd69 from_json<ApollocanbusGlobalCmd69>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGlobalCmd69 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGlobalCmd69 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGlobalCmd69 & dt);
}
