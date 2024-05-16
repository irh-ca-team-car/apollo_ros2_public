#pragma once
#include "apollo_msgs/msg/apollov2x_abnormal_information.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xAbnormalInformation &msg) ;
    Apollov2xAbnormalInformation from_json_Apollov2xAbnormalInformation (nlohmann::json obj) ;
    template <>
    Apollov2xAbnormalInformation from_json<Apollov2xAbnormalInformation>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xAbnormalInformation &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xAbnormalInformation & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xAbnormalInformation & dt);
}
