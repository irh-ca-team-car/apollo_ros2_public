#pragma once
#include "apollo_msgs/msg/apollov2x_v2_x_obstacle.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperception_perception_obstacle.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_v2_x_information.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xV2XObstacle &msg) ;
    Apollov2xV2XObstacle from_json_Apollov2xV2XObstacle (nlohmann::json obj) ;
    template <>
    Apollov2xV2XObstacle from_json<Apollov2xV2XObstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xV2XObstacle &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xV2XObstacle & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xV2XObstacle & dt);
}
