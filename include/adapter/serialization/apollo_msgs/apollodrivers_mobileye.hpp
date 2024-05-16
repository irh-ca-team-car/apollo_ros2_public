#pragma once
#include "apollo_msgs/msg/apollodrivers_mobileye.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_aftermarket669.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_details737.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_details738.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_details739.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_details73a.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_details73b.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_lka766.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_lka767.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_lka768.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_lka769.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_reference76a.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_num76b.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_next76c.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_next76d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversMobileye &msg) ;
    ApollodriversMobileye from_json_ApollodriversMobileye (nlohmann::json obj) ;
    template <>
    ApollodriversMobileye from_json<ApollodriversMobileye>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversMobileye &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversMobileye & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversMobileye & dt);
}
