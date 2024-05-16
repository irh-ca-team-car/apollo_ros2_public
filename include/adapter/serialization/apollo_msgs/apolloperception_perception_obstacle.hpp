#pragma once
#include "apollo_msgs/msg/apolloperception_perception_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_b_box2_d.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_sensor_measurement.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_light_status.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_debug_message.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_v2_x_information.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionPerceptionObstacle &msg) ;
    ApolloperceptionPerceptionObstacle from_json_ApolloperceptionPerceptionObstacle (nlohmann::json obj) ;
    template <>
    ApolloperceptionPerceptionObstacle from_json<ApolloperceptionPerceptionObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionPerceptionObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionPerceptionObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionPerceptionObstacle & dt);
}
