#pragma once
#include "apollo_msgs/msg/apollocanbus_brake_aux_rpt304.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeAuxRpt304 &msg) ;
    ApollocanbusBrakeAuxRpt304 from_json_ApollocanbusBrakeAuxRpt304 (nlohmann::json obj) ;
    template <>
    ApollocanbusBrakeAuxRpt304 from_json<ApollocanbusBrakeAuxRpt304>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeAuxRpt304 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeAuxRpt304 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeAuxRpt304 & dt);
}
