#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_lattice_st_training.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloplanning_internal_lattice_st_pixel.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalLatticeStTraining &msg) ;
    ApolloplanningInternalLatticeStTraining from_json_ApolloplanningInternalLatticeStTraining (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalLatticeStTraining from_json<ApolloplanningInternalLatticeStTraining>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalLatticeStTraining &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalLatticeStTraining & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalLatticeStTraining & dt);
}
