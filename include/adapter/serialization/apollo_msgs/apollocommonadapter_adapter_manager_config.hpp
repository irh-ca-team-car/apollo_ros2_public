#pragma once
#include "apollo_msgs/msg/apollocommonadapter_adapter_manager_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommonadapter_adapter_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonadapterAdapterManagerConfig &msg) ;
    ApollocommonadapterAdapterManagerConfig from_json_ApollocommonadapterAdapterManagerConfig (nlohmann::json obj) ;
    template <>
    ApollocommonadapterAdapterManagerConfig from_json<ApollocommonadapterAdapterManagerConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonadapterAdapterManagerConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonadapterAdapterManagerConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonadapterAdapterManagerConfig & dt);
}
