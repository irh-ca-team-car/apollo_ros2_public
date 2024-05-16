#pragma once
#include "apollo_msgs/msg/apolloplanningautotuning_st_point_pair.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningSTPointPair &msg) ;
    ApolloplanningautotuningSTPointPair from_json_ApolloplanningautotuningSTPointPair (nlohmann::json obj) ;
    template <>
    ApolloplanningautotuningSTPointPair from_json<ApolloplanningautotuningSTPointPair>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningSTPointPair &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningSTPointPair & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningSTPointPair & dt);
}
