#pragma once
#include "apollo_msgs/msg/apollocommon_status_pb.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonStatusPb &msg) ;
    ApollocommonStatusPb from_json_ApollocommonStatusPb (nlohmann::json obj) ;
    template <>
    ApollocommonStatusPb from_json<ApollocommonStatusPb>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonStatusPb &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonStatusPb & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonStatusPb & dt);
}
