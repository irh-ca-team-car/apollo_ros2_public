#pragma once
#include "apollo_msgs/msg/dense_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/tensor_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const DenseParameter &msg) ;
    DenseParameter from_json_DenseParameter (nlohmann::json obj) ;
    template <>
    DenseParameter from_json<DenseParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, DenseParameter &dt);
    std::ostream & operator<<(std::ostream & os, const DenseParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const DenseParameter & dt);
}
