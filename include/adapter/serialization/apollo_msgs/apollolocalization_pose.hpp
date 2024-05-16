#pragma once
#include "apollo_msgs/msg/apollolocalization_pose.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_quaternion.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationPose &msg) ;
    ApollolocalizationPose from_json_ApollolocalizationPose (nlohmann::json obj) ;
    template <>
    ApollolocalizationPose from_json<ApollolocalizationPose>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationPose &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationPose & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationPose & dt);
}
