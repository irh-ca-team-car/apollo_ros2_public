#pragma once
#include "apollo_msgs/msg/apollocommon_point_llh.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPointLLH &msg) ;
    ApollocommonPointLLH from_json_ApollocommonPointLLH (nlohmann::json obj) ;
    template <>
    ApollocommonPointLLH from_json<ApollocommonPointLLH>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPointLLH &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonPointLLH & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPointLLH & dt);
}
