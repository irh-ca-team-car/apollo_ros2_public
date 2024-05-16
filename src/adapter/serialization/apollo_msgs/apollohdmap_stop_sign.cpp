#include "adapter/serialization/apollo_msgs/apollohdmap_stop_sign.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapStopSign &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        nlohmann::json arr_stopline;
        for (auto it = msg.stopline.begin(); it != msg.stopline.end(); ++it) {
            arr_stopline.push_back(to_json(*it));
        }
        obj["stopline"] = arr_stopline;
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        obj["type"] = (msg.type);
        return obj;
    }
    ApollohdmapStopSign from_json_ApollohdmapStopSign (nlohmann::json obj) {
        ApollohdmapStopSign msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("stopline"))
        {
            if(obj["stopline"].is_array())
            {
                for (auto& element : obj["stopline"])
                {
                    msg.stopline.push_back(from_json_ApollohdmapCurve(element));
                }
            }
            else
            {
                msg.stopline.push_back(from_json_ApollohdmapCurve(obj["stopline"]));
            }
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
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApollohdmapStopSign from_json<ApollohdmapStopSign>(nlohmann::json obj){
        return from_json_ApollohdmapStopSign(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapStopSign &dt)
    {
        dt=from_json_ApollohdmapStopSign(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapStopSign & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapStopSign & dt)
    {
        os << to_json(dt);
        return os;
    }
}
