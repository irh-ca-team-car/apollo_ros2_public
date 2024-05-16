#pragma once
#include "apollo_msgs/msg/apollodrivers_ldw_data_packs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_roadway.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_lens_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLdwDataPacks &msg) ;
    ApollodriversLdwDataPacks from_json_ApollodriversLdwDataPacks (nlohmann::json obj) ;
    template <>
    ApollodriversLdwDataPacks from_json<ApollodriversLdwDataPacks>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLdwDataPacks &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversLdwDataPacks & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLdwDataPacks & dt);
}
