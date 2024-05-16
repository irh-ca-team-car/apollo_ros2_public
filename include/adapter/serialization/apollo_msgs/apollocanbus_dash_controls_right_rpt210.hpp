#pragma once
#include "apollo_msgs/msg/apollocanbus_dash_controls_right_rpt210.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDashControlsRightRpt210 &msg) ;
    ApollocanbusDashControlsRightRpt210 from_json_ApollocanbusDashControlsRightRpt210 (nlohmann::json obj) ;
    template <>
    ApollocanbusDashControlsRightRpt210 from_json<ApollocanbusDashControlsRightRpt210>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDashControlsRightRpt210 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDashControlsRightRpt210 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDashControlsRightRpt210 & dt);
}
