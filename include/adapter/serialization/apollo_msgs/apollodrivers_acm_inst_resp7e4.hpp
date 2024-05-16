#pragma once
#include "apollo_msgs/msg/apollodrivers_acm_inst_resp7e4.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversAcmInstResp7e4 &msg) ;
    ApollodriversAcmInstResp7e4 from_json_ApollodriversAcmInstResp7e4 (nlohmann::json obj) ;
    template <>
    ApollodriversAcmInstResp7e4 from_json<ApollodriversAcmInstResp7e4>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversAcmInstResp7e4 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversAcmInstResp7e4 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversAcmInstResp7e4 & dt);
}
