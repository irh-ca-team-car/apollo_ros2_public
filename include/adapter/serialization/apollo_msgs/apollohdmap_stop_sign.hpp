#pragma once
#include "apollo_msgs/msg/apollohdmap_stop_sign.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_curve.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapStopSign &msg) ;
    ApollohdmapStopSign from_json_ApollohdmapStopSign (nlohmann::json obj) ;
    template <>
    ApollohdmapStopSign from_json<ApollohdmapStopSign>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapStopSign &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapStopSign & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapStopSign & dt);
}
