#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream.hpp"
#include "adapter/serialization/apollo_msgs/bytes.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_configdevice_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_tf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigConfig &msg) ;
    ApollodriversgnssconfigConfig from_json_ApollodriversgnssconfigConfig (nlohmann::json obj) ;
    template <>
    ApollodriversgnssconfigConfig from_json<ApollodriversgnssconfigConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigConfig & dt);
}
