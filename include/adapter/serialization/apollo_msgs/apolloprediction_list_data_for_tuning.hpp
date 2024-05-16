#pragma once
#include "apollo_msgs/msg/apolloprediction_list_data_for_tuning.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_data_for_tuning.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionListDataForTuning &msg) ;
    ApollopredictionListDataForTuning from_json_ApollopredictionListDataForTuning (nlohmann::json obj) ;
    template <>
    ApollopredictionListDataForTuning from_json<ApollopredictionListDataForTuning>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionListDataForTuning &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionListDataForTuning & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionListDataForTuning & dt);
}
