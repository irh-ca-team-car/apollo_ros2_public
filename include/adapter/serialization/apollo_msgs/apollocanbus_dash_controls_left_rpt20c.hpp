#pragma once
#include "apollo_msgs/msg/apollocanbus_dash_controls_left_rpt20c.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDashControlsLeftRpt20c &msg) ;
    ApollocanbusDashControlsLeftRpt20c from_json_ApollocanbusDashControlsLeftRpt20c (nlohmann::json obj) ;
    template <>
    ApollocanbusDashControlsLeftRpt20c from_json<ApollocanbusDashControlsLeftRpt20c>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDashControlsLeftRpt20c &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDashControlsLeftRpt20c & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDashControlsLeftRpt20c & dt);
}
