#pragma once
#include "apollo_msgs/msg/apollocontrol_preprocessor.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_local_view.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_engage_advice.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_input_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolPreprocessor &msg) ;
    ApollocontrolPreprocessor from_json_ApollocontrolPreprocessor (nlohmann::json obj) ;
    template <>
    ApollocontrolPreprocessor from_json<ApollocontrolPreprocessor>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolPreprocessor &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontrolPreprocessor & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolPreprocessor & dt);
}
