#pragma once
#include "apollo_msgs/msg/apollodrivers_esr_trackmotionpower540.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodrivers_motionpower.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrTrackmotionpower540 &msg) ;
    ApollodriversEsrTrackmotionpower540 from_json_ApollodriversEsrTrackmotionpower540 (nlohmann::json obj) ;
    template <>
    ApollodriversEsrTrackmotionpower540 from_json<ApollodriversEsrTrackmotionpower540>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrTrackmotionpower540 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrTrackmotionpower540 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrTrackmotionpower540 & dt);
}
