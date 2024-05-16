#pragma once
#include "apollo_msgs/msg/apollohdmap_parking_space.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapParkingSpace &msg) ;
    ApollohdmapParkingSpace from_json_ApollohdmapParkingSpace (nlohmann::json obj) ;
    template <>
    ApollohdmapParkingSpace from_json<ApollohdmapParkingSpace>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapParkingSpace &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapParkingSpace & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapParkingSpace & dt);
}
