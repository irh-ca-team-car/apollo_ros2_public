#pragma once
#include "apollo_msgs/msg/apollodriversgnss_epoch_observation.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodriversgnss_satellite_observation.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssEpochObservation &msg) ;
    ApollodriversgnssEpochObservation from_json_ApollodriversgnssEpochObservation (nlohmann::json obj) ;
    template <>
    ApollodriversgnssEpochObservation from_json<ApollodriversgnssEpochObservation>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssEpochObservation &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssEpochObservation & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssEpochObservation & dt);
}
