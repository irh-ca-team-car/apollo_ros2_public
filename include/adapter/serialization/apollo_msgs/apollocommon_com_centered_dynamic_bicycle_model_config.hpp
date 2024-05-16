#pragma once
#include "apollo_msgs/msg/apollocommon_com_centered_dynamic_bicycle_model_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonComCenteredDynamicBicycleModelConfig &msg) ;
    ApollocommonComCenteredDynamicBicycleModelConfig from_json_ApollocommonComCenteredDynamicBicycleModelConfig (nlohmann::json obj) ;
    template <>
    ApollocommonComCenteredDynamicBicycleModelConfig from_json<ApollocommonComCenteredDynamicBicycleModelConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonComCenteredDynamicBicycleModelConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonComCenteredDynamicBicycleModelConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonComCenteredDynamicBicycleModelConfig & dt);
}
