#pragma once
#include "apollo_msgs/msg/classify_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/dense_parameter.hpp"
#include "adapter/serialization/apollo_msgs/activation_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ClassifyParameter &msg) ;
    ClassifyParameter from_json_ClassifyParameter (nlohmann::json obj) ;
    template <>
    ClassifyParameter from_json<ClassifyParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ClassifyParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ClassifyParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ClassifyParameter & dt);
}
