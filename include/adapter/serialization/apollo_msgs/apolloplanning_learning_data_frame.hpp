#pragma once
#include "apollo_msgs/msg/apolloplanning_learning_data_frame.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_planning_tag.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_chassis_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_localization_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_obstacle_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_routing_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_detection_feature.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_adc_trajectory_point.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_learning_output.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLearningDataFrame &msg) ;
    ApolloplanningLearningDataFrame from_json_ApolloplanningLearningDataFrame (nlohmann::json obj) ;
    template <>
    ApolloplanningLearningDataFrame from_json<ApolloplanningLearningDataFrame>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLearningDataFrame &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLearningDataFrame & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLearningDataFrame & dt);
}
