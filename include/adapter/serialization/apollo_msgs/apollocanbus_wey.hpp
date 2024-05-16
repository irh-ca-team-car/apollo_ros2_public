#pragma once
#include "apollo_msgs/msg/apollocanbus_wey.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_shifter115.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_eps113.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_status310.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vin_resp3393.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vin_resp2392.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vin_resp1391.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_req_vin390.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads1111.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_fbs2240.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_fbs1243.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_fbs4235.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_fail241.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_fbs3237.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads338e.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWey &msg) ;
    ApollocanbusWey from_json_ApollocanbusWey (nlohmann::json obj) ;
    template <>
    ApollocanbusWey from_json<ApollocanbusWey>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWey &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWey & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWey & dt);
}
