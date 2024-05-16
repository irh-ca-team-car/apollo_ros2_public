#pragma once
#include "apollo_msgs/msg/fnn_model.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/vector.hpp"
#include "adapter/serialization/apollo_msgs/layer.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const FnnModel &msg) ;
    FnnModel from_json_FnnModel (nlohmann::json obj) ;
    template <>
    FnnModel from_json<FnnModel>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, FnnModel &dt);
    std::ostream & operator<<(std::ostream & os, const FnnModel & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const FnnModel & dt);
}
