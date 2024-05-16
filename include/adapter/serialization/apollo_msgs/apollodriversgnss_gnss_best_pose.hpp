#pragma once
#include "apollo_msgs/msg/apollodriversgnss_gnss_best_pose.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssGnssBestPose &msg) ;
    ApollodriversgnssGnssBestPose from_json_ApollodriversgnssGnssBestPose (nlohmann::json obj) ;
    template <>
    ApollodriversgnssGnssBestPose from_json<ApollodriversgnssGnssBestPose>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssGnssBestPose &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssGnssBestPose & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssGnssBestPose & dt);
}
