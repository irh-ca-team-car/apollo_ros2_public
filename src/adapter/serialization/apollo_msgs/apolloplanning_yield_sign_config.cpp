#include "adapter/serialization/apollo_msgs/apolloplanning_yield_sign_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningYieldSignConfig &msg) {
        nlohmann::json obj;
        obj["enabled"] = (msg.enabled);
        obj["stopdistance"] = (msg.stopdistance);
        obj["startwatchdistance"] = (msg.startwatchdistance);
        return obj;
    }
    ApolloplanningYieldSignConfig from_json_ApolloplanningYieldSignConfig (nlohmann::json obj) {
        ApolloplanningYieldSignConfig msg;
        if(obj.contains("enabled"))
        {
            msg.enabled = (obj["enabled"].is_string()?(bool)atoi(obj["enabled"].get<std::string>().c_str()):obj["enabled"].get<bool>());
        }
        if(obj.contains("stopdistance"))
        {
            msg.stopdistance = (obj["stopdistance"].is_string()?atof(obj["stopdistance"].get<std::string>().c_str()):obj["stopdistance"].get<double>());
        }
        if(obj.contains("startwatchdistance"))
        {
            msg.startwatchdistance = (obj["startwatchdistance"].is_string()?atof(obj["startwatchdistance"].get<std::string>().c_str()):obj["startwatchdistance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningYieldSignConfig from_json<ApolloplanningYieldSignConfig>(nlohmann::json obj){
        return from_json_ApolloplanningYieldSignConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningYieldSignConfig &dt)
    {
        dt=from_json_ApolloplanningYieldSignConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningYieldSignConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningYieldSignConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
