#pragma once
#include "apollo_msgs/msg/apollocanbus_aeb_diagnosis1626.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebDiagnosis1626 &msg) ;
    ApollocanbusAebDiagnosis1626 from_json_ApollocanbusAebDiagnosis1626 (nlohmann::json obj) ;
    template <>
    ApollocanbusAebDiagnosis1626 from_json<ApollocanbusAebDiagnosis1626>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebDiagnosis1626 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebDiagnosis1626 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebDiagnosis1626 & dt);
}
