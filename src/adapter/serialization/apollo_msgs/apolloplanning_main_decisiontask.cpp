#include "adapter/serialization/apollo_msgs/apolloplanning_main_decisiontask.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainDecisiontask &msg) {
        nlohmann::json obj;
        obj["cruise"] = to_json(msg.cruise);
        obj["stop"] = to_json(msg.stop);
        obj["estop"] = to_json(msg.estop);
        obj["changelane"] = to_json(msg.changelane);
        obj["missioncomplete"] = to_json(msg.missioncomplete);
        obj["notready"] = to_json(msg.notready);
        obj["parking"] = to_json(msg.parking);
        return obj;
    }
    ApolloplanningMainDecisiontask from_json_ApolloplanningMainDecisiontask (nlohmann::json obj) {
        ApolloplanningMainDecisiontask msg;
        if(obj.contains("cruise"))
        {
            msg.cruise = from_json_ApolloplanningMainCruise(obj["cruise"]);
        }
        if(obj.contains("stop"))
        {
            msg.stop = from_json_ApolloplanningMainStop(obj["stop"]);
        }
        if(obj.contains("estop"))
        {
            msg.estop = from_json_ApolloplanningMainEmergencyStop(obj["estop"]);
        }
        if(obj.contains("changelane"))
        {
            msg.changelane = from_json_ApolloplanningMainChangeLane(obj["changelane"]);
        }
        if(obj.contains("missioncomplete"))
        {
            msg.missioncomplete = from_json_ApolloplanningMainMissionComplete(obj["missioncomplete"]);
        }
        if(obj.contains("notready"))
        {
            msg.notready = from_json_ApolloplanningMainNotReady(obj["notready"]);
        }
        if(obj.contains("parking"))
        {
            msg.parking = from_json_ApolloplanningMainParking(obj["parking"]);
        }
        return msg;
    }
    template <>
    ApolloplanningMainDecisiontask from_json<ApolloplanningMainDecisiontask>(nlohmann::json obj){
        return from_json_ApolloplanningMainDecisiontask(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainDecisiontask &dt)
    {
        dt=from_json_ApolloplanningMainDecisiontask(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainDecisiontask & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainDecisiontask & dt)
    {
        os << to_json(dt);
        return os;
    }
}
