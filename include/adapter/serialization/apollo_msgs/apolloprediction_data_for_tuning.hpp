#pragma once
#include "apollo_msgs/msg/apolloprediction_data_for_tuning.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionDataForTuning &msg) ;
    ApollopredictionDataForTuning from_json_ApollopredictionDataForTuning (nlohmann::json obj) ;
    template <>
    ApollopredictionDataForTuning from_json<ApollopredictionDataForTuning>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionDataForTuning &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionDataForTuning & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionDataForTuning & dt);
}
