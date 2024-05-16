#include "adapter/serialization/apollo_msgs/apollohdmap_speed_bump.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSpeedBump &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        nlohmann::json arr_position;
        for (auto it = msg.position.begin(); it != msg.position.end(); ++it) {
            arr_position.push_back(to_json(*it));
        }
        obj["position"] = arr_position;
        return obj;
    }
    ApollohdmapSpeedBump from_json_ApollohdmapSpeedBump (nlohmann::json obj) {
        ApollohdmapSpeedBump msg;
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
        if(obj.contains("position"))
        {
            if(obj["position"].is_array())
            {
                for (auto& element : obj["position"])
                {
                    msg.position.push_back(from_json_ApollohdmapCurve(element));
                }
            }
            else
            {
                msg.position.push_back(from_json_ApollohdmapCurve(obj["position"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapSpeedBump from_json<ApollohdmapSpeedBump>(nlohmann::json obj){
        return from_json_ApollohdmapSpeedBump(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSpeedBump &dt)
    {
        dt=from_json_ApollohdmapSpeedBump(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSpeedBump & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSpeedBump & dt)
    {
        os << to_json(dt);
        return os;
    }
}
