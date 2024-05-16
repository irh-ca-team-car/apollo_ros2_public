#include "modules/perception/onboard/internal_messages/point.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::Point;
    template <typename T>
    nlohmann::json to_json(const Point<T> &msg)
    {
        nlohmann::json j;

        j["x"] = msg.x;
        j["y"] = msg.y;
        j["z"] = msg.z;
        j["intensity"] = msg.intensity;

        return j;
    }
    template <typename T>
    Point<T> from_json_Point(nlohmann::json obj)
    {
        Point<T> d;
        if (obj.contains("x"))
            d.x = (obj["x"].is_string()?(T)atof(obj["x"].get<std::string>().c_str()):obj["x"].get<T>());
        if (obj.contains("y"))
            d.y = (obj["y"].is_string()?(T)atof(obj["y"].get<std::string>().c_str()):obj["y"].get<T>());
        if (obj.contains("z"))
            d.z = (obj["z"].is_string()?(T)atof(obj["z"].get<std::string>().c_str()):obj["z"].get<T>());
        if (obj.contains("intensity"))
            d.intensity = (obj["intensity"].is_string()?(T)atof(obj["intensity"].get<std::string>().c_str()):obj["intensity"].get<T>());
        return d;
    }
    template <>
    Point<double> from_json<Point<double>>(nlohmann::json obj)
    {
        return from_json_Point<double>(obj);
    }
    template <>
    Point<float> from_json<Point<float>>(nlohmann::json obj)
    {
        return from_json_Point<float>(obj);
    }
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, Point<T> &dt)
    {
        dt = from_json_Point<T>(os);
        return os;
    }
    template <typename T>
    std::ostream &
    operator<<(std::ostream &os, const Point<T> &dt)
    {
        return os << to_json(dt).dump();
    }
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Point<T> &dt)
    {
        return os << to_json(dt).dump();
    }
}
namespace apollo_msgs::msg
{
    using apollo::perception::base::PointIndices;
    nlohmann::json to_json(const PointIndices &msg)
    {
        nlohmann::json j;

        nlohmann::json arr_indices;
        for (auto it= msg.indices.begin(); it != msg.indices.end(); ++it){
            arr_indices.push_back(*it); 
        }
        j["indices"] = arr_indices;

        return j;
    }
    PointIndices from_json_PointIndices(nlohmann::json obj)
    {
        PointIndices d;
        
        if(obj.contains("indices")) 
            for (auto element : obj["indices"]){
                d.indices.push_back(element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>());
            }
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, PointIndices &dt)
    {
        dt = from_json_PointIndices(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const PointIndices &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const PointIndices &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::Point3D;
    template <typename T>
    nlohmann::json to_json(const Point3D<T> &msg)
    {
        nlohmann::json j;

        j["x"] = msg.x;
        j["y"] = msg.y;
        j["z"] = msg.z;

        return j;
    }
    template <>
    nlohmann::json to_json(const Point3D<float> &msg)
    {
        return to_json(msg);
    }
    template <typename T>
    Point3D<T> from_json_Point3D(nlohmann::json obj)
    {
        Point3D<T> d;
        if (obj.contains("x"))
            d.x = (obj["x"].is_string()?(T)atof(obj["x"].get<std::string>().c_str()):obj["x"].get<T>());
        if (obj.contains("y"))
            d.y = (obj["y"].is_string()?(T)atof(obj["y"].get<std::string>().c_str()):obj["y"].get<T>());
        if (obj.contains("z"))
            d.z = (obj["z"].is_string()?(T)atof(obj["z"].get<std::string>().c_str()):obj["z"].get<T>());
        return d;
    }
    template <>
    Point3D<double> from_json<Point3D<double>>(nlohmann::json obj)
    {
        return from_json_Point3D<double>(obj);
    }
    template <>
    Point3D<float> from_json<Point3D<float>>(nlohmann::json obj)
    {
        return from_json_Point3D<float>(obj);
    }
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, Point3D<T> &dt)
    {
        dt = from_json_Point3D<T>(os);
        return os;
    }template <typename T>
    std::ostream &
    operator<<(std::ostream &os, const Point3D<T> &dt)
    {
        return os << to_json(dt).dump();
    }
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Point3D<T> &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::Point2D;
    template <typename T>
    nlohmann::json to_json(const Point2D<T> &msg)
    {
        nlohmann::json j;

        j["x"] = msg.x;
        j["y"] = msg.y;

        return j;
    }
    template <>
    nlohmann::json to_json(const Point2D<float> &msg)
    {
        return to_json(msg);
    }
    template <typename T>
    Point2D<T> from_json_Point2D(nlohmann::json obj)
    {
        Point2D<T> d;
        if (obj.contains("x"))
            d.x = (obj["x"].is_string()?(T)atof(obj["x"].get<std::string>().c_str()):obj["x"].get<T>());
        if (obj.contains("y"))
            d.y = (obj["y"].is_string()?(T)atof(obj["y"].get<std::string>().c_str()):obj["y"].get<T>());
        return d;
    }
    template <>
    Point2D<double> from_json<Point2D<double>>(nlohmann::json obj)
    {
        return from_json_Point2D<double>(obj);
    }
    template <>
    Point2D<float> from_json<Point2D<float>>(nlohmann::json obj)
    {
        return from_json_Point2D<float>(obj);
    }
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, Point2D<T> &dt)
    {
        dt = from_json_Point2D<T>(os);
        return os;
    }
    template <typename T>
    std::ostream &
    operator<<(std::ostream &os, const Point2D<T> &dt)
    {
        return os << to_json(dt).dump();
    }
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Point2D<T> &dt)
    {
        return os << to_json(dt).dump();
    }
}
