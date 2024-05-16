#pragma once
#include "apollo_msgs/msg/apolloplanning_path_lane_borrow_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathLaneBorrowDeciderConfig &msg) ;
    ApolloplanningPathLaneBorrowDeciderConfig from_json_ApolloplanningPathLaneBorrowDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningPathLaneBorrowDeciderConfig from_json<ApolloplanningPathLaneBorrowDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathLaneBorrowDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathLaneBorrowDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathLaneBorrowDeciderConfig & dt);
}
