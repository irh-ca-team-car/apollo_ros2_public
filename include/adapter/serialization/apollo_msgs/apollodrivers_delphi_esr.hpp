#pragma once
#include "apollo_msgs/msg/apollodrivers_delphi_esr.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status95e8.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status65e5.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status55e4.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status34e2.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status44e3.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_trackmotionpower540.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_acm_inst_req7e0.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_track01500.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_valid15d0.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_valid25d1.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_acm_inst_resp7e4.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle24f1.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle14f0.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_sim15c0.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status14e0.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status24e1.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status85e7.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status75e6.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle35f2.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle45f3.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle55f4.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle65f5.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDelphiESR &msg) ;
    ApollodriversDelphiESR from_json_ApollodriversDelphiESR (nlohmann::json obj) ;
    template <>
    ApollodriversDelphiESR from_json<ApollodriversDelphiESR>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDelphiESR &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversDelphiESR & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDelphiESR & dt);
}
