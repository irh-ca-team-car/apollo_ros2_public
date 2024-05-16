#pragma once
#include "apollo_msgs/msg/apollodriversgnss_gnss.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point_llh.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssGnss &msg) ;
    ApollodriversgnssGnss from_json_ApollodriversgnssGnss (nlohmann::json obj) ;
    template <>
    ApollodriversgnssGnss from_json<ApollodriversgnssGnss>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssGnss &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssGnss & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssGnss & dt);
}
