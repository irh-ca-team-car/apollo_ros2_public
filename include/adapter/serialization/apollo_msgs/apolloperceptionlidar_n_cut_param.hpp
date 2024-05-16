#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_n_cut_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarNCutParam &msg) ;
    ApolloperceptionlidarNCutParam from_json_ApolloperceptionlidarNCutParam (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarNCutParam from_json<ApolloperceptionlidarNCutParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarNCutParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarNCutParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarNCutParam & dt);
}
