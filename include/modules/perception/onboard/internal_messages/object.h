#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/object.h"
#include "modules/perception/onboard/internal_messages/point_cloud.h"
#include "modules/perception/onboard/internal_messages/vehicle_struct.h"
#include "modules/perception/onboard/internal_messages/object_supplement.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::Object;
    nlohmann::json to_json(const Object &msg);
    Object from_json_Object(nlohmann::json obj);
    template <>
    Object from_json<Object>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Object &dt);
    std::ostream &operator<<(std::ostream &os, const Object &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Object &dt);
}
