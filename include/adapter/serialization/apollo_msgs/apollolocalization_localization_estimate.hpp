#pragma once
#include "apollo_msgs/msg/apollolocalization_localization_estimate.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_pose.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_uncertainty.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_msf_status.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_msf_sensor_msg_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationLocalizationEstimate &msg) ;
    ApollolocalizationLocalizationEstimate from_json_ApollolocalizationLocalizationEstimate (nlohmann::json obj) ;
    template <>
    ApollolocalizationLocalizationEstimate from_json<ApollolocalizationLocalizationEstimate>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationLocalizationEstimate &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationLocalizationEstimate & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationLocalizationEstimate & dt);
}
