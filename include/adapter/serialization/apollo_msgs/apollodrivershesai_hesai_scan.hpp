#pragma once
#include "apollo_msgs/msg/apollodrivershesai_hesai_scan.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivershesai_hesai_scan_packet.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodrivershesaiHesaiScan &msg) ;
    ApollodrivershesaiHesaiScan from_json_ApollodrivershesaiHesaiScan (nlohmann::json obj) ;
    template <>
    ApollodrivershesaiHesaiScan from_json<ApollodrivershesaiHesaiScan>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodrivershesaiHesaiScan &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodrivershesaiHesaiScan & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodrivershesaiHesaiScan & dt);
}
