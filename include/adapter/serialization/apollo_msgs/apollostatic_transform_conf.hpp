#pragma once
#include "apollo_msgs/msg/apollostatic_transform_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollostatic_transform_extrinsic_file.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostaticTransformConf &msg) ;
    ApollostaticTransformConf from_json_ApollostaticTransformConf (nlohmann::json obj) ;
    template <>
    ApollostaticTransformConf from_json<ApollostaticTransformConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostaticTransformConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostaticTransformConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostaticTransformConf & dt);
}
