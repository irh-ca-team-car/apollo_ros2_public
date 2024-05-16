#pragma once
#include "apollo_msgs/msg/apollolocalization_msf_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationMsfStatus &msg) ;
    ApollolocalizationMsfStatus from_json_ApollolocalizationMsfStatus (nlohmann::json obj) ;
    template <>
    ApollolocalizationMsfStatus from_json<ApollolocalizationMsfStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationMsfStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationMsfStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationMsfStatus & dt);
}
