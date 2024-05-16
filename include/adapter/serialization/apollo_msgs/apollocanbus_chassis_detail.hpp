#pragma once
#include "apollo_msgs/msg/apollocanbus_chassis_detail.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_basic_info.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_safety.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gear.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ems.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_esp.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gas.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_epb.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_brake.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_deceleration.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_spd.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_eps.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_light.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_battery.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_check_response_signal.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_license.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_surround.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_gem.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_lexus.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_transit.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ge3.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wey.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_zhongyun.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ch.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_devkit.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_neolix_edu.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_id.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusChassisDetail &msg) ;
    ApollocanbusChassisDetail from_json_ApollocanbusChassisDetail (nlohmann::json obj) ;
    template <>
    ApollocanbusChassisDetail from_json<ApollocanbusChassisDetail>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusChassisDetail &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusChassisDetail & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusChassisDetail & dt);
}
