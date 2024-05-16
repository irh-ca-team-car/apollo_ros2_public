#pragma once
#include "apollo_msgs/msg/apollolocalization_uncertainty.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationUncertainty &msg) ;
    ApollolocalizationUncertainty from_json_ApollolocalizationUncertainty (nlohmann::json obj) ;
    template <>
    ApollolocalizationUncertainty from_json<ApollolocalizationUncertainty>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationUncertainty &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationUncertainty & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationUncertainty & dt);
}
