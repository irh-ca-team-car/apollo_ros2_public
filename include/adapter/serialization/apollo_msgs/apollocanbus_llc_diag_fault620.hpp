#pragma once
#include "apollo_msgs/msg/apollocanbus_llc_diag_fault620.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcDiagFault620 &msg) ;
    ApollocanbusLlcDiagFault620 from_json_ApollocanbusLlcDiagFault620 (nlohmann::json obj) ;
    template <>
    ApollocanbusLlcDiagFault620 from_json<ApollocanbusLlcDiagFault620>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcDiagFault620 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcDiagFault620 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcDiagFault620 & dt);
}
