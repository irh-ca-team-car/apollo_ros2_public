#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_traffic_light_unprotected_left_turn_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig &msg) {
        nlohmann::json obj;
        obj["starttrafficlightscenariodistance"] = (msg.starttrafficlightscenariodistance);
        obj["approachcruisespeed"] = (msg.approachcruisespeed);
        obj["maxvalidstopdistance"] = (msg.maxvalidstopdistance);
        obj["minpasssdistance"] = (msg.minpasssdistance);
        obj["creeptimeoutsec"] = (msg.creeptimeoutsec);
        obj["maxadcspeedbeforecreep"] = (msg.maxadcspeedbeforecreep);
        return obj;
    }
    ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig from_json_ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig (nlohmann::json obj) {
        ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig msg;
        if(obj.contains("starttrafficlightscenariodistance"))
        {
            msg.starttrafficlightscenariodistance = (obj["starttrafficlightscenariodistance"].is_string()?atof(obj["starttrafficlightscenariodistance"].get<std::string>().c_str()):obj["starttrafficlightscenariodistance"].get<double>());
        }
        if(obj.contains("approachcruisespeed"))
        {
            msg.approachcruisespeed = (obj["approachcruisespeed"].is_string()?atof(obj["approachcruisespeed"].get<std::string>().c_str()):obj["approachcruisespeed"].get<double>());
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
        if(obj.contains("maxadcspeedbeforecreep"))
        {
            msg.maxadcspeedbeforecreep = (obj["maxadcspeedbeforecreep"].is_string()?atof(obj["maxadcspeedbeforecreep"].get<std::string>().c_str()):obj["maxadcspeedbeforecreep"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig from_json<ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
