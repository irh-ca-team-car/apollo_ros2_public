#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_stop_sign_unprotected_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioStopSignUnprotectedConfig &msg) {
        nlohmann::json obj;
        obj["startstopsignscenariodistance"] = (msg.startstopsignscenariodistance);
        obj["watchvehiclemaxvalidstopdistance"] = (msg.watchvehiclemaxvalidstopdistance);
        obj["maxvalidstopdistance"] = (msg.maxvalidstopdistance);
        obj["stopdurationsec"] = (msg.stopdurationsec);
        obj["minpasssdistance"] = (msg.minpasssdistance);
        obj["stoptimeoutsec"] = (msg.stoptimeoutsec);
        obj["creeptimeoutsec"] = (msg.creeptimeoutsec);
        return obj;
    }
    ApolloplanningScenarioStopSignUnprotectedConfig from_json_ApolloplanningScenarioStopSignUnprotectedConfig (nlohmann::json obj) {
        ApolloplanningScenarioStopSignUnprotectedConfig msg;
        if(obj.contains("startstopsignscenariodistance"))
        {
            msg.startstopsignscenariodistance = (obj["startstopsignscenariodistance"].is_string()?atof(obj["startstopsignscenariodistance"].get<std::string>().c_str()):obj["startstopsignscenariodistance"].get<double>());
        }
        if(obj.contains("watchvehiclemaxvalidstopdistance"))
        {
            msg.watchvehiclemaxvalidstopdistance = (obj["watchvehiclemaxvalidstopdistance"].is_string()?atof(obj["watchvehiclemaxvalidstopdistance"].get<std::string>().c_str()):obj["watchvehiclemaxvalidstopdistance"].get<double>());
        }
        if(obj.contains("maxvalidstopdistance"))
        {
            msg.maxvalidstopdistance = (obj["maxvalidstopdistance"].is_string()?atof(obj["maxvalidstopdistance"].get<std::string>().c_str()):obj["maxvalidstopdistance"].get<double>());
        }
        if(obj.contains("stopdurationsec"))
        {
            msg.stopdurationsec = (obj["stopdurationsec"].is_string()?(float)atof(obj["stopdurationsec"].get<std::string>().c_str()):obj["stopdurationsec"].get<float>());
        }
        if(obj.contains("minpasssdistance"))
        {
            msg.minpasssdistance = (obj["minpasssdistance"].is_string()?atof(obj["minpasssdistance"].get<std::string>().c_str()):obj["minpasssdistance"].get<double>());
        }
        if(obj.contains("stoptimeoutsec"))
        {
            msg.stoptimeoutsec = (obj["stoptimeoutsec"].is_string()?(float)atof(obj["stoptimeoutsec"].get<std::string>().c_str()):obj["stoptimeoutsec"].get<float>());
        }
        if(obj.contains("creeptimeoutsec"))
        {
            msg.creeptimeoutsec = (obj["creeptimeoutsec"].is_string()?(float)atof(obj["creeptimeoutsec"].get<std::string>().c_str()):obj["creeptimeoutsec"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioStopSignUnprotectedConfig from_json<ApolloplanningScenarioStopSignUnprotectedConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioStopSignUnprotectedConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioStopSignUnprotectedConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioStopSignUnprotectedConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioStopSignUnprotectedConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioStopSignUnprotectedConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
