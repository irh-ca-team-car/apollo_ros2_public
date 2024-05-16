#include "adapter/serialization/internal/common/linesegment2d.h"
#include "adapter/serialization/internal/common/vec2d.h"

namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::common::math::LineSegment2d &msg)
    {
        nlohmann::json obj;
        obj["start_"] = to_json(msg.start_);
        obj["end_"] = to_json(msg.end_);
        obj["unit_direction_"] = to_json(msg.unit_direction_);
        obj["heading_"] = msg.heading_;
        obj["length_"] = msg.length_;
        return obj;
    }
    apollo::common::math::LineSegment2d from_json_LineSegment2d(nlohmann::json obj)
    {
        apollo::common::math::LineSegment2d poly;

        if (obj.contains("start_"))
            poly.start_ = from_json_Vec2d(obj["start"]);
        if (obj.contains("end_"))
            poly.end_ = from_json_Vec2d(obj["end_"]);
        if (obj.contains("unit_direction_"))
            poly.unit_direction_ = from_json_Vec2d(obj["unit_direction_"]);
        if (obj.contains("heading_"))
            poly.heading_ = (obj["heading_"].is_string() ? atof(obj["heading_"].get<std::string>().c_str()) : obj["heading_"].get<double>());
        if (obj.contains("length_"))
            poly.length_ = (obj["length_"].is_string() ? atof(obj["length_"].get<std::string>().c_str()) : obj["length_"].get<double>());

        return poly;
    }
    template <>
    apollo::common::math::LineSegment2d from_json<apollo::common::math::LineSegment2d>(nlohmann::json obj)
    {
        return from_json_LineSegment2d(obj);
    }

    std::ostream &
    operator<<(std::ostream &os, const apollo::common::math::LineSegment2d &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::common::math::LineSegment2d &dt)
    {
        return os << to_json(dt).dump();
    }
}