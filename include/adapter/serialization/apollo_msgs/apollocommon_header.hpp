#pragma once
#include "apollo_msgs/msg/apollocommon_header.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_status_pb.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonHeader &msg) ;
    ApollocommonHeader from_json_ApollocommonHeader (nlohmann::json obj) ;
    template <>
    ApollocommonHeader from_json<ApollocommonHeader>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonHeader &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonHeader & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonHeader & dt);
}
