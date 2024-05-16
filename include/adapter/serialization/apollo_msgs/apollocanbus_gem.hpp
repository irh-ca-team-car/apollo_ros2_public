#pragma once
#include "apollo_msgs/msg/apollocanbus_gem.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_global_rpt6a.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_cmd6b.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_rpt6c.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_cmd6d.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_rpt16e.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wheel_speed_rpt7a.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_date_time_rpt83.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_motor_rpt170.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_headlight_rpt77.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_accel_rpt68.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_motor_rpt375.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_turn_cmd63.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_turn_rpt64.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_shift_cmd65.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_shift_rpt66.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_accel_cmd67.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_lat_lon_heading_rpt82.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_global_cmd69.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_parking_brake_status_rpt80.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_yaw_rate_rpt81.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_horn_rpt79.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_horn_cmd78.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wiper_rpt91.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_speed_rpt6f.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_headlight_cmd76.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_motor_rpt274.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_motor_rpt271.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_steering_motor_rpt173.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wiper_cmd90.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake_motor_rpt372.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGem &msg) ;
    ApollocanbusGem from_json_ApollocanbusGem (nlohmann::json obj) ;
    template <>
    ApollocanbusGem from_json<ApollocanbusGem>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGem &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGem & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGem & dt);
}
