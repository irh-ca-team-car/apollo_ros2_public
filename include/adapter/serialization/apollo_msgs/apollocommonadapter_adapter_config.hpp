#pragma once
#include "apollo_msgs/msg/apollocommonadapter_adapter_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonadapterAdapterConfig &msg) ;
    ApollocommonadapterAdapterConfig from_json_ApollocommonadapterAdapterConfig (nlohmann::json obj) ;
    template <>
    ApollocommonadapterAdapterConfig from_json<ApollocommonadapterAdapterConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonadapterAdapterConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonadapterAdapterConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonadapterAdapterConfig & dt);
}
