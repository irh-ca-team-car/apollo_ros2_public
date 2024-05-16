#include "adapter/serialization/apollo_msgs/apolloplanning_creep_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCreepDeciderConfig &msg) {
        nlohmann::json obj;
        obj["stopdistance"] = (msg.stopdistance);
        obj["speedlimit"] = (msg.speedlimit);
        obj["maxvalidstopdistance"] = (msg.maxvalidstopdistance);
        obj["minboundaryt"] = (msg.minboundaryt);
        obj["ignoremaxstmint"] = (msg.ignoremaxstmint);
        obj["ignoreminstmins"] = (msg.ignoreminstmins);
        return obj;
    }
    ApolloplanningCreepDeciderConfig from_json_ApolloplanningCreepDeciderConfig (nlohmann::json obj) {
        ApolloplanningCreepDeciderConfig msg;
        if(obj.contains("stopdistance"))
        {
            msg.stopdistance = (obj["stopdistance"].is_string()?atof(obj["stopdistance"].get<std::string>().c_str()):obj["stopdistance"].get<double>());
        }
        if(obj.contains("speedlimit"))
        {
            msg.speedlimit = (obj["speedlimit"].is_string()?atof(obj["speedlimit"].get<std::string>().c_str()):obj["speedlimit"].get<double>());
        }
        if(obj.contains("maxvalidstopdistance"))
        {
            msg.maxvalidstopdistance = (obj["maxvalidstopdistance"].is_string()?atof(obj["maxvalidstopdistance"].get<std::string>().c_str()):obj["maxvalidstopdistance"].get<double>());
        }
        if(obj.contains("minboundaryt"))
        {
            msg.minboundaryt = (obj["minboundaryt"].is_string()?atof(obj["minboundaryt"].get<std::string>().c_str()):obj["minboundaryt"].get<double>());
        }
        if(obj.contains("ignoremaxstmint"))
        {
            msg.ignoremaxstmint = (obj["ignoremaxstmint"].is_string()?atof(obj["ignoremaxstmint"].get<std::string>().c_str()):obj["ignoremaxstmint"].get<double>());
        }
        if(obj.contains("ignoreminstmins"))
        {
            msg.ignoreminstmins = (obj["ignoreminstmins"].is_string()?atof(obj["ignoreminstmins"].get<std::string>().c_str()):obj["ignoreminstmins"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningCreepDeciderConfig from_json<ApolloplanningCreepDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningCreepDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCreepDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningCreepDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCreepDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCreepDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
