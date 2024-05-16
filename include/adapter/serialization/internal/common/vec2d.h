#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "modules/common/math/vec2d.h"
#include <string>
namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::common::math::Vec2d &msg);
    apollo::common::math::Vec2d from_json_Vec2d(nlohmann::json obj);
    template <>
    apollo::common::math::Vec2d from_json<apollo::common::math::Vec2d>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, apollo::common::math::Vec2d &dt);
    std::ostream &operator<<(std::ostream &os, const apollo::common::math::Vec2d &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::common::math::Vec2d &dt);
}