#pragma once
#include "apollo_msgs/msg/apollorelative_map_map_msg.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_map.hpp"
#include "adapter/serialization/apollo_msgs/apollorelative_map_map_msgnavigation_path.hpp"
#include "adapter/serialization/apollo_msgs/apolloperception_lane_markers.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_localization_estimate.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapMapMsg &msg) ;
    ApollorelativeMapMapMsg from_json_ApollorelativeMapMapMsg (nlohmann::json obj) ;
    template <>
    ApollorelativeMapMapMsg from_json<ApollorelativeMapMapMsg>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapMapMsg &dt);
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapMapMsg & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapMapMsg & dt);
}
