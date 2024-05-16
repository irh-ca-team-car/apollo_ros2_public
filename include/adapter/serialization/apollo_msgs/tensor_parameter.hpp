#pragma once
#include "apollo_msgs/msg/tensor_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const TensorParameter &msg) ;
    TensorParameter from_json_TensorParameter (nlohmann::json obj) ;
    template <>
    TensorParameter from_json<TensorParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, TensorParameter &dt);
    std::ostream & operator<<(std::ostream & os, const TensorParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const TensorParameter & dt);
}
