#pragma once
#include "apollo_msgs/msg/apollodriverssmartereyeconfig_config_compress_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverssmartereyeconfigConfigCompressConfig &msg) ;
    ApollodriverssmartereyeconfigConfigCompressConfig from_json_ApollodriverssmartereyeconfigConfigCompressConfig (nlohmann::json obj) ;
    template <>
    ApollodriverssmartereyeconfigConfigCompressConfig from_json<ApollodriverssmartereyeconfigConfigCompressConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverssmartereyeconfigConfigCompressConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriverssmartereyeconfigConfigCompressConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverssmartereyeconfigConfigCompressConfig & dt);
}
