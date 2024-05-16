#pragma once
#include "apollo_msgs/msg/apollocanbus_ge3.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_pc_bcm201.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcs3308.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pc_epb203.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pc_bcs202.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pc_vcu205.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pc_eps204.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_vcu2313.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu1301.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu2302.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu3303.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcm304.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcs1306.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcs2307.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_epb310.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_vcu1312.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_scu_eps311.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGe3 &msg) ;
    ApollocanbusGe3 from_json_ApollocanbusGe3 (nlohmann::json obj) ;
    template <>
    ApollocanbusGe3 from_json<ApollocanbusGe3>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGe3 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGe3 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGe3 & dt);
}
