#pragma once
#include "apollo_msgs/msg/apolloperceptionlidar_filter_bank_config.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarFilterBankConfig &msg) ;
    ApolloperceptionlidarFilterBankConfig from_json_ApolloperceptionlidarFilterBankConfig (nlohmann::json obj) ;
    template <>
    ApolloperceptionlidarFilterBankConfig from_json<ApolloperceptionlidarFilterBankConfig>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarFilterBankConfig &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarFilterBankConfig & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarFilterBankConfig & dt);
}
