#include "adapter/serialization/apollo_msgs/apolloplanning_task_configtask_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTaskConfigtaskConfig &msg) {
        nlohmann::json obj;
        obj["creepdeciderconfig"] = to_json(msg.creepdeciderconfig);
        obj["lanechangedeciderconfig"] = to_json(msg.lanechangedeciderconfig);
        obj["openspacefallbackdeciderconfig"] = to_json(msg.openspacefallbackdeciderconfig);
        obj["openspaceprestopdeciderconfig"] = to_json(msg.openspaceprestopdeciderconfig);
        obj["openspaceroideciderconfig"] = to_json(msg.openspaceroideciderconfig);
        obj["pathassessmentdeciderconfig"] = (msg.pathassessmentdeciderconfig);
        obj["pathboundsdeciderconfig"] = to_json(msg.pathboundsdeciderconfig);
        obj["pathdeciderconfig"] = to_json(msg.pathdeciderconfig);
        obj["pathlaneborrowdeciderconfig"] = to_json(msg.pathlaneborrowdeciderconfig);
        obj["pathreferencedeciderconfig"] = to_json(msg.pathreferencedeciderconfig);
        obj["pathreusedeciderconfig"] = to_json(msg.pathreusedeciderconfig);
        obj["rulebasedstopdeciderconfig"] = to_json(msg.rulebasedstopdeciderconfig);
        obj["speedboundsdeciderconfig"] = to_json(msg.speedboundsdeciderconfig);
        obj["stboundsdeciderconfig"] = to_json(msg.stboundsdeciderconfig);
        obj["openspacetrajectorypartitionconfig"] = to_json(msg.openspacetrajectorypartitionconfig);
        obj["openspacetrajectoryproviderconfig"] = to_json(msg.openspacetrajectoryproviderconfig);
        obj["piecewisejerknonlinearspeedoptimizerconfig"] = to_json(msg.piecewisejerknonlinearspeedoptimizerconfig);
        obj["piecewisejerkpathoptimizerconfig"] = to_json(msg.piecewisejerkpathoptimizerconfig);
        obj["piecewisejerkspeedoptimizerconfig"] = to_json(msg.piecewisejerkspeedoptimizerconfig);
        obj["speedheuristicoptimizerconfig"] = to_json(msg.speedheuristicoptimizerconfig);
        obj["learningmodelinferencetaskconfig"] = to_json(msg.learningmodelinferencetaskconfig);
        obj["learningmodelinferencetrajectorytaskconfig"] = to_json(msg.learningmodelinferencetrajectorytaskconfig);
        return obj;
    }
    ApolloplanningTaskConfigtaskConfig from_json_ApolloplanningTaskConfigtaskConfig (nlohmann::json obj) {
        ApolloplanningTaskConfigtaskConfig msg;
        if(obj.contains("creepdeciderconfig"))
        {
            msg.creepdeciderconfig = from_json_ApolloplanningCreepDeciderConfig(obj["creepdeciderconfig"]);
        }
        if(obj.contains("lanechangedeciderconfig"))
        {
            msg.lanechangedeciderconfig = from_json_ApolloplanningLaneChangeDeciderConfig(obj["lanechangedeciderconfig"]);
        }
        if(obj.contains("openspacefallbackdeciderconfig"))
        {
            msg.openspacefallbackdeciderconfig = from_json_ApolloplanningOpenSpaceFallBackDeciderConfig(obj["openspacefallbackdeciderconfig"]);
        }
        if(obj.contains("openspaceprestopdeciderconfig"))
        {
            msg.openspaceprestopdeciderconfig = from_json_ApolloplanningOpenSpacePreStopDeciderConfig(obj["openspaceprestopdeciderconfig"]);
        }
        if(obj.contains("openspaceroideciderconfig"))
        {
            msg.openspaceroideciderconfig = from_json_ApolloplanningOpenSpaceRoiDeciderConfig(obj["openspaceroideciderconfig"]);
        }
        if(obj.contains("pathassessmentdeciderconfig"))
        {
            msg.pathassessmentdeciderconfig = (obj["pathassessmentdeciderconfig"].is_string()?atoi(obj["pathassessmentdeciderconfig"].get<std::string>().c_str()):obj["pathassessmentdeciderconfig"].get<int>());
        }
        if(obj.contains("pathboundsdeciderconfig"))
        {
            msg.pathboundsdeciderconfig = from_json_ApolloplanningPathBoundsDeciderConfig(obj["pathboundsdeciderconfig"]);
        }
        if(obj.contains("pathdeciderconfig"))
        {
            msg.pathdeciderconfig = from_json_ApolloplanningPathDeciderConfig(obj["pathdeciderconfig"]);
        }
        if(obj.contains("pathlaneborrowdeciderconfig"))
        {
            msg.pathlaneborrowdeciderconfig = from_json_ApolloplanningPathLaneBorrowDeciderConfig(obj["pathlaneborrowdeciderconfig"]);
        }
        if(obj.contains("pathreferencedeciderconfig"))
        {
            msg.pathreferencedeciderconfig = from_json_ApolloplanningPathReferenceDeciderConfig(obj["pathreferencedeciderconfig"]);
        }
        if(obj.contains("pathreusedeciderconfig"))
        {
            msg.pathreusedeciderconfig = from_json_ApolloplanningPathReuseDeciderConfig(obj["pathreusedeciderconfig"]);
        }
        if(obj.contains("rulebasedstopdeciderconfig"))
        {
            msg.rulebasedstopdeciderconfig = from_json_ApolloplanningRuleBasedStopDeciderConfig(obj["rulebasedstopdeciderconfig"]);
        }
        if(obj.contains("speedboundsdeciderconfig"))
        {
            msg.speedboundsdeciderconfig = from_json_ApolloplanningSpeedBoundsDeciderConfig(obj["speedboundsdeciderconfig"]);
        }
        if(obj.contains("stboundsdeciderconfig"))
        {
            msg.stboundsdeciderconfig = from_json_ApolloplanningSTBoundsDeciderConfig(obj["stboundsdeciderconfig"]);
        }
        if(obj.contains("openspacetrajectorypartitionconfig"))
        {
            msg.openspacetrajectorypartitionconfig = from_json_ApolloplanningOpenSpaceTrajectoryPartitionConfig(obj["openspacetrajectorypartitionconfig"]);
        }
        if(obj.contains("openspacetrajectoryproviderconfig"))
        {
            msg.openspacetrajectoryproviderconfig = from_json_ApolloplanningOpenSpaceTrajectoryProviderConfig(obj["openspacetrajectoryproviderconfig"]);
        }
        if(obj.contains("piecewisejerknonlinearspeedoptimizerconfig"))
        {
            msg.piecewisejerknonlinearspeedoptimizerconfig = from_json_ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig(obj["piecewisejerknonlinearspeedoptimizerconfig"]);
        }
        if(obj.contains("piecewisejerkpathoptimizerconfig"))
        {
            msg.piecewisejerkpathoptimizerconfig = from_json_ApolloplanningPiecewiseJerkPathOptimizerConfig(obj["piecewisejerkpathoptimizerconfig"]);
        }
        if(obj.contains("piecewisejerkspeedoptimizerconfig"))
        {
            msg.piecewisejerkspeedoptimizerconfig = from_json_ApolloplanningPiecewiseJerkSpeedOptimizerConfig(obj["piecewisejerkspeedoptimizerconfig"]);
        }
        if(obj.contains("speedheuristicoptimizerconfig"))
        {
            msg.speedheuristicoptimizerconfig = from_json_ApolloplanningSpeedHeuristicOptimizerConfig(obj["speedheuristicoptimizerconfig"]);
        }
        if(obj.contains("learningmodelinferencetaskconfig"))
        {
            msg.learningmodelinferencetaskconfig = from_json_ApolloplanningLearningModelInferenceTaskConfig(obj["learningmodelinferencetaskconfig"]);
        }
        if(obj.contains("learningmodelinferencetrajectorytaskconfig"))
        {
            msg.learningmodelinferencetrajectorytaskconfig = from_json_ApolloplanningLearningModelInferenceTrajectoryTaskConfig(obj["learningmodelinferencetrajectorytaskconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningTaskConfigtaskConfig from_json<ApolloplanningTaskConfigtaskConfig>(nlohmann::json obj){
        return from_json_ApolloplanningTaskConfigtaskConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTaskConfigtaskConfig &dt)
    {
        dt=from_json_ApolloplanningTaskConfigtaskConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTaskConfigtaskConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTaskConfigtaskConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
