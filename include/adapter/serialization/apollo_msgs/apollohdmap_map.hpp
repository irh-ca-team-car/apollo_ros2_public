#pragma once
#include "apollo_msgs/msg/apollohdmap_map.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollohdmap_header.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_crosswalk.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_junction.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_lane.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_stop_sign.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_signal.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_yield_sign.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_overlap.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_clear_area.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_speed_bump.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_road.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_parking_space.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_pnc_junction.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_rsu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapMap &msg) ;
    ApollohdmapMap from_json_ApollohdmapMap (nlohmann::json obj) ;
    template <>
    ApollohdmapMap from_json<ApollohdmapMap>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapMap &dt);
    std::ostream & operator<<(std::ostream & os, const ApollohdmapMap & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapMap & dt);
}
