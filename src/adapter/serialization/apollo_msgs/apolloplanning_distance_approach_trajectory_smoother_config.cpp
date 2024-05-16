#include "adapter/serialization/apollo_msgs/apolloplanning_distance_approach_trajectory_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDistanceApproachTrajectorySmootherConfig &msg) {
        nlohmann::json obj;
        obj["weightsteer"] = (msg.weightsteer);
        obj["weighta"] = (msg.weighta);
        obj["weightsteerrate"] = (msg.weightsteerrate);
        obj["weightarate"] = (msg.weightarate);
        obj["weightx"] = (msg.weightx);
        obj["weighty"] = (msg.weighty);
        obj["weightphi"] = (msg.weightphi);
        obj["weightv"] = (msg.weightv);
        obj["weightsteerstitching"] = (msg.weightsteerstitching);
        obj["weightastitching"] = (msg.weightastitching);
        obj["weightfirstordertime"] = (msg.weightfirstordertime);
        obj["weightsecondordertime"] = (msg.weightsecondordertime);
        obj["minsafetydistance"] = (msg.minsafetydistance);
        obj["maxspeedforward"] = (msg.maxspeedforward);
        obj["maxspeedreverse"] = (msg.maxspeedreverse);
        obj["maxaccelerationforward"] = (msg.maxaccelerationforward);
        obj["maxaccelerationreverse"] = (msg.maxaccelerationreverse);
        obj["mintimesamplescaling"] = (msg.mintimesamplescaling);
        obj["maxtimesamplescaling"] = (msg.maxtimesamplescaling);
        obj["usefixtime"] = (msg.usefixtime);
        obj["ipoptconfig"] = to_json(msg.ipoptconfig);
        obj["enableconstraintcheck"] = (msg.enableconstraintcheck);
        obj["enablehandderivative"] = (msg.enablehandderivative);
        obj["enablederivativecheck"] = (msg.enablederivativecheck);
        obj["enableinitialfinalcheck"] = (msg.enableinitialfinalcheck);
        return obj;
    }
    ApolloplanningDistanceApproachTrajectorySmootherConfig from_json_ApolloplanningDistanceApproachTrajectorySmootherConfig (nlohmann::json obj) {
        ApolloplanningDistanceApproachTrajectorySmootherConfig msg;
        if(obj.contains("weightsteer"))
        {
            msg.weightsteer = (obj["weightsteer"].is_string()?atof(obj["weightsteer"].get<std::string>().c_str()):obj["weightsteer"].get<double>());
        }
        if(obj.contains("weighta"))
        {
            msg.weighta = (obj["weighta"].is_string()?atof(obj["weighta"].get<std::string>().c_str()):obj["weighta"].get<double>());
        }
        if(obj.contains("weightsteerrate"))
        {
            msg.weightsteerrate = (obj["weightsteerrate"].is_string()?atof(obj["weightsteerrate"].get<std::string>().c_str()):obj["weightsteerrate"].get<double>());
        }
        if(obj.contains("weightarate"))
        {
            msg.weightarate = (obj["weightarate"].is_string()?atof(obj["weightarate"].get<std::string>().c_str()):obj["weightarate"].get<double>());
        }
        if(obj.contains("weightx"))
        {
            msg.weightx = (obj["weightx"].is_string()?atof(obj["weightx"].get<std::string>().c_str()):obj["weightx"].get<double>());
        }
        if(obj.contains("weighty"))
        {
            msg.weighty = (obj["weighty"].is_string()?atof(obj["weighty"].get<std::string>().c_str()):obj["weighty"].get<double>());
        }
        if(obj.contains("weightphi"))
        {
            msg.weightphi = (obj["weightphi"].is_string()?atof(obj["weightphi"].get<std::string>().c_str()):obj["weightphi"].get<double>());
        }
        if(obj.contains("weightv"))
        {
            msg.weightv = (obj["weightv"].is_string()?atof(obj["weightv"].get<std::string>().c_str()):obj["weightv"].get<double>());
        }
        if(obj.contains("weightsteerstitching"))
        {
            msg.weightsteerstitching = (obj["weightsteerstitching"].is_string()?atof(obj["weightsteerstitching"].get<std::string>().c_str()):obj["weightsteerstitching"].get<double>());
        }
        if(obj.contains("weightastitching"))
        {
            msg.weightastitching = (obj["weightastitching"].is_string()?atof(obj["weightastitching"].get<std::string>().c_str()):obj["weightastitching"].get<double>());
        }
        if(obj.contains("weightfirstordertime"))
        {
            msg.weightfirstordertime = (obj["weightfirstordertime"].is_string()?atof(obj["weightfirstordertime"].get<std::string>().c_str()):obj["weightfirstordertime"].get<double>());
        }
        if(obj.contains("weightsecondordertime"))
        {
            msg.weightsecondordertime = (obj["weightsecondordertime"].is_string()?atof(obj["weightsecondordertime"].get<std::string>().c_str()):obj["weightsecondordertime"].get<double>());
        }
        if(obj.contains("minsafetydistance"))
        {
            msg.minsafetydistance = (obj["minsafetydistance"].is_string()?atof(obj["minsafetydistance"].get<std::string>().c_str()):obj["minsafetydistance"].get<double>());
        }
        if(obj.contains("maxspeedforward"))
        {
            msg.maxspeedforward = (obj["maxspeedforward"].is_string()?atof(obj["maxspeedforward"].get<std::string>().c_str()):obj["maxspeedforward"].get<double>());
        }
        if(obj.contains("maxspeedreverse"))
        {
            msg.maxspeedreverse = (obj["maxspeedreverse"].is_string()?atof(obj["maxspeedreverse"].get<std::string>().c_str()):obj["maxspeedreverse"].get<double>());
        }
        if(obj.contains("maxaccelerationforward"))
        {
            msg.maxaccelerationforward = (obj["maxaccelerationforward"].is_string()?atof(obj["maxaccelerationforward"].get<std::string>().c_str()):obj["maxaccelerationforward"].get<double>());
        }
        if(obj.contains("maxaccelerationreverse"))
        {
            msg.maxaccelerationreverse = (obj["maxaccelerationreverse"].is_string()?atof(obj["maxaccelerationreverse"].get<std::string>().c_str()):obj["maxaccelerationreverse"].get<double>());
        }
        if(obj.contains("mintimesamplescaling"))
        {
            msg.mintimesamplescaling = (obj["mintimesamplescaling"].is_string()?atof(obj["mintimesamplescaling"].get<std::string>().c_str()):obj["mintimesamplescaling"].get<double>());
        }
        if(obj.contains("maxtimesamplescaling"))
        {
            msg.maxtimesamplescaling = (obj["maxtimesamplescaling"].is_string()?atof(obj["maxtimesamplescaling"].get<std::string>().c_str()):obj["maxtimesamplescaling"].get<double>());
        }
        if(obj.contains("usefixtime"))
        {
            msg.usefixtime = (obj["usefixtime"].is_string()?(bool)atoi(obj["usefixtime"].get<std::string>().c_str()):obj["usefixtime"].get<bool>());
        }
        if(obj.contains("ipoptconfig"))
        {
            msg.ipoptconfig = from_json_ApolloplanningIpoptSolverConfig(obj["ipoptconfig"]);
        }
        if(obj.contains("enableconstraintcheck"))
        {
            msg.enableconstraintcheck = (obj["enableconstraintcheck"].is_string()?(bool)atoi(obj["enableconstraintcheck"].get<std::string>().c_str()):obj["enableconstraintcheck"].get<bool>());
        }
        if(obj.contains("enablehandderivative"))
        {
            msg.enablehandderivative = (obj["enablehandderivative"].is_string()?(bool)atoi(obj["enablehandderivative"].get<std::string>().c_str()):obj["enablehandderivative"].get<bool>());
        }
        if(obj.contains("enablederivativecheck"))
        {
            msg.enablederivativecheck = (obj["enablederivativecheck"].is_string()?(bool)atoi(obj["enablederivativecheck"].get<std::string>().c_str()):obj["enablederivativecheck"].get<bool>());
        }
        if(obj.contains("enableinitialfinalcheck"))
        {
            msg.enableinitialfinalcheck = (obj["enableinitialfinalcheck"].is_string()?(bool)atoi(obj["enableinitialfinalcheck"].get<std::string>().c_str()):obj["enableinitialfinalcheck"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningDistanceApproachTrajectorySmootherConfig from_json<ApolloplanningDistanceApproachTrajectorySmootherConfig>(nlohmann::json obj){
        return from_json_ApolloplanningDistanceApproachTrajectorySmootherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDistanceApproachTrajectorySmootherConfig &dt)
    {
        dt=from_json_ApolloplanningDistanceApproachTrajectorySmootherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDistanceApproachTrajectorySmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDistanceApproachTrajectorySmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
