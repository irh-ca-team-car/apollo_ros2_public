#pragma once
#include "apollo_msgs/msg/apollohdmap_verify_range.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapVerifyRange &msg) ;
    ApollohdmapVerifyRange from_json_ApollohdmapVerifyRange (nlohmann::json obj) ;
    template <>
    ApollohdmapVerifyRange from_json<ApollohdmapVerifyRange>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapVerifyRange &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapVerifyRange & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapVerifyRange & dt);
}
