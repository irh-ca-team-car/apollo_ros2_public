#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_novatel_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigNovatelConfig &msg) ;
    ApollodriversgnssconfigNovatelConfig from_json_ApollodriversgnssconfigNovatelConfig (nlohmann::json obj) ;
    template <>
    ApollodriversgnssconfigNovatelConfig from_json<ApollodriversgnssconfigNovatelConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigNovatelConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigNovatelConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigNovatelConfig & dt);
}
