#pragma once
#include "apollo_msgs/msg/apollolocalization_corrected_imu.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_pose.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationCorrectedImu &msg) ;
    ApollolocalizationCorrectedImu from_json_ApollolocalizationCorrectedImu (nlohmann::json obj) ;
    template <>
    ApollolocalizationCorrectedImu from_json<ApollolocalizationCorrectedImu>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationCorrectedImu &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationCorrectedImu & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationCorrectedImu & dt);
}
