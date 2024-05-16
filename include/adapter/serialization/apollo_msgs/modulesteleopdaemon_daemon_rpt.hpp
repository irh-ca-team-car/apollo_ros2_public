#pragma once
#include "apollo_msgs/msg/modulesteleopdaemon_daemon_rpt.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ModulesteleopdaemonDaemonRpt &msg) ;
    ModulesteleopdaemonDaemonRpt from_json_ModulesteleopdaemonDaemonRpt (nlohmann::json obj) ;
    template <>
    ModulesteleopdaemonDaemonRpt from_json<ModulesteleopdaemonDaemonRpt>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ModulesteleopdaemonDaemonRpt &dt);
    std::ostream & operator<<(std::ostream & os, const ModulesteleopdaemonDaemonRpt & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ModulesteleopdaemonDaemonRpt & dt);
}
