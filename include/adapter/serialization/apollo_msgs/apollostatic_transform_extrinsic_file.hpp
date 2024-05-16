#pragma once
#include "apollo_msgs/msg/apollostatic_transform_extrinsic_file.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostaticTransformExtrinsicFile &msg) ;
    ApollostaticTransformExtrinsicFile from_json_ApollostaticTransformExtrinsicFile (nlohmann::json obj) ;
    template <>
    ApollostaticTransformExtrinsicFile from_json<ApollostaticTransformExtrinsicFile>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostaticTransformExtrinsicFile &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostaticTransformExtrinsicFile & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostaticTransformExtrinsicFile & dt);
}
