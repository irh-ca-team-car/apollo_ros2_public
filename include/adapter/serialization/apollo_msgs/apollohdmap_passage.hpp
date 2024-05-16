#pragma once
#include "apollo_msgs/msg/apollohdmap_passage.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapPassage &msg) ;
    ApollohdmapPassage from_json_ApollohdmapPassage (nlohmann::json obj) ;
    template <>
    ApollohdmapPassage from_json<ApollohdmapPassage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapPassage &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapPassage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapPassage & dt);
}
