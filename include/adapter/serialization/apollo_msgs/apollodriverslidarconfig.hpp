#pragma once
#include "apollo_msgs/msg/apollodriverslidarconfig.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodrivershesai_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversrobosense_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollodriverslidarconfig &msg) ;
    Apollodriverslidarconfig from_json_Apollodriverslidarconfig (nlohmann::json obj) ;
    template <>
    Apollodriverslidarconfig from_json<Apollodriverslidarconfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollodriverslidarconfig &dt);
    std::ostream & operator<<(std::ostream & os, const Apollodriverslidarconfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollodriverslidarconfig & dt);
}
