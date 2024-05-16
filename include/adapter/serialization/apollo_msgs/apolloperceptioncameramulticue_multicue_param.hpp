#pragma once
#include "apollo_msgs/msg/apolloperceptioncameramulticue_multicue_param.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameramulticueMulticueParam &msg) ;
    ApolloperceptioncameramulticueMulticueParam from_json_ApolloperceptioncameramulticueMulticueParam (nlohmann::json obj) ;
    template <>
    ApolloperceptioncameramulticueMulticueParam from_json<ApolloperceptioncameramulticueMulticueParam>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameramulticueMulticueParam &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameramulticueMulticueParam & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameramulticueMulticueParam & dt);
}
