#pragma once
#include "apollo_msgs/msg/apolloimage_decompress_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloimageDecompressConfig &msg) ;
    ApolloimageDecompressConfig from_json_ApolloimageDecompressConfig (nlohmann::json obj) ;
    template <>
    ApolloimageDecompressConfig from_json<ApolloimageDecompressConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloimageDecompressConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloimageDecompressConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloimageDecompressConfig & dt);
}
