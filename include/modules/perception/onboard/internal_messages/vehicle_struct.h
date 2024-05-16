#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/vehicle_struct.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::CarLight;
    nlohmann::json to_json(const CarLight &msg);
    CarLight from_json_CarLight(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, CarLight &dt);
    std::ostream &operator<<(std::ostream &os, const CarLight &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const CarLight &dt);
}
