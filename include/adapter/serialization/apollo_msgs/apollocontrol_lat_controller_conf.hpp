#pragma once
#include "apollo_msgs/msg/apollocontrol_lat_controller_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocontrol_gain_scheduler.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_leadlag_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_mrac_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolLatControllerConf &msg) ;
    ApollocontrolLatControllerConf from_json_ApollocontrolLatControllerConf (nlohmann::json obj) ;
    template <>
    ApollocontrolLatControllerConf from_json<ApollocontrolLatControllerConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolLatControllerConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolLatControllerConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolLatControllerConf & dt);
}
