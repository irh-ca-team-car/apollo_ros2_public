#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficLightConfig &msg) {
        nlohmann::json obj;
        obj["enabled"] = (msg.enabled);
        obj["stopdistance"] = (msg.stopdistance);
        obj["maxstopdeceleration"] = (msg.maxstopdeceleration);
        return obj;
    }
    ApolloplanningTrafficLightConfig from_json_ApolloplanningTrafficLightConfig (nlohmann::json obj) {
        ApolloplanningTrafficLightConfig msg;
        if(obj.contains("enabled"))
        {
            msg.enabled = (obj["enabled"].is_string()?(bool)atoi(obj["enabled"].get<std::string>().c_str()):obj["enabled"].get<bool>());
        }
        if(obj.contains("stopdistance"))
        {
            msg.stopdistance = (obj["stopdistance"].is_string()?atof(obj["stopdistance"].get<std::string>().c_str()):obj["stopdistance"].get<double>());
        }
        if(obj.contains("maxstopdeceleration"))
        {
            msg.maxstopdeceleration = (obj["maxstopdeceleration"].is_string()?atof(obj["maxstopdeceleration"].get<std::string>().c_str()):obj["maxstopdeceleration"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningTrafficLightConfig from_json<ApolloplanningTrafficLightConfig>(nlohmann::json obj){
        return from_json_ApolloplanningTrafficLightConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficLightConfig &dt)
    {
        dt=from_json_ApolloplanningTrafficLightConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficLightConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficLightConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
