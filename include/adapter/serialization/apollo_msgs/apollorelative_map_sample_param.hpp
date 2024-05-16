#pragma once
#include "apollo_msgs/msg/apollorelative_map_sample_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapSampleParam &msg) ;
    ApollorelativeMapSampleParam from_json_ApollorelativeMapSampleParam (nlohmann::json obj) ;
    template <>
    ApollorelativeMapSampleParam from_json<ApollorelativeMapSampleParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapSampleParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapSampleParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapSampleParam & dt);
}
