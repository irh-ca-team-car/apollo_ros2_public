#pragma once
#include "apollo_msgs/msg/apolloplanning_localization_feature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLocalizationFeature &msg) ;
    ApolloplanningLocalizationFeature from_json_ApolloplanningLocalizationFeature (nlohmann::json obj) ;
    template <>
    ApolloplanningLocalizationFeature from_json<ApolloplanningLocalizationFeature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLocalizationFeature &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLocalizationFeature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLocalizationFeature & dt);
}
