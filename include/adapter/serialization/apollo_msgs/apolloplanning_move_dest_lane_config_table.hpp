#pragma once
#include "apollo_msgs/msg/apolloplanning_move_dest_lane_config_table.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_shift_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMoveDestLaneConfigTable &msg) ;
    ApolloplanningMoveDestLaneConfigTable from_json_ApolloplanningMoveDestLaneConfigTable (nlohmann::json obj) ;
    template <>
    ApolloplanningMoveDestLaneConfigTable from_json<ApolloplanningMoveDestLaneConfigTable>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMoveDestLaneConfigTable &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMoveDestLaneConfigTable & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMoveDestLaneConfigTable & dt);
}
