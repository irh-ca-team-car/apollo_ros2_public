#include "adapter/serialization/apollo_msgs/apollohdmap_yield_sign.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapYieldSign &msg) {
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
        return obj;
    }
    ApollohdmapYieldSign from_json_ApollohdmapYieldSign (nlohmann::json obj) {
        ApollohdmapYieldSign msg;
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
        return msg;
    }
    template <>
    ApollohdmapYieldSign from_json<ApollohdmapYieldSign>(nlohmann::json obj){
        return from_json_ApollohdmapYieldSign(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapYieldSign &dt)
    {
        dt=from_json_ApollohdmapYieldSign(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapYieldSign & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapYieldSign & dt)
    {
        os << to_json(dt);
        return os;
    }
}
