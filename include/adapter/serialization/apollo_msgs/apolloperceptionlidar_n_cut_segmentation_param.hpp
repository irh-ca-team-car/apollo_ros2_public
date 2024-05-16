#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_n_cut_segmentation_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_n_cut_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarNCutSegmentationParam &msg) ;
    ApolloperceptionlidarNCutSegmentationParam from_json_ApolloperceptionlidarNCutSegmentationParam (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarNCutSegmentationParam from_json<ApolloperceptionlidarNCutSegmentationParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarNCutSegmentationParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarNCutSegmentationParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarNCutSegmentationParam & dt);
}
