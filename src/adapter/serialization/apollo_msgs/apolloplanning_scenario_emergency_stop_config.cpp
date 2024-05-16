#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_emergency_stop_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioEmergencyStopConfig &msg) {
        nlohmann::json obj;
        obj["maxstopdeceleration"] = (msg.maxstopdeceleration);
        obj["stopdistance"] = (msg.stopdistance);
        return obj;
    }
    ApolloplanningScenarioEmergencyStopConfig from_json_ApolloplanningScenarioEmergencyStopConfig (nlohmann::json obj) {
        ApolloplanningScenarioEmergencyStopConfig msg;
        if(obj.contains("maxstopdeceleration"))
        {
            msg.maxstopdeceleration = (obj["maxstopdeceleration"].is_string()?atof(obj["maxstopdeceleration"].get<std::string>().c_str()):obj["maxstopdeceleration"].get<double>());
        }
        if(obj.contains("stopdistance"))
        {
            msg.stopdistance = (obj["stopdistance"].is_string()?atof(obj["stopdistance"].get<std::string>().c_str()):obj["stopdistance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioEmergencyStopConfig from_json<ApolloplanningScenarioEmergencyStopConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioEmergencyStopConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioEmergencyStopConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioEmergencyStopConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioEmergencyStopConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioEmergencyStopConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
