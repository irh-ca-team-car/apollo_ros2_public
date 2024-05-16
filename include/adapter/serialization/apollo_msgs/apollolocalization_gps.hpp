#pragma once
#include "apollo_msgs/msg/apollolocalization_gps.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_pose.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationGps &msg) ;
    ApollolocalizationGps from_json_ApollolocalizationGps (nlohmann::json obj) ;
    template <>
    ApollolocalizationGps from_json<ApollolocalizationGps>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationGps &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationGps & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationGps & dt);
}
