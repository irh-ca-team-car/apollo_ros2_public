#pragma once
#include "apollo_msgs/msg/apollocanbus_vin_resp2392.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVinResp2392 &msg) ;
    ApollocanbusVinResp2392 from_json_ApollocanbusVinResp2392 (nlohmann::json obj) ;
    template <>
    ApollocanbusVinResp2392 from_json<ApollocanbusVinResp2392>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVinResp2392 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVinResp2392 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVinResp2392 & dt);
}
