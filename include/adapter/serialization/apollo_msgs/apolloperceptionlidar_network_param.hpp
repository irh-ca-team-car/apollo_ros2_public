#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_network_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarNetworkParam &msg) ;
    ApolloperceptionlidarNetworkParam from_json_ApolloperceptionlidarNetworkParam (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarNetworkParam from_json<ApolloperceptionlidarNetworkParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarNetworkParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarNetworkParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarNetworkParam & dt);
}
