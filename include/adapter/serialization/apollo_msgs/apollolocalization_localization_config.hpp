#pragma once
#include "apollo_msgs/msg/apollolocalization_localization_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationLocalizationConfig &msg) ;
    ApollolocalizationLocalizationConfig from_json_ApollolocalizationLocalizationConfig (nlohmann::json obj) ;
    template <>
    ApollolocalizationLocalizationConfig from_json<ApollolocalizationLocalizationConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationLocalizationConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationLocalizationConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationLocalizationConfig & dt);
}
