#include "adapter/serialization/internal/common/polygon2d.h"
#include "adapter/serialization/internal/common/linesegment2d.h"
#include "adapter/serialization/internal/common/vec2d.h"
namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::common::math::Polygon2d &msg)
    {
        nlohmann::json obj;
        nlohmann::json lst1;
        for (auto &&i : msg.points_)
        {
            lst1.push_back(to_json(i));
        }
        obj["points_"] = lst1;
        obj["num_points_"] = msg.num_points_;
        nlohmann::json lst2;
        for (auto &&i : msg.line_segments_)
        {
            lst2.push_back(to_json(i));
        }
        obj["line_segments_"] = lst2;

        obj["is_convex_"] = msg.is_convex_;
        obj["area_"] = msg.area_;
        obj["min_x_"] = msg.min_x_;
        obj["max_x_"] = msg.max_x_;
        obj["min_y_"] = msg.min_y_;
        obj["max_y_"] = msg.max_y_;

        return obj;
    }
    apollo::common::math::Polygon2d from_json_Polygon2d(nlohmann::json obj)
    {
        apollo::common::math::Polygon2d poly;

        if (obj.contains("points_"))
            for (auto &element : obj["points_"])
            {
                poly.points_.push_back(from_json_Vec2d(element));
            }
        if (obj.contains("line_segments_"))
            for (auto &element : obj["line_segments_"])
            {
                poly.line_segments_.push_back(from_json_LineSegment2d(element));
            }
        if (obj.contains("num_points_"))
            poly.num_points_ = (obj["num_points_"].is_string() ? atoi(obj["num_points_"].get<std::string>().c_str()) : obj["num_points_"].get<int>());

        if (obj.contains("is_convex_"))
            poly.is_convex_ = (obj["is_convex_"].is_string() ? (obj["is_convex_"].get<std::string>()) == "true" : obj["is_convex_"].get<bool>());

        if (obj.contains("area_"))
            poly.area_ = (obj["area_"].is_string() ? atof(obj["area_"].get<std::string>().c_str()) : obj["area_"].get<double>());
        if (obj.contains("min_x_"))
            poly.min_x_ = (obj["min_x_"].is_string() ? atof(obj["min_x_"].get<std::string>().c_str()) : obj["min_x_"].get<double>());
        if (obj.contains("max_x_"))
            poly.max_x_ = (obj["max_x_"].is_string() ? atof(obj["max_x_"].get<std::string>().c_str()) : obj["max_x_"].get<double>());
        if (obj.contains("min_y_"))
            poly.min_y_ = (obj["min_y_"].is_string() ? atof(obj["min_y_"].get<std::string>().c_str()) : obj["min_y_"].get<double>());
        if (obj.contains("max_y_"))
            poly.max_y_ = (obj["max_y_"].is_string() ? atof(obj["max_y_"].get<std::string>().c_str()) : obj["max_y_"].get<double>());
        return poly;
    }
    template <>
    apollo::common::math::Polygon2d from_json<apollo::common::math::Polygon2d>(nlohmann::json obj)
    {
        return from_json_Polygon2d(obj);
    }

    std::ostream &
    operator<<(std::ostream &os, const apollo::common::math::Polygon2d &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::common::math::Polygon2d &dt)
    {
        return os << to_json(dt).dump();
    }
}