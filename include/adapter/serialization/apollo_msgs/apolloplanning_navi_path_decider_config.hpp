#pragma once
#include "apollo_msgs/msg/apolloplanning_navi_path_decider_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_move_dest_lane_config_table.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningNaviPathDeciderConfig &msg) ;
    ApolloplanningNaviPathDeciderConfig from_json_ApolloplanningNaviPathDeciderConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningNaviPathDeciderConfig from_json<ApolloplanningNaviPathDeciderConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningNaviPathDeciderConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningNaviPathDeciderConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningNaviPathDeciderConfig & dt);
}
