#pragma once
#include "apollo_msgs/msg/apollolocalization_integ_sins_pva.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point_llh.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationIntegSinsPva &msg) ;
    ApollolocalizationIntegSinsPva from_json_ApollolocalizationIntegSinsPva (nlohmann::json obj) ;
    template <>
    ApollolocalizationIntegSinsPva from_json<ApollolocalizationIntegSinsPva>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationIntegSinsPva &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationIntegSinsPva & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationIntegSinsPva & dt);
}
