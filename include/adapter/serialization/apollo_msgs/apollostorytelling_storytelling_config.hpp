#pragma once
#include "apollo_msgs/msg/apollostorytelling_storytelling_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollostorytelling_topic_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingStorytellingConfig &msg) ;
    ApollostorytellingStorytellingConfig from_json_ApollostorytellingStorytellingConfig (nlohmann::json obj) ;
    template <>
    ApollostorytellingStorytellingConfig from_json<ApollostorytellingStorytellingConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingStorytellingConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingStorytellingConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingStorytellingConfig & dt);
}
