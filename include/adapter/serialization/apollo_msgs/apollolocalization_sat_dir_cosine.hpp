#pragma once
#include "apollo_msgs/msg/apollolocalization_sat_dir_cosine.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationSatDirCosine &msg) ;
    ApollolocalizationSatDirCosine from_json_ApollolocalizationSatDirCosine (nlohmann::json obj) ;
    template <>
    ApollolocalizationSatDirCosine from_json<ApollolocalizationSatDirCosine>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationSatDirCosine &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationSatDirCosine & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationSatDirCosine & dt);
}
