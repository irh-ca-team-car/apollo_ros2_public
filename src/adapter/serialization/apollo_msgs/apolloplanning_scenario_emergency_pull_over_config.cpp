#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_emergency_pull_over_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioEmergencyPullOverConfig &msg) {
        nlohmann::json obj;
        obj["maxstopdeceleration"] = (msg.maxstopdeceleration);
        obj["slowdowndecelerationtime"] = (msg.slowdowndecelerationtime);
        obj["targetslowdownspeed"] = (msg.targetslowdownspeed);
        obj["stopdistance"] = (msg.stopdistance);
        return obj;
    }
    ApolloplanningScenarioEmergencyPullOverConfig from_json_ApolloplanningScenarioEmergencyPullOverConfig (nlohmann::json obj) {
        ApolloplanningScenarioEmergencyPullOverConfig msg;
        if(obj.contains("maxstopdeceleration"))
        {
            msg.maxstopdeceleration = (obj["maxstopdeceleration"].is_string()?atof(obj["maxstopdeceleration"].get<std::string>().c_str()):obj["maxstopdeceleration"].get<double>());
        }
        if(obj.contains("slowdowndecelerationtime"))
        {
            msg.slowdowndecelerationtime = (obj["slowdowndecelerationtime"].is_string()?atof(obj["slowdowndecelerationtime"].get<std::string>().c_str()):obj["slowdowndecelerationtime"].get<double>());
        }
        if(obj.contains("targetslowdownspeed"))
        {
            msg.targetslowdownspeed = (obj["targetslowdownspeed"].is_string()?atof(obj["targetslowdownspeed"].get<std::string>().c_str()):obj["targetslowdownspeed"].get<double>());
        }
        if(obj.contains("stopdistance"))
        {
            msg.stopdistance = (obj["stopdistance"].is_string()?atof(obj["stopdistance"].get<std::string>().c_str()):obj["stopdistance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioEmergencyPullOverConfig from_json<ApolloplanningScenarioEmergencyPullOverConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioEmergencyPullOverConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioEmergencyPullOverConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioEmergencyPullOverConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioEmergencyPullOverConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioEmergencyPullOverConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
