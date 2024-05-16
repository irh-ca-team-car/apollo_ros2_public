#pragma once
#include "apollo_msgs/msg/apollohdmap_parking_lot.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapParkingLot &msg) ;
    ApollohdmapParkingLot from_json_ApollohdmapParkingLot (nlohmann::json obj) ;
    template <>
    ApollohdmapParkingLot from_json<ApollohdmapParkingLot>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapParkingLot &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapParkingLot & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapParkingLot & dt);
}
