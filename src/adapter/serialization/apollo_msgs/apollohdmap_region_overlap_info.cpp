#include "adapter/serialization/apollo_msgs/apollohdmap_region_overlap_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRegionOverlapInfo &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        nlohmann::json arr_polygon;
        for (auto it = msg.polygon.begin(); it != msg.polygon.end(); ++it) {
            arr_polygon.push_back(to_json(*it));
        }
        obj["polygon"] = arr_polygon;
        return obj;
    }
    ApollohdmapRegionOverlapInfo from_json_ApollohdmapRegionOverlapInfo (nlohmann::json obj) {
        ApollohdmapRegionOverlapInfo msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("polygon"))
        {
            if(obj["polygon"].is_array())
            {
                for (auto& element : obj["polygon"])
                {
                    msg.polygon.push_back(from_json_ApollohdmapPolygon(element));
                }
            }
            else
            {
                msg.polygon.push_back(from_json_ApollohdmapPolygon(obj["polygon"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapRegionOverlapInfo from_json<ApollohdmapRegionOverlapInfo>(nlohmann::json obj){
        return from_json_ApollohdmapRegionOverlapInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRegionOverlapInfo &dt)
    {
        dt=from_json_ApollohdmapRegionOverlapInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRegionOverlapInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRegionOverlapInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
