#include "adapter/serialization/apollo_msgs/apolloplanning_planner_open_space_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlannerOpenSpaceConfig &msg) {
        nlohmann::json obj;
        obj["roiconfig"] = to_json(msg.roiconfig);
        obj["warmstartconfig"] = to_json(msg.warmstartconfig);
        obj["dualvariablewarmstartconfig"] = to_json(msg.dualvariablewarmstartconfig);
        obj["distanceapproachconfig"] = to_json(msg.distanceapproachconfig);
        obj["iterativeanchoringsmootherconfig"] = to_json(msg.iterativeanchoringsmootherconfig);
        obj["trajectorypartitionconfig"] = to_json(msg.trajectorypartitionconfig);
        obj["deltat"] = (msg.deltat);
        obj["isneardestinationthreshold"] = (msg.isneardestinationthreshold);
        obj["enablecheckparalleltrajectory"] = (msg.enablecheckparalleltrajectory);
        obj["enablelinearinterpolation"] = (msg.enablelinearinterpolation);
        obj["isneardestinationthetathreshold"] = (msg.isneardestinationthetathreshold);
        return obj;
    }
    ApolloplanningPlannerOpenSpaceConfig from_json_ApolloplanningPlannerOpenSpaceConfig (nlohmann::json obj) {
        ApolloplanningPlannerOpenSpaceConfig msg;
        if(obj.contains("roiconfig"))
        {
            msg.roiconfig = from_json_ApolloplanningROIConfig(obj["roiconfig"]);
        }
        if(obj.contains("warmstartconfig"))
        {
            msg.warmstartconfig = from_json_ApolloplanningWarmStartConfig(obj["warmstartconfig"]);
        }
        if(obj.contains("dualvariablewarmstartconfig"))
        {
            msg.dualvariablewarmstartconfig = from_json_ApolloplanningDualVariableWarmStartConfig(obj["dualvariablewarmstartconfig"]);
        }
        if(obj.contains("distanceapproachconfig"))
        {
            msg.distanceapproachconfig = from_json_ApolloplanningDistanceApproachConfig(obj["distanceapproachconfig"]);
        }
        if(obj.contains("iterativeanchoringsmootherconfig"))
        {
            msg.iterativeanchoringsmootherconfig = from_json_ApolloplanningIterativeAnchoringConfig(obj["iterativeanchoringsmootherconfig"]);
        }
        if(obj.contains("trajectorypartitionconfig"))
        {
            msg.trajectorypartitionconfig = from_json_ApolloplanningTrajectoryPartitionConfig(obj["trajectorypartitionconfig"]);
        }
        if(obj.contains("deltat"))
        {
            msg.deltat = (obj["deltat"].is_string()?(float)atof(obj["deltat"].get<std::string>().c_str()):obj["deltat"].get<float>());
        }
        if(obj.contains("isneardestinationthreshold"))
        {
            msg.isneardestinationthreshold = (obj["isneardestinationthreshold"].is_string()?atof(obj["isneardestinationthreshold"].get<std::string>().c_str()):obj["isneardestinationthreshold"].get<double>());
        }
        if(obj.contains("enablecheckparalleltrajectory"))
        {
            msg.enablecheckparalleltrajectory = (obj["enablecheckparalleltrajectory"].is_string()?(bool)atoi(obj["enablecheckparalleltrajectory"].get<std::string>().c_str()):obj["enablecheckparalleltrajectory"].get<bool>());
        }
        if(obj.contains("enablelinearinterpolation"))
        {
            msg.enablelinearinterpolation = (obj["enablelinearinterpolation"].is_string()?(bool)atoi(obj["enablelinearinterpolation"].get<std::string>().c_str()):obj["enablelinearinterpolation"].get<bool>());
        }
        if(obj.contains("isneardestinationthetathreshold"))
        {
            msg.isneardestinationthetathreshold = (obj["isneardestinationthetathreshold"].is_string()?atof(obj["isneardestinationthetathreshold"].get<std::string>().c_str()):obj["isneardestinationthetathreshold"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningPlannerOpenSpaceConfig from_json<ApolloplanningPlannerOpenSpaceConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPlannerOpenSpaceConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlannerOpenSpaceConfig &dt)
    {
        dt=from_json_ApolloplanningPlannerOpenSpaceConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlannerOpenSpaceConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlannerOpenSpaceConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
