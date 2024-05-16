#include "modules/perception/onboard/internal_messages/point_cloud.h"
#include "modules/perception/onboard/internal_messages/hdmap_struct.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::RoadBoundary;
    using apollo::perception::base::PointD;

    nlohmann::json to_json(const RoadBoundary &msg)
    {
        nlohmann::json j;
        j["left_boundary"] = to_json(msg.left_boundary);
        j["right_boundary"] = to_json(msg.right_boundary);
        return j;
    }
    RoadBoundary from_json_RoadBoundary(nlohmann::json obj)
    {
        RoadBoundary strct;
        if (obj.contains("left_boundary"))
            strct.left_boundary = from_json_PointCloud<PointD>(obj["left_boundary"]);
        if (obj.contains("right_boundary"))
            strct.right_boundary = from_json_PointCloud<PointD>(obj["right_boundary"]);
        return strct;
    }
    template <>
    RoadBoundary from_json<RoadBoundary>(nlohmann::json obj)
    {
        return from_json_RoadBoundary(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, RoadBoundary &dt)
    {
        dt = from_json_RoadBoundary(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const RoadBoundary &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const RoadBoundary &dt)
    {
        return os << to_json(dt).dump();
    }
}
namespace apollo_msgs::msg
{
    template <typename T>
    nlohmann::json to_json(const EigenVector<T> &msg)
    {
        nlohmann::json j;
        for (size_t i = 0; i < msg.size(); i++)
        {
            j[i] = to_json(msg[i]);
        }
        
        return j;
    }
    template <typename T>
    EigenVector<T> from_json_EigenVector(nlohmann::json obj)
    {
        EigenVector<T> strct;
        for (auto &&i : obj)
        {
            strct.push_back(from_json<T>(i));
        }

        return strct;
    }
    template <typename T>
    EigenVector<PointCloud<T>> from_json_EigenVectorPC(nlohmann::json obj)
    {
        EigenVector<PointCloud<T>> strct;
        for (auto &&i : obj)
        {
            strct.push_back(from_json_PointCloud<T>(i));
        }

        return strct;
    }
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, EigenVector<T> &dt)
    {
        dt = from_json_EigenVector<T>(os);
        return os;
    }
    template <typename T>
    std::ostream &
    operator<<(std::ostream &os, const EigenVector<T> &dt)
    {
        return os << to_json(dt).dump();
    }
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const EigenVector<T> &dt)
    {
        return os << to_json(dt).dump();
    }
}
namespace apollo_msgs::msg
{
    using apollo::perception::base::HdmapStruct;
    using apollo::perception::base::PointD;
    using apollo::perception::base::RoadBoundary;
    using apollo::perception::base::PointCloud;
    nlohmann::json to_json(const HdmapStruct &msg)
    {
        nlohmann::json j;
        j["road_boundary"] = to_json(msg.road_boundary);
        j["hole_polygons"] = to_json(msg.hole_polygons);
        j["junction_polygons"] = to_json(msg.junction_polygons);
        j["road_polygons"] = to_json(msg.road_polygons);
        return j;
    }
    HdmapStruct from_json_HdmapStruct(nlohmann::json obj)
    {
        HdmapStruct strct;
        if (obj.contains("road_boundary"))
            strct.road_boundary = from_json_EigenVector<RoadBoundary>(obj["road_boundary"]);
        if (obj.contains("hole_polygons"))
            strct.hole_polygons = from_json_EigenVectorPC<PointD>(obj["hole_polygons"]);
        if (obj.contains("junction_polygons"))
            strct.junction_polygons = from_json_EigenVectorPC<PointD>(obj["junction_polygons"]);
        if (obj.contains("road_polygons"))
            strct.road_polygons = from_json_EigenVectorPC<PointD>(obj["road_polygons"]);

        return strct;
    }
    template <>
    HdmapStruct from_json<HdmapStruct>(nlohmann::json obj)
    {
        return from_json_HdmapStruct(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, HdmapStruct &dt)
    {
        dt = from_json_HdmapStruct(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const HdmapStruct &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const HdmapStruct &dt)
    {
        return os << to_json(dt).dump();
    }
}
