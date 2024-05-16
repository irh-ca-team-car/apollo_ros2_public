#pragma once
#include "apollo_msgs/msg/apollohdmap_channel_verify_response.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_verify_result.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapChannelVerifyResponse &msg) ;
    ApollohdmapChannelVerifyResponse from_json_ApollohdmapChannelVerifyResponse (nlohmann::json obj) ;
    template <>
    ApollohdmapChannelVerifyResponse from_json<ApollohdmapChannelVerifyResponse>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapChannelVerifyResponse &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapChannelVerifyResponse & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapChannelVerifyResponse & dt);
}
