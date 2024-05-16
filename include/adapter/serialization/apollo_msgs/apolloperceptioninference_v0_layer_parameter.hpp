#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_v0_layer_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_proto.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hdf5_output_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceV0LayerParameter &msg) ;
    ApolloperceptioninferenceV0LayerParameter from_json_ApolloperceptioninferenceV0LayerParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceV0LayerParameter from_json<ApolloperceptioninferenceV0LayerParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceV0LayerParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceV0LayerParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceV0LayerParameter & dt);
}
