#pragma once
#include "apollo_msgs/msg/apollocanbus_dash_controls_left_cmd10c.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDashControlsLeftCmd10c &msg) ;
    ApollocanbusDashControlsLeftCmd10c from_json_ApollocanbusDashControlsLeftCmd10c (nlohmann::json obj) ;
    template <>
    ApollocanbusDashControlsLeftCmd10c from_json<ApollocanbusDashControlsLeftCmd10c>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDashControlsLeftCmd10c &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDashControlsLeftCmd10c & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDashControlsLeftCmd10c & dt);
}
