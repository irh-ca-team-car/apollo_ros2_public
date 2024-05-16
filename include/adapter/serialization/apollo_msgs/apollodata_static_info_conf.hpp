#pragma once
#include "apollo_msgs/msg/apollodata_static_info_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataStaticInfoConf &msg) ;
    ApollodataStaticInfoConf from_json_ApollodataStaticInfoConf (nlohmann::json obj) ;
    template <>
    ApollodataStaticInfoConf from_json<ApollodataStaticInfoConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataStaticInfoConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataStaticInfoConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataStaticInfoConf & dt);
}
