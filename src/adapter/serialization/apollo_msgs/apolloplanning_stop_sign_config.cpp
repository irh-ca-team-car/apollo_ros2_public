#include "adapter/serialization/apollo_msgs/apolloplanning_stop_sign_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStopSignConfig &msg) {
        nlohmann::json obj;
        obj["enabled"] = (msg.enabled);
        obj["stopdistance"] = (msg.stopdistance);
        return obj;
    }
    ApolloplanningStopSignConfig from_json_ApolloplanningStopSignConfig (nlohmann::json obj) {
        ApolloplanningStopSignConfig msg;
        if(obj.contains("enabled"))
        {
            msg.enabled = (obj["enabled"].is_string()?(bool)atoi(obj["enabled"].get<std::string>().c_str()):obj["enabled"].get<bool>());
        }
        if(obj.contains("stopdistance"))
        {
            msg.stopdistance = (obj["stopdistance"].is_string()?atof(obj["stopdistance"].get<std::string>().c_str()):obj["stopdistance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningStopSignConfig from_json<ApolloplanningStopSignConfig>(nlohmann::json obj){
        return from_json_ApolloplanningStopSignConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStopSignConfig &dt)
    {
        dt=from_json_ApolloplanningStopSignConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStopSignConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStopSignConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
