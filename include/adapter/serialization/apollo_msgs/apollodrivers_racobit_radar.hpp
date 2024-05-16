#pragma once
#include "apollo_msgs/msg/apollodrivers_racobit_radar.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_radar_obs.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_radar_state201.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_cluster_list_status600.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_object_list_status60_a.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRacobitRadar &msg) ;
    ApollodriversRacobitRadar from_json_ApollodriversRacobitRadar (nlohmann::json obj) ;
    template <>
    ApollodriversRacobitRadar from_json<ApollodriversRacobitRadar>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRacobitRadar &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversRacobitRadar & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRacobitRadar & dt);
}
