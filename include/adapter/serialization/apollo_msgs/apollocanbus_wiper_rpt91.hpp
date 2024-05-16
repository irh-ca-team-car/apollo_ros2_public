#pragma once
#include "apollo_msgs/msg/apollocanbus_wiper_rpt91.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWiperRpt91 &msg) ;
    ApollocanbusWiperRpt91 from_json_ApollocanbusWiperRpt91 (nlohmann::json obj) ;
    template <>
    ApollocanbusWiperRpt91 from_json<ApollocanbusWiperRpt91>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWiperRpt91 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWiperRpt91 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWiperRpt91 & dt);
}
