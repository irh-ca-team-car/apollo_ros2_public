#pragma once
#include "apollo_msgs/msg/apollohdmap_passage_group.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_passage.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapPassageGroup &msg) ;
    ApollohdmapPassageGroup from_json_ApollohdmapPassageGroup (nlohmann::json obj) ;
    template <>
    ApollohdmapPassageGroup from_json<ApollohdmapPassageGroup>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapPassageGroup &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapPassageGroup & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapPassageGroup & dt);
}
