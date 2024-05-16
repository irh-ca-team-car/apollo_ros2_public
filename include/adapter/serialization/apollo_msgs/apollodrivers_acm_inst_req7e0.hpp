#pragma once
#include "apollo_msgs/msg/apollodrivers_acm_inst_req7e0.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversAcmInstReq7e0 &msg) ;
    ApollodriversAcmInstReq7e0 from_json_ApollodriversAcmInstReq7e0 (nlohmann::json obj) ;
    template <>
    ApollodriversAcmInstReq7e0 from_json<ApollodriversAcmInstReq7e0>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversAcmInstReq7e0 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversAcmInstReq7e0 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversAcmInstReq7e0 & dt);
}
