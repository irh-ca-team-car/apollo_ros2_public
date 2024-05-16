#pragma once
#include "apollo_msgs/msg/apollolocalization_gnss_pnt_result.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollolocalization_sat_dir_cosine.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationGnssPntResult &msg) ;
    ApollolocalizationGnssPntResult from_json_ApollolocalizationGnssPntResult (nlohmann::json obj) ;
    template <>
    ApollolocalizationGnssPntResult from_json<ApollolocalizationGnssPntResult>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationGnssPntResult &dt);
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationGnssPntResult & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationGnssPntResult & dt);
}
