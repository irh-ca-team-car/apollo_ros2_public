#pragma once
#include "apollo_msgs/msg/apollocontrol_pid_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolPidConf &msg) ;
    ApollocontrolPidConf from_json_ApollocontrolPidConf (nlohmann::json obj) ;
    template <>
    ApollocontrolPidConf from_json<ApollocontrolPidConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolPidConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolPidConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolPidConf & dt);
}
