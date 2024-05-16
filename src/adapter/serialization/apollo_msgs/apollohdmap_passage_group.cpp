#include "adapter/serialization/apollo_msgs/apollohdmap_passage_group.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapPassageGroup &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        nlohmann::json arr_passage;
        for (auto it = msg.passage.begin(); it != msg.passage.end(); ++it) {
            arr_passage.push_back(to_json(*it));
        }
        obj["passage"] = arr_passage;
        return obj;
    }
    ApollohdmapPassageGroup from_json_ApollohdmapPassageGroup (nlohmann::json obj) {
        ApollohdmapPassageGroup msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("passage"))
        {
            if(obj["passage"].is_array())
            {
                for (auto& element : obj["passage"])
                {
                    msg.passage.push_back(from_json_ApollohdmapPassage(element));
                }
            }
            else
            {
                msg.passage.push_back(from_json_ApollohdmapPassage(obj["passage"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapPassageGroup from_json<ApollohdmapPassageGroup>(nlohmann::json obj){
        return from_json_ApollohdmapPassageGroup(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapPassageGroup &dt)
    {
        dt=from_json_ApollohdmapPassageGroup(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapPassageGroup & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapPassageGroup & dt)
    {
        os << to_json(dt);
        return os;
    }
}
