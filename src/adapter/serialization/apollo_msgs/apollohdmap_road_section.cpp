#include "adapter/serialization/apollo_msgs/apollohdmap_road_section.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRoadSection &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        nlohmann::json arr_laneid;
        for (auto it = msg.laneid.begin(); it != msg.laneid.end(); ++it) {
            arr_laneid.push_back(to_json(*it));
        }
        obj["laneid"] = arr_laneid;
        obj["boundary"] = to_json(msg.boundary);
        return obj;
    }
    ApollohdmapRoadSection from_json_ApollohdmapRoadSection (nlohmann::json obj) {
        ApollohdmapRoadSection msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("laneid"))
        {
            if(obj["laneid"].is_array())
            {
                for (auto& element : obj["laneid"])
                {
                    msg.laneid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.laneid.push_back(from_json_ApollohdmapId(obj["laneid"]));
            }
        }
        if(obj.contains("boundary"))
        {
            msg.boundary = from_json_ApollohdmapRoadBoundary(obj["boundary"]);
        }
        return msg;
    }
    template <>
    ApollohdmapRoadSection from_json<ApollohdmapRoadSection>(nlohmann::json obj){
        return from_json_ApollohdmapRoadSection(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRoadSection &dt)
    {
        dt=from_json_ApollohdmapRoadSection(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRoadSection & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRoadSection & dt)
    {
        os << to_json(dt);
        return os;
    }
}
