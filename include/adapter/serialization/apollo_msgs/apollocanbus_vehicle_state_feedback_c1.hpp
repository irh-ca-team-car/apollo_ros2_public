#pragma once
#include "apollo_msgs/msg/apollocanbus_vehicle_state_feedback_c1.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleStateFeedbackC1 &msg) ;
    ApollocanbusVehicleStateFeedbackC1 from_json_ApollocanbusVehicleStateFeedbackC1 (nlohmann::json obj) ;
    template <>
    ApollocanbusVehicleStateFeedbackC1 from_json<ApollocanbusVehicleStateFeedbackC1>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleStateFeedbackC1 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleStateFeedbackC1 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleStateFeedbackC1 & dt);
}
