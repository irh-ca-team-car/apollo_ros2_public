#pragma once
#include "apollo_msgs/msg/layer.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/matrix.hpp"
#include "adapter/serialization/apollo_msgs/vector.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Layer &msg) ;
    Layer from_json_Layer (nlohmann::json obj) ;
    template <>
    Layer from_json<Layer>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Layer &dt);
    std::ostream & operator<<(std::ostream & os, const Layer & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Layer & dt);
}
