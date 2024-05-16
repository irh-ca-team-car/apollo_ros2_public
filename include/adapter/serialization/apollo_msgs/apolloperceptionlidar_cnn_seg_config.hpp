#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_cnn_seg_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarCNNSegConfig &msg) ;
    ApolloperceptionlidarCNNSegConfig from_json_ApolloperceptionlidarCNNSegConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarCNNSegConfig from_json<ApolloperceptionlidarCNNSegConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarCNNSegConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarCNNSegConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarCNNSegConfig & dt);
}
