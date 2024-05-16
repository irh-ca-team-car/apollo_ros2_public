#pragma once
#include "apollo_msgs/msg/apollobridge_udp_bridge_receiver_remote_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollobridgeUDPBridgeReceiverRemoteInfo &msg) ;
    ApollobridgeUDPBridgeReceiverRemoteInfo from_json_ApollobridgeUDPBridgeReceiverRemoteInfo (nlohmann::json obj) ;
    template <>
    ApollobridgeUDPBridgeReceiverRemoteInfo from_json<ApollobridgeUDPBridgeReceiverRemoteInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollobridgeUDPBridgeReceiverRemoteInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollobridgeUDPBridgeReceiverRemoteInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollobridgeUDPBridgeReceiverRemoteInfo & dt);
}
