#pragma once
#include "apollo_msgs/msg/apolloprediction_list_data_for_learning.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_data_for_learning.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionListDataForLearning &msg) ;
    ApollopredictionListDataForLearning from_json_ApollopredictionListDataForLearning (nlohmann::json obj) ;
    template <>
    ApollopredictionListDataForLearning from_json<ApollopredictionListDataForLearning>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionListDataForLearning &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionListDataForLearning & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionListDataForLearning & dt);
}
