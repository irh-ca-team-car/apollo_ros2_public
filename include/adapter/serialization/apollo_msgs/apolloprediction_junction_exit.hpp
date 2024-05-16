#pragma once
#include "apollo_msgs/msg/apolloprediction_junction_exit.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionJunctionExit &msg) ;
    ApollopredictionJunctionExit from_json_ApollopredictionJunctionExit (nlohmann::json obj) ;
    template <>
    ApollopredictionJunctionExit from_json<ApollopredictionJunctionExit>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionJunctionExit &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionJunctionExit & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionJunctionExit & dt);
}
