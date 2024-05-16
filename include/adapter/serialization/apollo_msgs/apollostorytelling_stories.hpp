#pragma once
#include "apollo_msgs/msg/apollostorytelling_stories.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_clear_area.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_crosswalk.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_junction.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_signal.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_stop_sign.hpp"
#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_yield_sign.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingStories &msg) ;
    ApollostorytellingStories from_json_ApollostorytellingStories (nlohmann::json obj) ;
    template <>
    ApollostorytellingStories from_json<ApollostorytellingStories>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingStories &dt);
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingStories & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingStories & dt);
}
