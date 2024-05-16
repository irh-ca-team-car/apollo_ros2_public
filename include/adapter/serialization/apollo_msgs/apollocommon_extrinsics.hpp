#pragma once
#include "apollo_msgs/msg/apollocommon_extrinsics.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_transform.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonExtrinsics &msg) ;
    ApollocommonExtrinsics from_json_ApollocommonExtrinsics (nlohmann::json obj) ;
    template <>
    ApollocommonExtrinsics from_json<ApollocommonExtrinsics>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonExtrinsics &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonExtrinsics & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonExtrinsics & dt);
}
