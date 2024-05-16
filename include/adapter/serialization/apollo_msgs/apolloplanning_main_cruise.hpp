#pragma once
#include "apollo_msgs/msg/apolloplanning_main_cruise.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainCruise &msg) ;
    ApolloplanningMainCruise from_json_ApolloplanningMainCruise (nlohmann::json obj) ;
    template <>
    ApolloplanningMainCruise from_json<ApolloplanningMainCruise>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainCruise &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainCruise & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainCruise & dt);
}
