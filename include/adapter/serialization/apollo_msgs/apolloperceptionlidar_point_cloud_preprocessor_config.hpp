#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_point_cloud_preprocessor_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarPointCloudPreprocessorConfig &msg) ;
    ApolloperceptionlidarPointCloudPreprocessorConfig from_json_ApolloperceptionlidarPointCloudPreprocessorConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarPointCloudPreprocessorConfig from_json<ApolloperceptionlidarPointCloudPreprocessorConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarPointCloudPreprocessorConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarPointCloudPreprocessorConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarPointCloudPreprocessorConfig & dt);
}
