#pragma once
#include "apollo_msgs/msg/apolloperceptioncamerasinglestage_singlestage_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasinglestageSinglestageParam &msg) ;
    ApolloperceptioncamerasinglestageSinglestageParam from_json_ApolloperceptioncamerasinglestageSinglestageParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncamerasinglestageSinglestageParam from_json<ApolloperceptioncamerasinglestageSinglestageParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasinglestageSinglestageParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasinglestageSinglestageParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasinglestageSinglestageParam & dt);
}
