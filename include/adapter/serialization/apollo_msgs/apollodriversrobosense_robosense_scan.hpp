#pragma once
#include "apollo_msgs/msg/apollodriversrobosense_robosense_scan.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversrobosense_robosense_scan_packet.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversrobosenseRobosenseScan &msg) ;
    ApollodriversrobosenseRobosenseScan from_json_ApollodriversrobosenseRobosenseScan (nlohmann::json obj) ;
    template <>
    ApollodriversrobosenseRobosenseScan from_json<ApollodriversrobosenseRobosenseScan>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversrobosenseRobosenseScan &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversrobosenseRobosenseScan & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversrobosenseRobosenseScan & dt);
}
