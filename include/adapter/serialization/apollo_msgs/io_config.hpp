#pragma once
#include "apollo_msgs/msg/io_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const IoConfig &msg) ;
    IoConfig from_json_IoConfig (nlohmann::json obj) ;
    template <>
    IoConfig from_json<IoConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, IoConfig &dt);
    std::ostream & operator<<(std::ostream & os, const IoConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const IoConfig & dt);
}
