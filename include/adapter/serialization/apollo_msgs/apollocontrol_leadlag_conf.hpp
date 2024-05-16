#pragma once
#include "apollo_msgs/msg/apollocontrol_leadlag_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolLeadlagConf &msg) ;
    ApollocontrolLeadlagConf from_json_ApollocontrolLeadlagConf (nlohmann::json obj) ;
    template <>
    ApollocontrolLeadlagConf from_json<ApollocontrolLeadlagConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolLeadlagConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolLeadlagConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolLeadlagConf & dt);
}
