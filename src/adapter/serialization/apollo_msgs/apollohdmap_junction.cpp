#include "adapter/serialization/apollo_msgs/apollohdmap_junction.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapJunction &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        obj["polygon"] = to_json(msg.polygon);
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        return obj;
    }
    ApollohdmapJunction from_json_ApollohdmapJunction (nlohmann::json obj) {
        ApollohdmapJunction msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("polygon"))
        {
            msg.polygon = from_json_ApollohdmapPolygon(obj["polygon"]);
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
        return msg;
    }
    template <>
    ApollohdmapJunction from_json<ApollohdmapJunction>(nlohmann::json obj){
        return from_json_ApollohdmapJunction(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapJunction &dt)
    {
        dt=from_json_ApollohdmapJunction(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapJunction & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapJunction & dt)
    {
        os << to_json(dt);
        return os;
    }
}
