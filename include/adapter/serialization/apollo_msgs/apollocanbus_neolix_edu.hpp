#pragma once
#include "apollo_msgs/msg/apollocanbus_neolix_edu.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_systemstate11.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_vehicle_fault_response201.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_powerstatus214.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_light_horn_command310.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_brake_command46.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_brake_report47.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_eps_report57.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_eps_command56.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_drive_command50.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_drive_report52.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_ads_diagnosis628.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_nm401.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_vehicle_status_report101.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_vehicle_info_response502.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_diagnosis1626.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_diagresp718.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pas1st_data311.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_pas2nd_data312.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_wheelimpulse355.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_rearwheelspeed354.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_frontwheelspeed353.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusNeolixEdu &msg) ;
    ApollocanbusNeolixEdu from_json_ApollocanbusNeolixEdu (nlohmann::json obj) ;
    template <>
    ApollocanbusNeolixEdu from_json<ApollocanbusNeolixEdu>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusNeolixEdu &dt);
    std::ostream & operator<<(std::ostream & os, const ApollocanbusNeolixEdu & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusNeolixEdu & dt);
}
