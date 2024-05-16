#pragma once
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_detection2_d_array.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_detection2_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsDetection2DArray &msg) ;
    ApollocontriblgsvlMsgsDetection2DArray from_json_ApollocontriblgsvlMsgsDetection2DArray (nlohmann::json obj) ;
    template <>
    ApollocontriblgsvlMsgsDetection2DArray from_json<ApollocontriblgsvlMsgsDetection2DArray>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsDetection2DArray &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsDetection2DArray & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsDetection2DArray & dt);
}
