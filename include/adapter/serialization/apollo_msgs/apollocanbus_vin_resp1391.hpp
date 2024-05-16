#pragma once
#include "apollo_msgs/msg/apollocanbus_vin_resp1391.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVinResp1391 &msg) ;
    ApollocanbusVinResp1391 from_json_ApollocanbusVinResp1391 (nlohmann::json obj) ;
    template <>
    ApollocanbusVinResp1391 from_json<ApollocanbusVinResp1391>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVinResp1391 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVinResp1391 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVinResp1391 & dt);
}
