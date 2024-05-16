#include "adapter/serialization/apollo_msgs/apollocontrol_latency_stats.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolLatencyStats &msg) {
        nlohmann::json obj;
        obj["totaltimems"] = (msg.totaltimems);
        nlohmann::json arr_controllertimems;
        for (auto it = msg.controllertimems.begin(); it != msg.controllertimems.end(); ++it) {
            arr_controllertimems.push_back((*it));
        }
        obj["controllertimems"] = arr_controllertimems;
        obj["totaltimeexceeded"] = (msg.totaltimeexceeded);
        return obj;
    }
    ApollocontrolLatencyStats from_json_ApollocontrolLatencyStats (nlohmann::json obj) {
        ApollocontrolLatencyStats msg;
        if(obj.contains("totaltimems"))
        {
            msg.totaltimems = (obj["totaltimems"].is_string()?atof(obj["totaltimems"].get<std::string>().c_str()):obj["totaltimems"].get<double>());
        }
        if(obj.contains("controllertimems"))
        {
            if(obj["controllertimems"].is_array())
            {
                for (auto& element : obj["controllertimems"])
                {
                    msg.controllertimems.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.controllertimems.push_back((obj["controllertimems"].is_string()?atof(obj["controllertimems"].get<std::string>().c_str()):obj["controllertimems"].get<double>()));
            }
        }
        if(obj.contains("totaltimeexceeded"))
        {
            msg.totaltimeexceeded = (obj["totaltimeexceeded"].is_string()?(bool)atoi(obj["totaltimeexceeded"].get<std::string>().c_str()):obj["totaltimeexceeded"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocontrolLatencyStats from_json<ApollocontrolLatencyStats>(nlohmann::json obj){
        return from_json_ApollocontrolLatencyStats(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolLatencyStats &dt)
    {
        dt=from_json_ApollocontrolLatencyStats(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolLatencyStats & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolLatencyStats & dt)
    {
        os << to_json(dt);
        return os;
    }
}
