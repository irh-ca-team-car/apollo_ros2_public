#pragma once
#include "apollo_msgs/msg/apolloplanning_qp_matrix.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningQPMatrix &msg) ;
    ApolloplanningQPMatrix from_json_ApolloplanningQPMatrix (nlohmann::json obj) ;
    template <>
    ApolloplanningQPMatrix from_json<ApolloplanningQPMatrix>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningQPMatrix &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningQPMatrix & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningQPMatrix & dt);
}
