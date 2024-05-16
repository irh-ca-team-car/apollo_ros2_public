#pragma once
#include "apollo_msgs/msg/apollodrivers_ldw_lens_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLdwLensInfo &msg) ;
    ApollodriversLdwLensInfo from_json_ApollodriversLdwLensInfo (nlohmann::json obj) ;
    template <>
    ApollodriversLdwLensInfo from_json<ApollodriversLdwLensInfo>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLdwLensInfo &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversLdwLensInfo & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLdwLensInfo & dt);
}
