#pragma once
#include "apollo_msgs/msg/apollocommon_drive_event.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_pose.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonDriveEvent &msg) ;
    ApollocommonDriveEvent from_json_ApollocommonDriveEvent (nlohmann::json obj) ;
    template <>
    ApollocommonDriveEvent from_json<ApollocommonDriveEvent>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonDriveEvent &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonDriveEvent & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonDriveEvent & dt);
}
