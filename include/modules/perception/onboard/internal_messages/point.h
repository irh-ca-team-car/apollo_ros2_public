#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/point.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::Point;
    template <typename T>
    nlohmann::json to_json(const Point<T> &msg);
    template <typename T>
    Point<T> from_json_Point(nlohmann::json obj);
    template <>
    Point<double> from_json<Point<double>>(nlohmann::json obj);
    template <>
    Point<float> from_json<Point<float>>(nlohmann::json obj);
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, Point<T> &dt);
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const Point<T> &dt);
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Point<T> &dt);
}
namespace apollo_msgs::msg
{
    using apollo::perception::base::PointIndices;
    nlohmann::json to_json(const PointIndices &msg);
    PointIndices from_json_PointIndices(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, PointIndices &dt);
    std::ostream &operator<<(std::ostream &os, const PointIndices &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const PointIndices &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::Point3D;
    template <typename T>
    nlohmann::json to_json(const Point3D<T> &msg);
    template <>
    nlohmann::json to_json(const Point3D<float> &msg);
    template <typename T>
    Point3D<T> from_json_Point3D(nlohmann::json obj);
    template <>
    Point3D<double> from_json<Point3D<double>>(nlohmann::json obj);
    template <>
    Point3D<float> from_json<Point3D<float>>(nlohmann::json obj);
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, Point3D<T> &dt);
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const Point3D<T> &dt);
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Point3D<T> &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::Point2D;
    template <typename T>
    nlohmann::json to_json(const Point2D<T> &msg);
    template <>
    nlohmann::json to_json(const Point2D<float> &msg);
    template <typename T>
    Point2D<T> from_json_Point2D(nlohmann::json obj);
    template <>
    Point2D<double> from_json<Point2D<double>>(nlohmann::json obj);
    template <>
    Point2D<float> from_json<Point2D<float>>(nlohmann::json obj);
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, Point2D<T> &dt);
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const Point2D<T> &dt);
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Point2D<T> &dt);
}
