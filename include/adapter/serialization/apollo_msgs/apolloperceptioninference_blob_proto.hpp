#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_blob_proto.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_shape.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBlobProto &msg) ;
    ApolloperceptioninferenceBlobProto from_json_ApolloperceptioninferenceBlobProto (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceBlobProto from_json<ApolloperceptioninferenceBlobProto>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBlobProto &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBlobProto & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBlobProto & dt);
}
