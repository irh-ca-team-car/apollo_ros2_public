#pragma once
#include "apollo_msgs/msg/apollodata_software_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodata_software_infoconfigs.hpp"
#include "adapter/serialization/apollo_msgs/apollorouting_routing_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataSoftwareInfo &msg) ;
    ApollodataSoftwareInfo from_json_ApollodataSoftwareInfo (nlohmann::json obj) ;
    template <>
    ApollodataSoftwareInfo from_json<ApollodataSoftwareInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataSoftwareInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodataSoftwareInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataSoftwareInfo & dt);
}
