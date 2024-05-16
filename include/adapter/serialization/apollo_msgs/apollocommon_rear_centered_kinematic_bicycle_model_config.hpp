#pragma once
#include "apollo_msgs/msg/apollocommon_rear_centered_kinematic_bicycle_model_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonRearCenteredKinematicBicycleModelConfig &msg) ;
    ApollocommonRearCenteredKinematicBicycleModelConfig from_json_ApollocommonRearCenteredKinematicBicycleModelConfig (nlohmann::json obj) ;
    template <>
    ApollocommonRearCenteredKinematicBicycleModelConfig from_json<ApollocommonRearCenteredKinematicBicycleModelConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonRearCenteredKinematicBicycleModelConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonRearCenteredKinematicBicycleModelConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonRearCenteredKinematicBicycleModelConfig & dt);
}
