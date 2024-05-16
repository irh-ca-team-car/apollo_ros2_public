#pragma once
#include "apollo_msgs/msg/apollocanbus_vehicle_state_feedback2_c4.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleStateFeedback2C4 &msg) ;
    ApollocanbusVehicleStateFeedback2C4 from_json_ApollocanbusVehicleStateFeedback2C4 (nlohmann::json obj) ;
    template <>
    ApollocanbusVehicleStateFeedback2C4 from_json<ApollocanbusVehicleStateFeedback2C4>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleStateFeedback2C4 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleStateFeedback2C4 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleStateFeedback2C4 & dt);
}
