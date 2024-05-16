#pragma once
#include "apollo_msgs/msg/apollodriversrobosense_robosense_scan_packet.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversrobosenseRobosenseScanPacket &msg) ;
    ApollodriversrobosenseRobosenseScanPacket from_json_ApollodriversrobosenseRobosenseScanPacket (nlohmann::json obj) ;
    template <>
    ApollodriversrobosenseRobosenseScanPacket from_json<ApollodriversrobosenseRobosenseScanPacket>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversrobosenseRobosenseScanPacket &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversrobosenseRobosenseScanPacket & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversrobosenseRobosenseScanPacket & dt);
}
