#pragma once
#include "apollo_msgs/msg/apollocanbus_pas1st_data311.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPas1stData311 &msg) ;
    ApollocanbusPas1stData311 from_json_ApollocanbusPas1stData311 (nlohmann::json obj) ;
    template <>
    ApollocanbusPas1stData311 from_json<ApollocanbusPas1stData311>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPas1stData311 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPas1stData311 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPas1stData311 & dt);
}
