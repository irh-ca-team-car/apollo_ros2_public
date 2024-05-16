#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_traffic_light_protected_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioTrafficLightProtectedConfig &msg) {
        nlohmann::json obj;
        obj["starttrafficlightscenariodistance"] = (msg.starttrafficlightscenariodistance);
        obj["maxvalidstopdistance"] = (msg.maxvalidstopdistance);
        obj["minpasssdistance"] = (msg.minpasssdistance);
        return obj;
    }
    ApolloplanningScenarioTrafficLightProtectedConfig from_json_ApolloplanningScenarioTrafficLightProtectedConfig (nlohmann::json obj) {
        ApolloplanningScenarioTrafficLightProtectedConfig msg;
        if(obj.contains("starttrafficlightscenariodistance"))
        {
            msg.starttrafficlightscenariodistance = (obj["starttrafficlightscenariodistance"].is_string()?atof(obj["starttrafficlightscenariodistance"].get<std::string>().c_str()):obj["starttrafficlightscenariodistance"].get<double>());
        }
        if(obj.contains("maxvalidstopdistance"))
        {
            msg.maxvalidstopdistance = (obj["maxvalidstopdistance"].is_string()?atof(obj["maxvalidstopdistance"].get<std::string>().c_str()):obj["maxvalidstopdistance"].get<double>());
        }
        if(obj.contains("minpasssdistance"))
        {
            msg.minpasssdistance = (obj["minpasssdistance"].is_string()?atof(obj["minpasssdistance"].get<std::string>().c_str()):obj["minpasssdistance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioTrafficLightProtectedConfig from_json<ApolloplanningScenarioTrafficLightProtectedConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioTrafficLightProtectedConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioTrafficLightProtectedConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioTrafficLightProtectedConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioTrafficLightProtectedConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioTrafficLightProtectedConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
