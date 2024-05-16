#pragma once
#include "apollo_msgs/msg/apollodriverscameraconfig_config_compress_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscameraconfigConfigCompressConfig &msg) ;
    ApollodriverscameraconfigConfigCompressConfig from_json_ApollodriverscameraconfigConfigCompressConfig (nlohmann::json obj) ;
    template <>
    ApollodriverscameraconfigConfigCompressConfig from_json<ApollodriverscameraconfigConfigCompressConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscameraconfigConfigCompressConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriverscameraconfigConfigCompressConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscameraconfigConfigCompressConfig & dt);
}
