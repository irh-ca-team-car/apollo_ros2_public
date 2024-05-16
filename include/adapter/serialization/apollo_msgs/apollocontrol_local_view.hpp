#pragma once
#include "apollo_msgs/msg/apollocontrol_local_view.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_chassis.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_adc_trajectory.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_localization_estimate.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_pad_message.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolLocalView &msg) ;
    ApollocontrolLocalView from_json_ApollocontrolLocalView (nlohmann::json obj) ;
    template <>
    ApollocontrolLocalView from_json<ApollocontrolLocalView>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolLocalView &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolLocalView & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolLocalView & dt);
}
