#pragma once
#include "apollo_msgs/msg/apollocanbus_transit.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_vehiclelimits24.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_adc_motioncontrol110.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_adc_motioncontrollimits112.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_motionfeedback120.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_motionfeedback221.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_motioncommandfeedback122.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_vehiclestatus25.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_auxiliaryfeedback120.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_diag_fault620.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_diag_steeringcontrol722.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_adc_auxiliarycontrol110.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_llc_diag_brakecontrol721.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTransit &msg) ;
    ApollocanbusTransit from_json_ApollocanbusTransit (nlohmann::json obj) ;
    template <>
    ApollocanbusTransit from_json<ApollocanbusTransit>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTransit &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTransit & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTransit & dt);
}
