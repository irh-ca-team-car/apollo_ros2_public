#include "adapter/serialization/internal/common/vec2d.h"

namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::common::math::Vec2d &msg)
    {
        nlohmann::json obj;
        obj["x_"] = msg.x_;
        obj["y_"] = msg.y_;
        return obj;
    }
    apollo::common::math::Vec2d from_json_Vec2d(nlohmann::json obj)
    {
        apollo::common::math::Vec2d poly;
        if (obj.contains("x_"))
            poly.x_ = (obj["x_"].is_string() ? atof(obj["x_"].get<std::string>().c_str()) : obj["x_"].get<double>());
        if (obj.contains("y_"))
            poly.y_ = (obj["y_"].is_string() ? atof(obj["y_"].get<std::string>().c_str()) : obj["y_"].get<double>());

        return poly;
    }
    template <>
    apollo::common::math::Vec2d from_json<apollo::common::math::Vec2d>(nlohmann::json obj)
    {
        return from_json_Vec2d(obj);
    }

    std::ostream &
    operator<<(std::ostream &os, const apollo::common::math::Vec2d &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::common::math::Vec2d &dt)
    {
        return os << to_json(dt).dump();
    }
}