#pragma once
#include "apollo_msgs/msg/apollohdmap_subsignal.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSubsignal &msg) ;
    ApollohdmapSubsignal from_json_ApollohdmapSubsignal (nlohmann::json obj) ;
    template <>
    ApollohdmapSubsignal from_json<ApollohdmapSubsignal>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSubsignal &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSubsignal & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSubsignal & dt);
}
