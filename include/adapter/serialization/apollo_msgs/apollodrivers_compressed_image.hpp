#pragma once
#include "apollo_msgs/msg/apollodrivers_compressed_image.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversCompressedImage &msg) ;
    ApollodriversCompressedImage from_json_ApollodriversCompressedImage (nlohmann::json obj) ;
    template <>
    ApollodriversCompressedImage from_json<ApollodriversCompressedImage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversCompressedImage &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversCompressedImage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversCompressedImage & dt);
}
