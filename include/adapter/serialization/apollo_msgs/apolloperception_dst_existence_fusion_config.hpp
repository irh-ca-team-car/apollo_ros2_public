#pragma once
#include "apollo_msgs/msg/apolloperception_dst_existence_fusion_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_camera_valid_dist.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionDstExistenceFusionConfig &msg) ;
    ApolloperceptionDstExistenceFusionConfig from_json_ApolloperceptionDstExistenceFusionConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionDstExistenceFusionConfig from_json<ApolloperceptionDstExistenceFusionConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionDstExistenceFusionConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionDstExistenceFusionConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionDstExistenceFusionConfig & dt);
}
