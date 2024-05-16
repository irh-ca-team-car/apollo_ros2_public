#pragma once
#include "apollo_msgs/msg/modulesteleopmodem_modem_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ModulesteleopmodemModemInfo &msg) ;
    ModulesteleopmodemModemInfo from_json_ModulesteleopmodemModemInfo (nlohmann::json obj) ;
    template <>
    ModulesteleopmodemModemInfo from_json<ModulesteleopmodemModemInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ModulesteleopmodemModemInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ModulesteleopmodemModemInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ModulesteleopmodemModemInfo & dt);
}
