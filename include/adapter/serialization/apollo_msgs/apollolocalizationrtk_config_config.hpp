#pragma once
#include "apollo_msgs/msg/apollolocalizationrtk_config_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationrtkConfigConfig &msg) ;
    ApollolocalizationrtkConfigConfig from_json_ApollolocalizationrtkConfigConfig (nlohmann::json obj) ;
    template <>
    ApollolocalizationrtkConfigConfig from_json<ApollolocalizationrtkConfigConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationrtkConfigConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationrtkConfigConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationrtkConfigConfig & dt);
}
