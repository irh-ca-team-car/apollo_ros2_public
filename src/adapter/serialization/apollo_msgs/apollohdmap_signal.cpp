#include "adapter/serialization/apollo_msgs/apollohdmap_signal.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSignal &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        obj["boundary"] = to_json(msg.boundary);
        nlohmann::json arr_subsignal;
        for (auto it = msg.subsignal.begin(); it != msg.subsignal.end(); ++it) {
            arr_subsignal.push_back(to_json(*it));
        }
        obj["subsignal"] = arr_subsignal;
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        obj["type"] = (msg.type);
        nlohmann::json arr_stopline;
        for (auto it = msg.stopline.begin(); it != msg.stopline.end(); ++it) {
            arr_stopline.push_back(to_json(*it));
        }
        obj["stopline"] = arr_stopline;
        nlohmann::json arr_signinfo;
        for (auto it = msg.signinfo.begin(); it != msg.signinfo.end(); ++it) {
            arr_signinfo.push_back(to_json(*it));
        }
        obj["signinfo"] = arr_signinfo;
        return obj;
    }
    ApollohdmapSignal from_json_ApollohdmapSignal (nlohmann::json obj) {
        ApollohdmapSignal msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("boundary"))
        {
            msg.boundary = from_json_ApollohdmapPolygon(obj["boundary"]);
        }
        if(obj.contains("subsignal"))
        {
            if(obj["subsignal"].is_array())
            {
                for (auto& element : obj["subsignal"])
                {
                    msg.subsignal.push_back(from_json_ApollohdmapSubsignal(element));
                }
            }
            else
            {
                msg.subsignal.push_back(from_json_ApollohdmapSubsignal(obj["subsignal"]));
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
        if(obj.contains("signinfo"))
        {
            if(obj["signinfo"].is_array())
            {
                for (auto& element : obj["signinfo"])
                {
                    msg.signinfo.push_back(from_json_ApollohdmapSignInfo(element));
                }
            }
            else
            {
                msg.signinfo.push_back(from_json_ApollohdmapSignInfo(obj["signinfo"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapSignal from_json<ApollohdmapSignal>(nlohmann::json obj){
        return from_json_ApollohdmapSignal(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSignal &dt)
    {
        dt=from_json_ApollohdmapSignal(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSignal & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSignal & dt)
    {
        os << to_json(dt);
        return os;
    }
}
