#pragma once
#include "apollo_msgs/msg/apollocommon_point_enu.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPointENU &msg) ;
    ApollocommonPointENU from_json_ApollocommonPointENU (nlohmann::json obj) ;
    template <>
    ApollocommonPointENU from_json<ApollocommonPointENU>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPointENU &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocommonPointENU & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPointENU & dt);
}
