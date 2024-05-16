#pragma once
#include "apollo_msgs/msg/apolloplanning_scenario_configscenario_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_bare_intersection_unprotected_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_emergency_pull_over_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_emergency_stop_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_park_and_go_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_pull_over_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_stop_sign_unprotected_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_traffic_light_protected_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_traffic_light_unprotected_left_turn_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_traffic_light_unprotected_right_turn_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_valet_parking_config.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_yield_sign_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioConfigscenarioConfig &msg) ;
    ApolloplanningScenarioConfigscenarioConfig from_json_ApolloplanningScenarioConfigscenarioConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningScenarioConfigscenarioConfig from_json<ApolloplanningScenarioConfigscenarioConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioConfigscenarioConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioConfigscenarioConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioConfigscenarioConfig & dt);
}
