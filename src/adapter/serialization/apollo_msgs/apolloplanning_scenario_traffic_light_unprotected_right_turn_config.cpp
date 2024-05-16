#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_traffic_light_unprotected_right_turn_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig &msg) {
        nlohmann::json obj;
        obj["starttrafficlightscenariodistance"] = (msg.starttrafficlightscenariodistance);
        obj["enablerightturnonred"] = (msg.enablerightturnonred);
        obj["maxvalidstopdistance"] = (msg.maxvalidstopdistance);
        obj["minpasssdistance"] = (msg.minpasssdistance);
        obj["redlightrightturnstopdurationsec"] = (msg.redlightrightturnstopdurationsec);
        obj["creeptimeoutsec"] = (msg.creeptimeoutsec);
        obj["maxadcspeedbeforecreep"] = (msg.maxadcspeedbeforecreep);
        return obj;
    }
    ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig from_json_ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig (nlohmann::json obj) {
        ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig msg;
        if(obj.contains("starttrafficlightscenariodistance"))
        {
            msg.starttrafficlightscenariodistance = (obj["starttrafficlightscenariodistance"].is_string()?atof(obj["starttrafficlightscenariodistance"].get<std::string>().c_str()):obj["starttrafficlightscenariodistance"].get<double>());
        }
        if(obj.contains("enablerightturnonred"))
        {
            msg.enablerightturnonred = (obj["enablerightturnonred"].is_string()?(bool)atoi(obj["enablerightturnonred"].get<std::string>().c_str()):obj["enablerightturnonred"].get<bool>());
        }
        if(obj.contains("maxvalidstopdistance"))
        {
            msg.maxvalidstopdistance = (obj["maxvalidstopdistance"].is_string()?atof(obj["maxvalidstopdistance"].get<std::string>().c_str()):obj["maxvalidstopdistance"].get<double>());
        }
        if(obj.contains("minpasssdistance"))
        {
            msg.minpasssdistance = (obj["minpasssdistance"].is_string()?atof(obj["minpasssdistance"].get<std::string>().c_str()):obj["minpasssdistance"].get<double>());
        }
        if(obj.contains("redlightrightturnstopdurationsec"))
        {
            msg.redlightrightturnstopdurationsec = (obj["redlightrightturnstopdurationsec"].is_string()?(float)atof(obj["redlightrightturnstopdurationsec"].get<std::string>().c_str()):obj["redlightrightturnstopdurationsec"].get<float>());
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
    ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig from_json<ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
