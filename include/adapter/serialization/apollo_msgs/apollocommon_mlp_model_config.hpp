#pragma once
#include "apollo_msgs/msg/apollocommon_mlp_model_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonMlpModelConfig &msg) ;
    ApollocommonMlpModelConfig from_json_ApollocommonMlpModelConfig (nlohmann::json obj) ;
    template <>
    ApollocommonMlpModelConfig from_json<ApollocommonMlpModelConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonMlpModelConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonMlpModelConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonMlpModelConfig & dt);
}
