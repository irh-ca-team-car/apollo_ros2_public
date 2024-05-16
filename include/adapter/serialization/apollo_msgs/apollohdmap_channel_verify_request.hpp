#pragma once
#include "apollo_msgs/msg/apollohdmap_channel_verify_request.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapChannelVerifyRequest &msg) ;
    ApollohdmapChannelVerifyRequest from_json_ApollohdmapChannelVerifyRequest (nlohmann::json obj) ;
    template <>
    ApollohdmapChannelVerifyRequest from_json<ApollohdmapChannelVerifyRequest>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapChannelVerifyRequest &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapChannelVerifyRequest & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapChannelVerifyRequest & dt);
}
