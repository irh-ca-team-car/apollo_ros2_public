#pragma once
#include "apollo_msgs/msg/apollohdmap_loops_verify_request.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_verify_range.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLoopsVerifyRequest &msg) ;
    ApollohdmapLoopsVerifyRequest from_json_ApollohdmapLoopsVerifyRequest (nlohmann::json obj) ;
    template <>
    ApollohdmapLoopsVerifyRequest from_json<ApollohdmapLoopsVerifyRequest>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLoopsVerifyRequest &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLoopsVerifyRequest & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLoopsVerifyRequest & dt);
}
