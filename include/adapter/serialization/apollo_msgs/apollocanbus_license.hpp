#pragma once
#include "apollo_msgs/msg/apollocanbus_license.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLicense &msg) ;
    ApollocanbusLicense from_json_ApollocanbusLicense (nlohmann::json obj) ;
    template <>
    ApollocanbusLicense from_json<ApollocanbusLicense>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLicense &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLicense & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLicense & dt);
}
