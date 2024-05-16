#include "adapter/serialization/apollo_msgs/apollohdmap_road.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRoad &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        nlohmann::json arr_section;
        for (auto it = msg.section.begin(); it != msg.section.end(); ++it) {
            arr_section.push_back(to_json(*it));
        }
        obj["section"] = arr_section;
        obj["junctionid"] = to_json(msg.junctionid);
        obj["type"] = (msg.type);
        return obj;
    }
    ApollohdmapRoad from_json_ApollohdmapRoad (nlohmann::json obj) {
        ApollohdmapRoad msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("section"))
        {
            if(obj["section"].is_array())
            {
                for (auto& element : obj["section"])
                {
                    msg.section.push_back(from_json_ApollohdmapRoadSection(element));
                }
            }
            else
            {
                msg.section.push_back(from_json_ApollohdmapRoadSection(obj["section"]));
            }
        }
        if(obj.contains("junctionid"))
        {
            msg.junctionid = from_json_ApollohdmapId(obj["junctionid"]);
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApollohdmapRoad from_json<ApollohdmapRoad>(nlohmann::json obj){
        return from_json_ApollohdmapRoad(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRoad &dt)
    {
        dt=from_json_ApollohdmapRoad(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRoad & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRoad & dt)
    {
        os << to_json(dt);
        return os;
    }
}
