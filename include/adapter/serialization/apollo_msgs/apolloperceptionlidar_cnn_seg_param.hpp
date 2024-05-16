#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_cnn_seg_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_network_param.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_feature_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarCNNSegParam &msg) ;
    ApolloperceptionlidarCNNSegParam from_json_ApolloperceptionlidarCNNSegParam (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarCNNSegParam from_json<ApolloperceptionlidarCNNSegParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarCNNSegParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarCNNSegParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarCNNSegParam & dt);
}
