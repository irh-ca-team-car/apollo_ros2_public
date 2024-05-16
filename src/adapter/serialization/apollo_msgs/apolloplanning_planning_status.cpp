#include "adapter/serialization/apollo_msgs/apolloplanning_planning_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningStatus &msg) {
        nlohmann::json obj;
        obj["bareintersection"] = to_json(msg.bareintersection);
        obj["changelane"] = to_json(msg.changelane);
        obj["creepdecider"] = to_json(msg.creepdecider);
        obj["crosswalk"] = to_json(msg.crosswalk);
        obj["destination"] = to_json(msg.destination);
        obj["emergencystop"] = to_json(msg.emergencystop);
        obj["openspace"] = to_json(msg.openspace);
        obj["parkandgo"] = to_json(msg.parkandgo);
        obj["pathdecider"] = to_json(msg.pathdecider);
        obj["pullover"] = to_json(msg.pullover);
        obj["rerouting"] = to_json(msg.rerouting);
        obj["scenario"] = to_json(msg.scenario);
        obj["speeddecider"] = to_json(msg.speeddecider);
        obj["stopsign"] = to_json(msg.stopsign);
        obj["trafficlight"] = to_json(msg.trafficlight);
        obj["yieldsign"] = to_json(msg.yieldsign);
        return obj;
    }
    ApolloplanningPlanningStatus from_json_ApolloplanningPlanningStatus (nlohmann::json obj) {
        ApolloplanningPlanningStatus msg;
        if(obj.contains("bareintersection"))
        {
            msg.bareintersection = from_json_ApolloplanningBareIntersectionStatus(obj["bareintersection"]);
        }
        if(obj.contains("changelane"))
        {
            msg.changelane = from_json_ApolloplanningChangeLaneStatus(obj["changelane"]);
        }
        if(obj.contains("creepdecider"))
        {
            msg.creepdecider = from_json_ApolloplanningCreepDeciderStatus(obj["creepdecider"]);
        }
        if(obj.contains("crosswalk"))
        {
            msg.crosswalk = from_json_ApolloplanningCrosswalkStatus(obj["crosswalk"]);
        }
        if(obj.contains("destination"))
        {
            msg.destination = from_json_ApolloplanningDestinationStatus(obj["destination"]);
        }
        if(obj.contains("emergencystop"))
        {
            msg.emergencystop = from_json_ApolloplanningEmergencyStopStatus(obj["emergencystop"]);
        }
        if(obj.contains("openspace"))
        {
            msg.openspace = from_json_ApolloplanningOpenSpaceStatus(obj["openspace"]);
        }
        if(obj.contains("parkandgo"))
        {
            msg.parkandgo = from_json_ApolloplanningParkAndGoStatus(obj["parkandgo"]);
        }
        if(obj.contains("pathdecider"))
        {
            msg.pathdecider = from_json_ApolloplanningPathDeciderStatus(obj["pathdecider"]);
        }
        if(obj.contains("pullover"))
        {
            msg.pullover = from_json_ApolloplanningPullOverStatus(obj["pullover"]);
        }
        if(obj.contains("rerouting"))
        {
            msg.rerouting = from_json_ApolloplanningReroutingStatus(obj["rerouting"]);
        }
        if(obj.contains("scenario"))
        {
            msg.scenario = from_json_ApolloplanningScenarioStatus(obj["scenario"]);
        }
        if(obj.contains("speeddecider"))
        {
            msg.speeddecider = from_json_ApolloplanningSpeedDeciderStatus(obj["speeddecider"]);
        }
        if(obj.contains("stopsign"))
        {
            msg.stopsign = from_json_ApolloplanningStopSignStatus(obj["stopsign"]);
        }
        if(obj.contains("trafficlight"))
        {
            msg.trafficlight = from_json_ApolloplanningTrafficLightStatus(obj["trafficlight"]);
        }
        if(obj.contains("yieldsign"))
        {
            msg.yieldsign = from_json_ApolloplanningYieldSignStatus(obj["yieldsign"]);
        }
        return msg;
    }
    template <>
    ApolloplanningPlanningStatus from_json<ApolloplanningPlanningStatus>(nlohmann::json obj){
        return from_json_ApolloplanningPlanningStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningStatus &dt)
    {
        dt=from_json_ApolloplanningPlanningStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
