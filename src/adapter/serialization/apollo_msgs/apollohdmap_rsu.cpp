#include "adapter/serialization/apollo_msgs/apollohdmap_rsu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRSU &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        obj["junctionid"] = to_json(msg.junctionid);
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        return obj;
    }
    ApollohdmapRSU from_json_ApollohdmapRSU (nlohmann::json obj) {
        ApollohdmapRSU msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("junctionid"))
        {
            msg.junctionid = from_json_ApollohdmapId(obj["junctionid"]);
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
    ApollohdmapRSU from_json<ApollohdmapRSU>(nlohmann::json obj){
        return from_json_ApollohdmapRSU(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRSU &dt)
    {
        dt=from_json_ApollohdmapRSU(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRSU & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRSU & dt)
    {
        os << to_json(dt);
        return os;
    }
}
