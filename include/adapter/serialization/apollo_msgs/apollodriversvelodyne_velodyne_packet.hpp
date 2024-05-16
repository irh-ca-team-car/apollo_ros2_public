#pragma once
#include "apollo_msgs/msg/apollodriversvelodyne_velodyne_packet.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvelodyneVelodynePacket &msg) ;
    ApollodriversvelodyneVelodynePacket from_json_ApollodriversvelodyneVelodynePacket (nlohmann::json obj) ;
    template <>
    ApollodriversvelodyneVelodynePacket from_json<ApollodriversvelodyneVelodynePacket>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvelodyneVelodynePacket &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversvelodyneVelodynePacket & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvelodyneVelodynePacket & dt);
}
