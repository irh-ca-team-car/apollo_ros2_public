#pragma once
#include "apollo_msgs/msg/apolloplanning_keep_clear_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningKeepClearConfig &msg) ;
    ApolloplanningKeepClearConfig from_json_ApolloplanningKeepClearConfig (nlohmann::json obj) ;
    template <>
    ApolloplanningKeepClearConfig from_json<ApolloplanningKeepClearConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningKeepClearConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningKeepClearConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningKeepClearConfig & dt);
}
