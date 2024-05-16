#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_streamtype.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStreamtype &msg) ;
    ApollodriversgnssconfigStreamtype from_json_ApollodriversgnssconfigStreamtype (nlohmann::json obj) ;
    template <>
    ApollodriversgnssconfigStreamtype from_json<ApollodriversgnssconfigStreamtype>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStreamtype &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStreamtype & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStreamtype & dt);
}
