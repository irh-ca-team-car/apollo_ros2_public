#pragma once
#include "apollo_msgs/msg/apollodriversvelodyne_velodyne_scan.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_velodyne_packet.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvelodyneVelodyneScan &msg) ;
    ApollodriversvelodyneVelodyneScan from_json_ApollodriversvelodyneVelodyneScan (nlohmann::json obj) ;
    template <>
    ApollodriversvelodyneVelodyneScan from_json<ApollodriversvelodyneVelodyneScan>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvelodyneVelodyneScan &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversvelodyneVelodyneScan & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvelodyneVelodyneScan & dt);
}
