#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/sensor_meta.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::SensorInfo;
    nlohmann::json to_json(const SensorInfo &msg);
    SensorInfo from_json_SensorInfo(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, SensorInfo &dt);
    std::ostream &operator<<(std::ostream &os, const SensorInfo &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const SensorInfo &dt);
}
