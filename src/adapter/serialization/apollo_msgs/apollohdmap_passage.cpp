#include "adapter/serialization/apollo_msgs/apollohdmap_passage.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapPassage &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        nlohmann::json arr_signalid;
        for (auto it = msg.signalid.begin(); it != msg.signalid.end(); ++it) {
            arr_signalid.push_back(to_json(*it));
        }
        obj["signalid"] = arr_signalid;
        nlohmann::json arr_yieldid;
        for (auto it = msg.yieldid.begin(); it != msg.yieldid.end(); ++it) {
            arr_yieldid.push_back(to_json(*it));
        }
        obj["yieldid"] = arr_yieldid;
        nlohmann::json arr_stopsignid;
        for (auto it = msg.stopsignid.begin(); it != msg.stopsignid.end(); ++it) {
            arr_stopsignid.push_back(to_json(*it));
        }
        obj["stopsignid"] = arr_stopsignid;
        nlohmann::json arr_laneid;
        for (auto it = msg.laneid.begin(); it != msg.laneid.end(); ++it) {
            arr_laneid.push_back(to_json(*it));
        }
        obj["laneid"] = arr_laneid;
        obj["type"] = (msg.type);
        return obj;
    }
    ApollohdmapPassage from_json_ApollohdmapPassage (nlohmann::json obj) {
        ApollohdmapPassage msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("signalid"))
        {
            if(obj["signalid"].is_array())
            {
                for (auto& element : obj["signalid"])
                {
                    msg.signalid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.signalid.push_back(from_json_ApollohdmapId(obj["signalid"]));
            }
        }
        if(obj.contains("yieldid"))
        {
            if(obj["yieldid"].is_array())
            {
                for (auto& element : obj["yieldid"])
                {
                    msg.yieldid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.yieldid.push_back(from_json_ApollohdmapId(obj["yieldid"]));
            }
        }
        if(obj.contains("stopsignid"))
        {
            if(obj["stopsignid"].is_array())
            {
                for (auto& element : obj["stopsignid"])
                {
                    msg.stopsignid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.stopsignid.push_back(from_json_ApollohdmapId(obj["stopsignid"]));
            }
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
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApollohdmapPassage from_json<ApollohdmapPassage>(nlohmann::json obj){
        return from_json_ApollohdmapPassage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapPassage &dt)
    {
        dt=from_json_ApollohdmapPassage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapPassage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapPassage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
