#pragma once
#include "apollo_msgs/msg/apolloplanning_object_decision_typeobject_tag.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_object_stop.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_follow.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_yield.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_overtake.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_nudge.hpp"
#include "adapter/serialization/apollo_msgs/apolloplanning_object_side_pass.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectDecisionTypeobjectTag &msg) ;
    ApolloplanningObjectDecisionTypeobjectTag from_json_ApolloplanningObjectDecisionTypeobjectTag (nlohmann::json obj) ;
    template <>
    ApolloplanningObjectDecisionTypeobjectTag from_json<ApolloplanningObjectDecisionTypeobjectTag>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectDecisionTypeobjectTag &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectDecisionTypeobjectTag & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectDecisionTypeobjectTag & dt);
}
