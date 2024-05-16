#pragma once
#include "apollo_msgs/msg/apollodrivers_conti_radar.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_conti_radar_obs.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_radar_state201.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_cluster_list_status600.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_object_list_status60_a.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversContiRadar &msg) ;
    ApollodriversContiRadar from_json_ApollodriversContiRadar (nlohmann::json obj) ;
    template <>
    ApollodriversContiRadar from_json<ApollodriversContiRadar>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversContiRadar &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversContiRadar & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversContiRadar & dt);
}
