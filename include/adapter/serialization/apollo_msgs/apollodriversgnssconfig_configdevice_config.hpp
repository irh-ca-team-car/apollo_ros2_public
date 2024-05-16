#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_configdevice_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_novatel_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigConfigdeviceConfig &msg) ;
    ApollodriversgnssconfigConfigdeviceConfig from_json_ApollodriversgnssconfigConfigdeviceConfig (nlohmann::json obj) ;
    template <>
    ApollodriversgnssconfigConfigdeviceConfig from_json<ApollodriversgnssconfigConfigdeviceConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigConfigdeviceConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigConfigdeviceConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigConfigdeviceConfig & dt);
}
