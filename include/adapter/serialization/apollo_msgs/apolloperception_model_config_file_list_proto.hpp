#pragma once
#include "apollo_msgs/msg/apolloperception_model_config_file_list_proto.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionModelConfigFileListProto &msg) ;
    ApolloperceptionModelConfigFileListProto from_json_ApolloperceptionModelConfigFileListProto (nlohmann::json obj) ;
    template <>
    ApolloperceptionModelConfigFileListProto from_json<ApolloperceptionModelConfigFileListProto>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionModelConfigFileListProto &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionModelConfigFileListProto & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionModelConfigFileListProto & dt);
}
