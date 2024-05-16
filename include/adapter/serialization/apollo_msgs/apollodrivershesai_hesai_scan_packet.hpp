#pragma once
#include "apollo_msgs/msg/apollodrivershesai_hesai_scan_packet.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodrivershesaiHesaiScanPacket &msg) ;
    ApollodrivershesaiHesaiScanPacket from_json_ApollodrivershesaiHesaiScanPacket (nlohmann::json obj) ;
    template <>
    ApollodrivershesaiHesaiScanPacket from_json<ApollodrivershesaiHesaiScanPacket>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodrivershesaiHesaiScanPacket &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodrivershesaiHesaiScanPacket & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodrivershesaiHesaiScanPacket & dt);
}
