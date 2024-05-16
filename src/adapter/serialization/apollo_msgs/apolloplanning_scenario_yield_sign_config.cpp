#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_yield_sign_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioYieldSignConfig &msg) {
        nlohmann::json obj;
        obj["startyieldsignscenariodistance"] = (msg.startyieldsignscenariodistance);
        obj["maxvalidstopdistance"] = (msg.maxvalidstopdistance);
        obj["minpasssdistance"] = (msg.minpasssdistance);
        obj["creeptimeoutsec"] = (msg.creeptimeoutsec);
        return obj;
    }
    ApolloplanningScenarioYieldSignConfig from_json_ApolloplanningScenarioYieldSignConfig (nlohmann::json obj) {
        ApolloplanningScenarioYieldSignConfig msg;
        if(obj.contains("startyieldsignscenariodistance"))
        {
            msg.startyieldsignscenariodistance = (obj["startyieldsignscenariodistance"].is_string()?atof(obj["startyieldsignscenariodistance"].get<std::string>().c_str()):obj["startyieldsignscenariodistance"].get<double>());
        }
        if(obj.contains("maxvalidstopdistance"))
        {
            msg.maxvalidstopdistance = (obj["maxvalidstopdistance"].is_string()?atof(obj["maxvalidstopdistance"].get<std::string>().c_str()):obj["maxvalidstopdistance"].get<double>());
        }
        if(obj.contains("minpasssdistance"))
        {
            msg.minpasssdistance = (obj["minpasssdistance"].is_string()?atof(obj["minpasssdistance"].get<std::string>().c_str()):obj["minpasssdistance"].get<double>());
        }
        if(obj.contains("creeptimeoutsec"))
        {
            msg.creeptimeoutsec = (obj["creeptimeoutsec"].is_string()?(float)atof(obj["creeptimeoutsec"].get<std::string>().c_str()):obj["creeptimeoutsec"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioYieldSignConfig from_json<ApolloplanningScenarioYieldSignConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioYieldSignConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioYieldSignConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioYieldSignConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioYieldSignConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioYieldSignConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
