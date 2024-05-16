#pragma once
#include "apollo_msgs/msg/modulesteleopdaemon_daemon_cmd.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ModulesteleopdaemonDaemonCmd &msg) ;
    ModulesteleopdaemonDaemonCmd from_json_ModulesteleopdaemonDaemonCmd (nlohmann::json obj) ;
    template <>
    ModulesteleopdaemonDaemonCmd from_json<ModulesteleopdaemonDaemonCmd>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ModulesteleopdaemonDaemonCmd &dt);
    std::ostream & operator<<(std::ostream & os, const ModulesteleopdaemonDaemonCmd & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ModulesteleopdaemonDaemonCmd & dt);
}
