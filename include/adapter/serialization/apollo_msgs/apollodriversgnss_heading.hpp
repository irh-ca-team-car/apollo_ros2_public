#pragma once
#include "apollo_msgs/msg/apollodriversgnss_heading.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssHeading &msg) ;
    ApollodriversgnssHeading from_json_ApollodriversgnssHeading (nlohmann::json obj) ;
    template <>
    ApollodriversgnssHeading from_json<ApollodriversgnssHeading>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssHeading &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssHeading & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssHeading & dt);
}
