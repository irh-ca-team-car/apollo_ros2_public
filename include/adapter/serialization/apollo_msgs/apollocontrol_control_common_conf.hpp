#pragma once
#include "apollo_msgs/msg/apollocontrol_control_common_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolControlCommonConf &msg) ;
    ApollocontrolControlCommonConf from_json_ApollocontrolControlCommonConf (nlohmann::json obj) ;
    template <>
    ApollocontrolControlCommonConf from_json<ApollocontrolControlCommonConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolControlCommonConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolControlCommonConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolControlCommonConf & dt);
}
