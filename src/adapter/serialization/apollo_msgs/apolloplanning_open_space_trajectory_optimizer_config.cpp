#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_trajectory_optimizer_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceTrajectoryOptimizerConfig &msg) {
        nlohmann::json obj;
        obj["hybridastarconfig"] = to_json(msg.hybridastarconfig);
        obj["dualvariablewarmstartconfig"] = to_json(msg.dualvariablewarmstartconfig);
        obj["distanceapproachtrajectorysmootherconfig"] = to_json(msg.distanceapproachtrajectorysmootherconfig);
        obj["deltat"] = (msg.deltat);
        obj["isneardestinationthreshold"] = (msg.isneardestinationthreshold);
        obj["planneropenspaceconfig"] = to_json(msg.planneropenspaceconfig);
        return obj;
    }
    ApolloplanningOpenSpaceTrajectoryOptimizerConfig from_json_ApolloplanningOpenSpaceTrajectoryOptimizerConfig (nlohmann::json obj) {
        ApolloplanningOpenSpaceTrajectoryOptimizerConfig msg;
        if(obj.contains("hybridastarconfig"))
        {
            msg.hybridastarconfig = from_json_ApolloplanningHybridAStarConfig(obj["hybridastarconfig"]);
        }
        if(obj.contains("dualvariablewarmstartconfig"))
        {
            msg.dualvariablewarmstartconfig = from_json_ApolloplanningDualVariableConfig(obj["dualvariablewarmstartconfig"]);
        }
        if(obj.contains("distanceapproachtrajectorysmootherconfig"))
        {
            msg.distanceapproachtrajectorysmootherconfig = from_json_ApolloplanningDistanceApproachTrajectorySmootherConfig(obj["distanceapproachtrajectorysmootherconfig"]);
        }
        if(obj.contains("deltat"))
        {
            msg.deltat = (obj["deltat"].is_string()?(float)atof(obj["deltat"].get<std::string>().c_str()):obj["deltat"].get<float>());
        }
        if(obj.contains("isneardestinationthreshold"))
        {
            msg.isneardestinationthreshold = (obj["isneardestinationthreshold"].is_string()?atof(obj["isneardestinationthreshold"].get<std::string>().c_str()):obj["isneardestinationthreshold"].get<double>());
        }
        if(obj.contains("planneropenspaceconfig"))
        {
            msg.planneropenspaceconfig = from_json_ApolloplanningPlannerOpenSpaceConfig(obj["planneropenspaceconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningOpenSpaceTrajectoryOptimizerConfig from_json<ApolloplanningOpenSpaceTrajectoryOptimizerConfig>(nlohmann::json obj){
        return from_json_ApolloplanningOpenSpaceTrajectoryOptimizerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceTrajectoryOptimizerConfig &dt)
    {
        dt=from_json_ApolloplanningOpenSpaceTrajectoryOptimizerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceTrajectoryOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceTrajectoryOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
