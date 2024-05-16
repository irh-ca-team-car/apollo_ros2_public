#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_stream.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_streamtype.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStream &msg) ;
    ApollodriversgnssconfigStream from_json_ApollodriversgnssconfigStream (nlohmann::json obj) ;
    template <>
    ApollodriversgnssconfigStream from_json<ApollodriversgnssconfigStream>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStream &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStream & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStream & dt);
}
