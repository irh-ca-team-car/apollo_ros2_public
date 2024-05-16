#pragma once
#include "apollo_msgs/msg/apollohdmap_loop_result.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLoopResult &msg) ;
    ApollohdmapLoopResult from_json_ApollohdmapLoopResult (nlohmann::json obj) ;
    template <>
    ApollohdmapLoopResult from_json<ApollohdmapLoopResult>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLoopResult &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLoopResult & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLoopResult & dt);
}
