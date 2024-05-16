#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_blob_shape.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBlobShape &msg) ;
    ApolloperceptioninferenceBlobShape from_json_ApolloperceptioninferenceBlobShape (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceBlobShape from_json<ApolloperceptioninferenceBlobShape>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBlobShape &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBlobShape & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBlobShape & dt);
}
