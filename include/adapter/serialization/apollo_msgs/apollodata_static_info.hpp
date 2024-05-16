#pragma once
#include "apollo_msgs/msg/apollodata_static_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodata_vehicle_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_environment_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_hardware_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_software_info.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_user_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataStaticInfo &msg) ;
    ApollodataStaticInfo from_json_ApollodataStaticInfo (nlohmann::json obj) ;
    template <>
    ApollodataStaticInfo from_json<ApollodataStaticInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataStaticInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataStaticInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataStaticInfo & dt);
}
