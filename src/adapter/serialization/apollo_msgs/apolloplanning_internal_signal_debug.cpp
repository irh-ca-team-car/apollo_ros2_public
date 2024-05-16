#include "adapter/serialization/apollo_msgs/apolloplanning_internal_signal_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSignalDebug &msg) {
        nlohmann::json obj;
        obj["lightid"] = (msg.lightid);
        obj["color"] = (msg.color);
        obj["lightstops"] = (msg.lightstops);
        obj["adcstopdeceleration"] = (msg.adcstopdeceleration);
        obj["isstopwallcreated"] = (msg.isstopwallcreated);
        return obj;
    }
    ApolloplanningInternalSignalDebug from_json_ApolloplanningInternalSignalDebug (nlohmann::json obj) {
        ApolloplanningInternalSignalDebug msg;
        if(obj.contains("lightid"))
        {
            msg.lightid = (obj["lightid"].is_string()?(obj["lightid"].get<std::string>().c_str()):obj["lightid"].get<std::string>());
        }
        if(obj.contains("color"))
        {
            msg.color = (obj["color"].is_string()?atoi(obj["color"].get<std::string>().c_str()):obj["color"].get<int>());
        }
        if(obj.contains("lightstops"))
        {
            msg.lightstops = (obj["lightstops"].is_string()?atof(obj["lightstops"].get<std::string>().c_str()):obj["lightstops"].get<double>());
        }
        if(obj.contains("adcstopdeceleration"))
        {
            msg.adcstopdeceleration = (obj["adcstopdeceleration"].is_string()?atof(obj["adcstopdeceleration"].get<std::string>().c_str()):obj["adcstopdeceleration"].get<double>());
        }
        if(obj.contains("isstopwallcreated"))
        {
            msg.isstopwallcreated = (obj["isstopwallcreated"].is_string()?(bool)atoi(obj["isstopwallcreated"].get<std::string>().c_str()):obj["isstopwallcreated"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningInternalSignalDebug from_json<ApolloplanningInternalSignalDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalSignalDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSignalDebug &dt)
    {
        dt=from_json_ApolloplanningInternalSignalDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSignalDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSignalDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
