#pragma once
#include "apollo_msgs/msg/apollodriversgnss_raw_data.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssRawData &msg) ;
    ApollodriversgnssRawData from_json_ApollodriversgnssRawData (nlohmann::json obj) ;
    template <>
    ApollodriversgnssRawData from_json<ApollodriversgnssRawData>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssRawData &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssRawData & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssRawData & dt);
}
