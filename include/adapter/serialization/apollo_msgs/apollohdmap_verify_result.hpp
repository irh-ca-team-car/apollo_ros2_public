#pragma once
#include "apollo_msgs/msg/apollohdmap_verify_result.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_topic_result.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_frame_rate.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapVerifyResult &msg) ;
    ApollohdmapVerifyResult from_json_ApollohdmapVerifyResult (nlohmann::json obj) ;
    template <>
    ApollohdmapVerifyResult from_json<ApollohdmapVerifyResult>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapVerifyResult &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapVerifyResult & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapVerifyResult & dt);
}
