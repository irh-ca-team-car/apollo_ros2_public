#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_dummy_data_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_shape.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDummyDataParameter &msg) ;
    ApolloperceptioninferenceDummyDataParameter from_json_ApolloperceptioninferenceDummyDataParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceDummyDataParameter from_json<ApolloperceptioninferenceDummyDataParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDummyDataParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDummyDataParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDummyDataParameter & dt);
}
