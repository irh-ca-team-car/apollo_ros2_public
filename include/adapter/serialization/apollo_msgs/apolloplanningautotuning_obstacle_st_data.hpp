#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_obstacle_st_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_st_point_pair.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningObstacleSTData &msg) ;
    ApolloplanningautotuningObstacleSTData from_json_ApolloplanningautotuningObstacleSTData (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningObstacleSTData from_json<ApolloplanningautotuningObstacleSTData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningObstacleSTData &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningObstacleSTData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningObstacleSTData & dt);
}
