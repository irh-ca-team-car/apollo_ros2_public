#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "modules/prediction/container/adc_trajectory/adc_trajectory_container.h"
#include <string>
namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::prediction::ADCTrajectoryContainer &msg);
    apollo::prediction::ADCTrajectoryContainer from_json_ADCTrajectoryContainer(nlohmann::json obj);
    template <>
    apollo::prediction::ADCTrajectoryContainer from_json<apollo::prediction::ADCTrajectoryContainer>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, apollo::prediction::ADCTrajectoryContainer &dt);
    std::ostream &operator<<(std::ostream &os, const apollo::prediction::ADCTrajectoryContainer &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::prediction::ADCTrajectoryContainer &dt);
}