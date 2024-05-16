#pragma once
#include "apollo_msgs/msg/apollolocalization_localization_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationLocalizationStatus &msg) ;
    ApollolocalizationLocalizationStatus from_json_ApollolocalizationLocalizationStatus (nlohmann::json obj) ;
    template <>
    ApollolocalizationLocalizationStatus from_json<ApollolocalizationLocalizationStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationLocalizationStatus &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationLocalizationStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationLocalizationStatus & dt);
}
