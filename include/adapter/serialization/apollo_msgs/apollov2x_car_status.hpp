#pragma once
#include "apollo_msgs/msg/apollov2x_car_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollolocalization_localization_estimate.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_chassis_detail.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_junction.hpp"
#include "adapter/serialization/apollo_msgs/apollov2x_id.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xCarStatus &msg) ;
    Apollov2xCarStatus from_json_Apollov2xCarStatus (nlohmann::json obj) ;
    template <>
    Apollov2xCarStatus from_json<Apollov2xCarStatus>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xCarStatus &dt);
    std::ostream & operator<<(std::ostream & os, const Apollov2xCarStatus & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xCarStatus & dt);
}
