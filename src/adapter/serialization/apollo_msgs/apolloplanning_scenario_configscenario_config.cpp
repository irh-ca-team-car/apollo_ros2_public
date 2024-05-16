#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_configscenario_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioConfigscenarioConfig &msg) {
        nlohmann::json obj;
        obj["lanefollowconfig"] = (msg.lanefollowconfig);
        obj["bareintersectionunprotectedconfig"] = to_json(msg.bareintersectionunprotectedconfig);
        obj["emergencypulloverconfig"] = to_json(msg.emergencypulloverconfig);
        obj["emergencystopconfig"] = to_json(msg.emergencystopconfig);
        obj["learningmodelsampleconfig"] = (msg.learningmodelsampleconfig);
        obj["narrowstreetuturnconfig"] = (msg.narrowstreetuturnconfig);
        obj["parkandgoconfig"] = to_json(msg.parkandgoconfig);
        obj["pulloverconfig"] = to_json(msg.pulloverconfig);
        obj["stopsignunprotectedconfig"] = to_json(msg.stopsignunprotectedconfig);
        obj["trafficlightprotectedconfig"] = to_json(msg.trafficlightprotectedconfig);
        obj["trafficlightunprotectedleftturnconfig"] = to_json(msg.trafficlightunprotectedleftturnconfig);
        obj["trafficlightunprotectedrightturnconfig"] = to_json(msg.trafficlightunprotectedrightturnconfig);
        obj["valetparkingconfig"] = to_json(msg.valetparkingconfig);
        obj["yieldsignconfig"] = to_json(msg.yieldsignconfig);
        return obj;
    }
    ApolloplanningScenarioConfigscenarioConfig from_json_ApolloplanningScenarioConfigscenarioConfig (nlohmann::json obj) {
        ApolloplanningScenarioConfigscenarioConfig msg;
        if(obj.contains("lanefollowconfig"))
        {
            msg.lanefollowconfig = (obj["lanefollowconfig"].is_string()?atoi(obj["lanefollowconfig"].get<std::string>().c_str()):obj["lanefollowconfig"].get<int>());
        }
        if(obj.contains("bareintersectionunprotectedconfig"))
        {
            msg.bareintersectionunprotectedconfig = from_json_ApolloplanningScenarioBareIntersectionUnprotectedConfig(obj["bareintersectionunprotectedconfig"]);
        }
        if(obj.contains("emergencypulloverconfig"))
        {
            msg.emergencypulloverconfig = from_json_ApolloplanningScenarioEmergencyPullOverConfig(obj["emergencypulloverconfig"]);
        }
        if(obj.contains("emergencystopconfig"))
        {
            msg.emergencystopconfig = from_json_ApolloplanningScenarioEmergencyStopConfig(obj["emergencystopconfig"]);
        }
        if(obj.contains("learningmodelsampleconfig"))
        {
            msg.learningmodelsampleconfig = (obj["learningmodelsampleconfig"].is_string()?atoi(obj["learningmodelsampleconfig"].get<std::string>().c_str()):obj["learningmodelsampleconfig"].get<int>());
        }
        if(obj.contains("narrowstreetuturnconfig"))
        {
            msg.narrowstreetuturnconfig = (obj["narrowstreetuturnconfig"].is_string()?atoi(obj["narrowstreetuturnconfig"].get<std::string>().c_str()):obj["narrowstreetuturnconfig"].get<int>());
        }
        if(obj.contains("parkandgoconfig"))
        {
            msg.parkandgoconfig = from_json_ApolloplanningScenarioParkAndGoConfig(obj["parkandgoconfig"]);
        }
        if(obj.contains("pulloverconfig"))
        {
            msg.pulloverconfig = from_json_ApolloplanningScenarioPullOverConfig(obj["pulloverconfig"]);
        }
        if(obj.contains("stopsignunprotectedconfig"))
        {
            msg.stopsignunprotectedconfig = from_json_ApolloplanningScenarioStopSignUnprotectedConfig(obj["stopsignunprotectedconfig"]);
        }
        if(obj.contains("trafficlightprotectedconfig"))
        {
            msg.trafficlightprotectedconfig = from_json_ApolloplanningScenarioTrafficLightProtectedConfig(obj["trafficlightprotectedconfig"]);
        }
        if(obj.contains("trafficlightunprotectedleftturnconfig"))
        {
            msg.trafficlightunprotectedleftturnconfig = from_json_ApolloplanningScenarioTrafficLightUnprotectedLeftTurnConfig(obj["trafficlightunprotectedleftturnconfig"]);
        }
        if(obj.contains("trafficlightunprotectedrightturnconfig"))
        {
            msg.trafficlightunprotectedrightturnconfig = from_json_ApolloplanningScenarioTrafficLightUnprotectedRightTurnConfig(obj["trafficlightunprotectedrightturnconfig"]);
        }
        if(obj.contains("valetparkingconfig"))
        {
            msg.valetparkingconfig = from_json_ApolloplanningScenarioValetParkingConfig(obj["valetparkingconfig"]);
        }
        if(obj.contains("yieldsignconfig"))
        {
            msg.yieldsignconfig = from_json_ApolloplanningScenarioYieldSignConfig(obj["yieldsignconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioConfigscenarioConfig from_json<ApolloplanningScenarioConfigscenarioConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioConfigscenarioConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioConfigscenarioConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioConfigscenarioConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioConfigscenarioConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioConfigscenarioConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
