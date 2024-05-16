#pragma once
#include "apollo_msgs/msg/apollobridge_udp_bridge_sender_remote_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollobridgeUDPBridgeSenderRemoteInfo &msg) ;
    ApollobridgeUDPBridgeSenderRemoteInfo from_json_ApollobridgeUDPBridgeSenderRemoteInfo (nlohmann::json obj) ;
    template <>
    ApollobridgeUDPBridgeSenderRemoteInfo from_json<ApollobridgeUDPBridgeSenderRemoteInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollobridgeUDPBridgeSenderRemoteInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollobridgeUDPBridgeSenderRemoteInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollobridgeUDPBridgeSenderRemoteInfo & dt);
}
