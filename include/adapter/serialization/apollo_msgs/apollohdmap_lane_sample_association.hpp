#pragma once
#include "apollo_msgs/msg/apollohdmap_lane_sample_association.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLaneSampleAssociation &msg) ;
    ApollohdmapLaneSampleAssociation from_json_ApollohdmapLaneSampleAssociation (nlohmann::json obj) ;
    template <>
    ApollohdmapLaneSampleAssociation from_json<ApollohdmapLaneSampleAssociation>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLaneSampleAssociation &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLaneSampleAssociation & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLaneSampleAssociation & dt);
}
