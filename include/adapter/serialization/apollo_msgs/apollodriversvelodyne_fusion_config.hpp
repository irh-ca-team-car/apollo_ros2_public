#pragma once
#include "apollo_msgs/msg/apollodriversvelodyne_fusion_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvelodyneFusionConfig &msg) ;
    ApollodriversvelodyneFusionConfig from_json_ApollodriversvelodyneFusionConfig (nlohmann::json obj) ;
    template <>
    ApollodriversvelodyneFusionConfig from_json<ApollodriversvelodyneFusionConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvelodyneFusionConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversvelodyneFusionConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvelodyneFusionConfig & dt);
}
