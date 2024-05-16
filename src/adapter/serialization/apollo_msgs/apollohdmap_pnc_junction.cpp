#include "adapter/serialization/apollo_msgs/apollohdmap_pnc_junction.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapPNCJunction &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        obj["polygon"] = to_json(msg.polygon);
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        nlohmann::json arr_passagegroup;
        for (auto it = msg.passagegroup.begin(); it != msg.passagegroup.end(); ++it) {
            arr_passagegroup.push_back(to_json(*it));
        }
        obj["passagegroup"] = arr_passagegroup;
        return obj;
    }
    ApollohdmapPNCJunction from_json_ApollohdmapPNCJunction (nlohmann::json obj) {
        ApollohdmapPNCJunction msg;
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
        if(obj.contains("passagegroup"))
        {
            if(obj["passagegroup"].is_array())
            {
                for (auto& element : obj["passagegroup"])
                {
                    msg.passagegroup.push_back(from_json_ApollohdmapPassageGroup(element));
                }
            }
            else
            {
                msg.passagegroup.push_back(from_json_ApollohdmapPassageGroup(obj["passagegroup"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapPNCJunction from_json<ApollohdmapPNCJunction>(nlohmann::json obj){
        return from_json_ApollohdmapPNCJunction(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapPNCJunction &dt)
    {
        dt=from_json_ApollohdmapPNCJunction(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapPNCJunction & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapPNCJunction & dt)
    {
        os << to_json(dt);
        return os;
    }
}
