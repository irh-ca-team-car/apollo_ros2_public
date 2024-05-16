#pragma once
#include "apollo_msgs/msg/apollocontrol_filter_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolFilterConf &msg) ;
    ApollocontrolFilterConf from_json_ApollocontrolFilterConf (nlohmann::json obj) ;
    template <>
    ApollocontrolFilterConf from_json<ApollocontrolFilterConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolFilterConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolFilterConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolFilterConf & dt);
}
