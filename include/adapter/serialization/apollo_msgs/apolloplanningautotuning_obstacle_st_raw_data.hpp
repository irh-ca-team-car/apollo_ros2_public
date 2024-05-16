#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_obstacle_st_raw_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_obstacle_st_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningObstacleSTRawData &msg) ;
    ApolloplanningautotuningObstacleSTRawData from_json_ApolloplanningautotuningObstacleSTRawData (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningObstacleSTRawData from_json<ApolloplanningautotuningObstacleSTRawData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningObstacleSTRawData &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningObstacleSTRawData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningObstacleSTRawData & dt);
}
