#pragma once
#include "apollo_msgs/msg/apollocanbus_vcu_nm401.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuNm401 &msg) ;
    ApollocanbusVcuNm401 from_json_ApollocanbusVcuNm401 (nlohmann::json obj) ;
    template <>
    ApollocanbusVcuNm401 from_json<ApollocanbusVcuNm401>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuNm401 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuNm401 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuNm401 & dt);
}
