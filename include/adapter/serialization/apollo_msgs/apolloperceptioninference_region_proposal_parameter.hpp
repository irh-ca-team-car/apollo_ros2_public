#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_region_proposal_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_anchor_box.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_non_maximum_suppression_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceRegionProposalParameter &msg) ;
    ApolloperceptioninferenceRegionProposalParameter from_json_ApolloperceptioninferenceRegionProposalParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceRegionProposalParameter from_json<ApolloperceptioninferenceRegionProposalParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceRegionProposalParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceRegionProposalParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceRegionProposalParameter & dt);
}
