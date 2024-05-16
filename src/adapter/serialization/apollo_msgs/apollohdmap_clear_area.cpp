#include "adapter/serialization/apollo_msgs/apollohdmap_clear_area.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapClearArea &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        obj["polygon"] = to_json(msg.polygon);
        return obj;
    }
    ApollohdmapClearArea from_json_ApollohdmapClearArea (nlohmann::json obj) {
        ApollohdmapClearArea msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("overlapid"))
        {
            if(obj["overlapid"].is_array())
            {
                for (auto& element : obj["overlapid"])
                {
                    msg.overlapid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.overlapid.push_back(from_json_ApollohdmapId(obj["overlapid"]));
            }
        }
        if(obj.contains("polygon"))
        {
            msg.polygon = from_json_ApollohdmapPolygon(obj["polygon"]);
        }
        return msg;
    }
    template <>
    ApollohdmapClearArea from_json<ApollohdmapClearArea>(nlohmann::json obj){
        return from_json_ApollohdmapClearArea(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapClearArea &dt)
    {
        dt=from_json_ApollohdmapClearArea(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapClearArea & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapClearArea & dt)
    {
        os << to_json(dt);
        return os;
    }
}
