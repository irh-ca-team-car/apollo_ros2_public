#pragma once
#include "apollo_msgs/msg/matrix.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/vector.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Matrix &msg) ;
    Matrix from_json_Matrix (nlohmann::json obj) ;
    template <>
    Matrix from_json<Matrix>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Matrix &dt);
    std::ostream & operator<<(std::ostream & os, const Matrix & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Matrix & dt);
}
