#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_tf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigTF &msg) ;
    ApollodriversgnssconfigTF from_json_ApollodriversgnssconfigTF (nlohmann::json obj) ;
    template <>
    ApollodriversgnssconfigTF from_json<ApollodriversgnssconfigTF>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigTF &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigTF & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigTF & dt);
}
