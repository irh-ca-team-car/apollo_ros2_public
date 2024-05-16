#pragma once
#include "apollo_msgs/msg/apollohdmap_signal.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_polygon.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_subsignal.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_curve.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_sign_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSignal &msg) ;
    ApollohdmapSignal from_json_ApollohdmapSignal (nlohmann::json obj) ;
    template <>
    ApollohdmapSignal from_json<ApollohdmapSignal>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSignal &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSignal & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSignal & dt);
}
