#include "modules/perception/onboard/internal_messages/box.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::BBox2D;
    template <typename T>
    nlohmann::json to_json(const BBox2D<T> &msg)
    {
        nlohmann::json j;

        j["xmin"] = msg.xmin;
        j["ymin"] = msg.ymin;
        j["xmax"] = msg.xmax;
        j["ymax"] = msg.ymax;

        return j;
    }
    template <>
    nlohmann::json to_json(const BBox2D<float> &msg)
    {
       return to_json(msg);
    }
    template <>
    nlohmann::json to_json(const BBox2D<double> &msg)
    {
       return to_json(msg);
    }
    template <typename T>
    BBox2D<T> from_json_BBox2D(nlohmann::json obj)
    {
        BBox2D<T> d;
        if (obj.contains("xmin"))
            d.xmin = (obj["xmin"].is_string()?(T)atof(obj["xmin"].get<std::string>().c_str()):obj["xmin"].get<T>());
        if (obj.contains("ymin"))
            d.ymin = (obj["ymin"].is_string()?(T)atof(obj["ymin"].get<std::string>().c_str()):obj["ymin"].get<T>());
        if (obj.contains("xmax"))
            d.xmax = (obj["xmax"].is_string()?(T)atof(obj["xmax"].get<std::string>().c_str()):obj["xmax"].get<T>());
        if (obj.contains("ymax"))
            d.ymax = (obj["ymax"].is_string()?(T)atof(obj["ymax"].get<std::string>().c_str()):obj["ymax"].get<T>());
        return d;
    }
    template <>
    BBox2D<double> from_json<BBox2D<double>>(nlohmann::json obj)
    {
        return from_json_BBox2D<double>(obj);
    }
    template <>
    BBox2D<float> from_json<BBox2D<float>>(nlohmann::json obj)
    {
        return from_json_BBox2D<float>(obj);
    }
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, BBox2D<T> &dt)
    {
        dt = from_json_BBox2D<T>(os);
        return os;
    }
    template <typename T>
    std::ostream &
    operator<<(std::ostream &os, const BBox2D<T> &dt)
    {
        return os << to_json(dt).dump();
    }
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const BBox2D<T> &dt)
    {
        return os << to_json(dt).dump();
    }
}
