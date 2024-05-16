#pragma once
#include "apollo_msgs/msg/apolloplanning_main_parking.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainParking &msg) ;
    ApolloplanningMainParking from_json_ApolloplanningMainParking (nlohmann::json obj) ;
    template <>
    ApolloplanningMainParking from_json<ApolloplanningMainParking>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainParking &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainParking & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainParking & dt);
}
