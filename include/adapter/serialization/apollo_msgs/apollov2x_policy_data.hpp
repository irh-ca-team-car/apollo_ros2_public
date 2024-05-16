#pragma once
#include "apollo_msgs/msg/apollov2x_policy_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2x_map.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_spat.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xPolicyData &msg) ;
    Apollov2xPolicyData from_json_Apollov2xPolicyData (nlohmann::json obj) ;
    template <>
    Apollov2xPolicyData from_json<Apollov2xPolicyData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xPolicyData &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xPolicyData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xPolicyData & dt);
}
