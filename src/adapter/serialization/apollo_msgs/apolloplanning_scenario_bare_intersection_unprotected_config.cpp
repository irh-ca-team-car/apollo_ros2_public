#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_bare_intersection_unprotected_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioBareIntersectionUnprotectedConfig &msg) {
        nlohmann::json obj;
        obj["startbareintersectionscenariodistance"] = (msg.startbareintersectionscenariodistance);
        obj["enableexplicitstop"] = (msg.enableexplicitstop);
        obj["minpasssdistance"] = (msg.minpasssdistance);
        obj["approachcruisespeed"] = (msg.approachcruisespeed);
        obj["stopdistance"] = (msg.stopdistance);
        obj["stoptimeoutsec"] = (msg.stoptimeoutsec);
        obj["creeptimeoutsec"] = (msg.creeptimeoutsec);
        return obj;
    }
    ApolloplanningScenarioBareIntersectionUnprotectedConfig from_json_ApolloplanningScenarioBareIntersectionUnprotectedConfig (nlohmann::json obj) {
        ApolloplanningScenarioBareIntersectionUnprotectedConfig msg;
        if(obj.contains("startbareintersectionscenariodistance"))
        {
            msg.startbareintersectionscenariodistance = (obj["startbareintersectionscenariodistance"].is_string()?atof(obj["startbareintersectionscenariodistance"].get<std::string>().c_str()):obj["startbareintersectionscenariodistance"].get<double>());
        }
        if(obj.contains("enableexplicitstop"))
        {
            msg.enableexplicitstop = (obj["enableexplicitstop"].is_string()?(bool)atoi(obj["enableexplicitstop"].get<std::string>().c_str()):obj["enableexplicitstop"].get<bool>());
        }
        if(obj.contains("minpasssdistance"))
        {
            msg.minpasssdistance = (obj["minpasssdistance"].is_string()?atof(obj["minpasssdistance"].get<std::string>().c_str()):obj["minpasssdistance"].get<double>());
        }
        if(obj.contains("approachcruisespeed"))
        {
            msg.approachcruisespeed = (obj["approachcruisespeed"].is_string()?atof(obj["approachcruisespeed"].get<std::string>().c_str()):obj["approachcruisespeed"].get<double>());
        }
        if(obj.contains("stopdistance"))
        {
            msg.stopdistance = (obj["stopdistance"].is_string()?atof(obj["stopdistance"].get<std::string>().c_str()):obj["stopdistance"].get<double>());
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
    ApolloplanningScenarioBareIntersectionUnprotectedConfig from_json<ApolloplanningScenarioBareIntersectionUnprotectedConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioBareIntersectionUnprotectedConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioBareIntersectionUnprotectedConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioBareIntersectionUnprotectedConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioBareIntersectionUnprotectedConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioBareIntersectionUnprotectedConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
