#include "adapter/serialization/internal/hdmap/junctioninfo.h"
#include "adapter/serialization/internal/common/polygon2d.h"

namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::hdmap::JunctionInfo &msg)
    {
        nlohmann::json obj;
        obj["junction_"] = to_json(msg.junction_);
        obj["polygon_"] = to_json(msg.polygon_);
        nlohmann::json lst1;
        for (auto &&i : msg.overlap_stop_sign_ids_)
        {
            lst1.push_back(to_json(i));
        }
        obj["overlap_stop_sign_ids_"] = lst1;
        nlohmann::json lst2;
        for (auto &&i : msg.overlap_ids_)
        {
            lst1.push_back(to_json(i));
        }
        obj["overlap_ids_"] = lst2;
        return obj;
    }
    apollo::hdmap::JunctionInfo from_json_JunctionInfo(nlohmann::json obj)
    {
        ApollohdmapJunction j;
        j = from_json_ApollohdmapJunction(obj["junction_"]);
        apollo::hdmap::JunctionInfo msg(j);
        msg.polygon_ = from_json_Polygon2d(obj["polygon_"]);
        if (obj.contains("overlap_stop_sign_ids_"))
            for (auto &element : obj["overlap_stop_sign_ids_"])
            {
                msg.overlap_stop_sign_ids_.push_back(from_json_ApollohdmapId(element));
            }
        if (obj.contains("overlap_ids_"))
            for (auto &element : obj["overlap_ids_"])
            {
                msg.overlap_ids_.push_back(from_json_ApollohdmapId(element));
            }

        return msg;
    }
    template <>
    apollo::hdmap::JunctionInfo from_json<apollo::hdmap::JunctionInfo>(nlohmann::json obj)
    {
        return from_json_JunctionInfo(obj);
    }

    std::ostream &
    operator<<(std::ostream &os, const apollo::hdmap::JunctionInfo &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::hdmap::JunctionInfo &dt)
    {
        return os << to_json(dt).dump();
    }
}
