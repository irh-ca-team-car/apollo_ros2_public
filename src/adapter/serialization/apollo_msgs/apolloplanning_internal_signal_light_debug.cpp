#include "adapter/serialization/apollo_msgs/apolloplanning_internal_signal_light_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSignalLightDebug &msg) {
        nlohmann::json obj;
        obj["adcspeed"] = (msg.adcspeed);
        obj["adcfronts"] = (msg.adcfronts);
        nlohmann::json arr_signal;
        for (auto it = msg.signal.begin(); it != msg.signal.end(); ++it) {
            arr_signal.push_back(to_json(*it));
        }
        obj["signal"] = arr_signal;
        return obj;
    }
    ApolloplanningInternalSignalLightDebug from_json_ApolloplanningInternalSignalLightDebug (nlohmann::json obj) {
        ApolloplanningInternalSignalLightDebug msg;
        if(obj.contains("adcspeed"))
        {
            msg.adcspeed = (obj["adcspeed"].is_string()?atof(obj["adcspeed"].get<std::string>().c_str()):obj["adcspeed"].get<double>());
        }
        if(obj.contains("adcfronts"))
        {
            msg.adcfronts = (obj["adcfronts"].is_string()?atof(obj["adcfronts"].get<std::string>().c_str()):obj["adcfronts"].get<double>());
        }
        if(obj.contains("signal"))
        {
            if(obj["signal"].is_array())
            {
                for (auto& element : obj["signal"])
                {
                    msg.signal.push_back(from_json_ApolloplanningInternalSignalDebug(element));
                }
            }
            else
            {
                msg.signal.push_back(from_json_ApolloplanningInternalSignalDebug(obj["signal"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalSignalLightDebug from_json<ApolloplanningInternalSignalLightDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalSignalLightDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSignalLightDebug &dt)
    {
        dt=from_json_ApolloplanningInternalSignalLightDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSignalLightDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSignalLightDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
