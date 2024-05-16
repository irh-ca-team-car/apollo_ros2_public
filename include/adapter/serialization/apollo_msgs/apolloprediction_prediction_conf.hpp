#pragma once
#include "apollo_msgs/msg/apolloprediction_prediction_conf.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloprediction_topic_conf.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionConf &msg) ;
    ApollopredictionPredictionConf from_json_ApollopredictionPredictionConf (nlohmann::json obj) ;
    template <>
    ApollopredictionPredictionConf from_json<ApollopredictionPredictionConf>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionConf &dt);
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionConf & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionConf & dt);
}
