#pragma once
#include "apollo_msgs/msg/apolloplanning_main_decisiontask.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_main_cruise.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_stop.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_emergency_stop.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_change_lane.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_mission_complete.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_not_ready.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_main_parking.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainDecisiontask &msg) ;
    ApolloplanningMainDecisiontask from_json_ApolloplanningMainDecisiontask (nlohmann::json obj) ;
    template <>
    ApolloplanningMainDecisiontask from_json<ApolloplanningMainDecisiontask>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainDecisiontask &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainDecisiontask & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainDecisiontask & dt);
}
