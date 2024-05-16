#pragma once
#include "apollo_msgs/msg/apollocanbus_vin_resp3393.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVinResp3393 &msg) ;
    ApollocanbusVinResp3393 from_json_ApollocanbusVinResp3393 (nlohmann::json obj) ;
    template <>
    ApollocanbusVinResp3393 from_json<ApollocanbusVinResp3393>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVinResp3393 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVinResp3393 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVinResp3393 & dt);
}
