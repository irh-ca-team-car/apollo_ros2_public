#pragma once
#include "apollo_msgs/msg/apollocanbus_zhongyun.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_gear_control_a1.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_torque_control_a3.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_control_a2.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_parking_control_a5.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_control_a4.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_enable_state_feedback_c3.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_state_feedback_c1.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_error_state_e1.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_state_feedback2_c4.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusZhongyun &msg) ;
    ApollocanbusZhongyun from_json_ApollocanbusZhongyun (nlohmann::json obj) ;
    template <>
    ApollocanbusZhongyun from_json<ApollocanbusZhongyun>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusZhongyun &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusZhongyun & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusZhongyun & dt);
}
