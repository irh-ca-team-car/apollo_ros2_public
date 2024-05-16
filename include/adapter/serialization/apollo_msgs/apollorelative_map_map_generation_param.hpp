#pragma once
#include "apollo_msgs/msg/apollorelative_map_map_generation_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapMapGenerationParam &msg) ;
    ApollorelativeMapMapGenerationParam from_json_ApollorelativeMapMapGenerationParam (nlohmann::json obj) ;
    template <>
    ApollorelativeMapMapGenerationParam from_json<ApollorelativeMapMapGenerationParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapMapGenerationParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapMapGenerationParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapMapGenerationParam & dt);
}
