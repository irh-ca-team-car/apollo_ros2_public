#pragma once
#include "apollo_msgs/msg/apollocanbus_dash_controls_right_cmd110.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDashControlsRightCmd110 &msg) ;
    ApollocanbusDashControlsRightCmd110 from_json_ApollocanbusDashControlsRightCmd110 (nlohmann::json obj) ;
    template <>
    ApollocanbusDashControlsRightCmd110 from_json<ApollocanbusDashControlsRightCmd110>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDashControlsRightCmd110 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDashControlsRightCmd110 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDashControlsRightCmd110 & dt);
}
