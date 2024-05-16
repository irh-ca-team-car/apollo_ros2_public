#pragma once
#include "apollo_msgs/msg/apollov2x_v2_x_information.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollov2x_point.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_abnormal_information.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xV2XInformation &msg) ;
    Apollov2xV2XInformation from_json_Apollov2xV2XInformation (nlohmann::json obj) ;
    template <>
    Apollov2xV2XInformation from_json<Apollov2xV2XInformation>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xV2XInformation &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xV2XInformation & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xV2XInformation & dt);
}
