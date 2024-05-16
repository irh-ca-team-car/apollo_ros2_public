#pragma once
#include "apollo_msgs/msg/apollolocalization_integ_measure.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationIntegMeasure &msg) ;
    ApollolocalizationIntegMeasure from_json_ApollolocalizationIntegMeasure (nlohmann::json obj) ;
    template <>
    ApollolocalizationIntegMeasure from_json<ApollolocalizationIntegMeasure>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationIntegMeasure &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationIntegMeasure & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationIntegMeasure & dt);
}
