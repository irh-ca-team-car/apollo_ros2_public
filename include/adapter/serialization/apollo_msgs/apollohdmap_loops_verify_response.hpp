#pragma once
#include "apollo_msgs/msg/apollohdmap_loops_verify_response.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_loop_result.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLoopsVerifyResponse &msg) ;
    ApollohdmapLoopsVerifyResponse from_json_ApollohdmapLoopsVerifyResponse (nlohmann::json obj) ;
    template <>
    ApollohdmapLoopsVerifyResponse from_json<ApollohdmapLoopsVerifyResponse>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLoopsVerifyResponse &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLoopsVerifyResponse & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLoopsVerifyResponse & dt);
}
