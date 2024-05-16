#include "adapter/serialization/apollo_msgs/apolloplanning_crosswalk_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCrosswalkConfig &msg) {
        nlohmann::json obj;
        obj["stopdistance"] = (msg.stopdistance);
        obj["maxstopdeceleration"] = (msg.maxstopdeceleration);
        obj["minpasssdistance"] = (msg.minpasssdistance);
        obj["maxvalidstopdistance"] = (msg.maxvalidstopdistance);
        obj["expandsdistance"] = (msg.expandsdistance);
        obj["stopstrictldistance"] = (msg.stopstrictldistance);
        obj["stoplooseldistance"] = (msg.stoplooseldistance);
        obj["stoptimeout"] = (msg.stoptimeout);
        return obj;
    }
    ApolloplanningCrosswalkConfig from_json_ApolloplanningCrosswalkConfig (nlohmann::json obj) {
        ApolloplanningCrosswalkConfig msg;
        if(obj.contains("stopdistance"))
        {
            msg.stopdistance = (obj["stopdistance"].is_string()?atof(obj["stopdistance"].get<std::string>().c_str()):obj["stopdistance"].get<double>());
        }
        if(obj.contains("maxstopdeceleration"))
        {
            msg.maxstopdeceleration = (obj["maxstopdeceleration"].is_string()?atof(obj["maxstopdeceleration"].get<std::string>().c_str()):obj["maxstopdeceleration"].get<double>());
        }
        if(obj.contains("minpasssdistance"))
        {
            msg.minpasssdistance = (obj["minpasssdistance"].is_string()?atof(obj["minpasssdistance"].get<std::string>().c_str()):obj["minpasssdistance"].get<double>());
        }
        if(obj.contains("maxvalidstopdistance"))
        {
            msg.maxvalidstopdistance = (obj["maxvalidstopdistance"].is_string()?atof(obj["maxvalidstopdistance"].get<std::string>().c_str()):obj["maxvalidstopdistance"].get<double>());
        }
        if(obj.contains("expandsdistance"))
        {
            msg.expandsdistance = (obj["expandsdistance"].is_string()?atof(obj["expandsdistance"].get<std::string>().c_str()):obj["expandsdistance"].get<double>());
        }
        if(obj.contains("stopstrictldistance"))
        {
            msg.stopstrictldistance = (obj["stopstrictldistance"].is_string()?atof(obj["stopstrictldistance"].get<std::string>().c_str()):obj["stopstrictldistance"].get<double>());
        }
        if(obj.contains("stoplooseldistance"))
        {
            msg.stoplooseldistance = (obj["stoplooseldistance"].is_string()?atof(obj["stoplooseldistance"].get<std::string>().c_str()):obj["stoplooseldistance"].get<double>());
        }
        if(obj.contains("stoptimeout"))
        {
            msg.stoptimeout = (obj["stoptimeout"].is_string()?atof(obj["stoptimeout"].get<std::string>().c_str()):obj["stoptimeout"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningCrosswalkConfig from_json<ApolloplanningCrosswalkConfig>(nlohmann::json obj){
        return from_json_ApolloplanningCrosswalkConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCrosswalkConfig &dt)
    {
        dt=from_json_ApolloplanningCrosswalkConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCrosswalkConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCrosswalkConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
