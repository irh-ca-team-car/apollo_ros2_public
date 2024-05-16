#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "modules/common/math/polygon2d.h"
#include <string>
namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::common::math::Polygon2d &msg);
    apollo::common::math::Polygon2d from_json_Polygon2d(nlohmann::json obj);
    template <>
    apollo::common::math::Polygon2d from_json<apollo::common::math::Polygon2d>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, apollo::common::math::Polygon2d &dt);
    std::ostream &operator<<(std::ostream &os, const apollo::common::math::Polygon2d &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::common::math::Polygon2d &dt);
}