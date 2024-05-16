#include "adapter/serialization/apollo_msgs/apolloplanning_adc_trajectory.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningADCTrajectory &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["totalpathlength"] = (msg.totalpathlength);
        obj["totalpathtime"] = (msg.totalpathtime);
        nlohmann::json arr_trajectorypoint;
        for (auto it = msg.trajectorypoint.begin(); it != msg.trajectorypoint.end(); ++it) {
            arr_trajectorypoint.push_back(to_json(*it));
        }
        obj["trajectorypoint"] = arr_trajectorypoint;
        obj["estop"] = to_json(msg.estop);
        nlohmann::json arr_pathpoint;
        for (auto it = msg.pathpoint.begin(); it != msg.pathpoint.end(); ++it) {
            arr_pathpoint.push_back(to_json(*it));
        }
        obj["pathpoint"] = arr_pathpoint;
        obj["isreplan"] = (msg.isreplan);
        obj["replanreason"] = (msg.replanreason);
        obj["gear"] = (msg.gear);
        obj["decision"] = to_json(msg.decision);
        obj["latencystats"] = to_json(msg.latencystats);
        obj["routingheader"] = to_json(msg.routingheader);
        obj["debug"] = to_json(msg.debug);
        obj["rightofwaystatus"] = (msg.rightofwaystatus);
        nlohmann::json arr_laneid;
        for (auto it = msg.laneid.begin(); it != msg.laneid.end(); ++it) {
            arr_laneid.push_back(to_json(*it));
        }
        obj["laneid"] = arr_laneid;
        obj["engageadvice"] = to_json(msg.engageadvice);
        obj["criticalregion"] = (msg.criticalregion);
        obj["trajectorytype"] = (msg.trajectorytype);
        nlohmann::json arr_targetlaneid;
        for (auto it = msg.targetlaneid.begin(); it != msg.targetlaneid.end(); ++it) {
            arr_targetlaneid.push_back(to_json(*it));
        }
        obj["targetlaneid"] = arr_targetlaneid;
        obj["rssinfo"] = to_json(msg.rssinfo);
        return obj;
    }
    ApolloplanningADCTrajectory from_json_ApolloplanningADCTrajectory (nlohmann::json obj) {
        ApolloplanningADCTrajectory msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("totalpathlength"))
        {
            msg.totalpathlength = (obj["totalpathlength"].is_string()?atof(obj["totalpathlength"].get<std::string>().c_str()):obj["totalpathlength"].get<double>());
        }
        if(obj.contains("totalpathtime"))
        {
            msg.totalpathtime = (obj["totalpathtime"].is_string()?atof(obj["totalpathtime"].get<std::string>().c_str()):obj["totalpathtime"].get<double>());
        }
        if(obj.contains("trajectorypoint"))
        {
            if(obj["trajectorypoint"].is_array())
            {
                for (auto& element : obj["trajectorypoint"])
                {
                    msg.trajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(element));
                }
            }
            else
            {
                msg.trajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(obj["trajectorypoint"]));
            }
        }
        if(obj.contains("estop"))
        {
            msg.estop = from_json_ApolloplanningEStop(obj["estop"]);
        }
        if(obj.contains("pathpoint"))
        {
            if(obj["pathpoint"].is_array())
            {
                for (auto& element : obj["pathpoint"])
                {
                    msg.pathpoint.push_back(from_json_ApollocommonPathPoint(element));
                }
            }
            else
            {
                msg.pathpoint.push_back(from_json_ApollocommonPathPoint(obj["pathpoint"]));
            }
        }
        if(obj.contains("isreplan"))
        {
            msg.isreplan = (obj["isreplan"].is_string()?(bool)atoi(obj["isreplan"].get<std::string>().c_str()):obj["isreplan"].get<bool>());
        }
        if(obj.contains("replanreason"))
        {
            msg.replanreason = (obj["replanreason"].is_string()?(obj["replanreason"].get<std::string>().c_str()):obj["replanreason"].get<std::string>());
        }
        if(obj.contains("gear"))
        {
            msg.gear = (obj["gear"].is_string()?atoi(obj["gear"].get<std::string>().c_str()):obj["gear"].get<int>());
        }
        if(obj.contains("decision"))
        {
            msg.decision = from_json_ApolloplanningDecisionResult(obj["decision"]);
        }
        if(obj.contains("latencystats"))
        {
            msg.latencystats = from_json_ApolloplanningLatencyStats(obj["latencystats"]);
        }
        if(obj.contains("routingheader"))
        {
            msg.routingheader = from_json_ApollocommonHeader(obj["routingheader"]);
        }
        if(obj.contains("debug"))
        {
            msg.debug = from_json_ApolloplanningInternalDebug(obj["debug"]);
        }
        if(obj.contains("rightofwaystatus"))
        {
            msg.rightofwaystatus = (obj["rightofwaystatus"].is_string()?atoi(obj["rightofwaystatus"].get<std::string>().c_str()):obj["rightofwaystatus"].get<int>());
        }
        if(obj.contains("laneid"))
        {
            if(obj["laneid"].is_array())
            {
                for (auto& element : obj["laneid"])
                {
                    msg.laneid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.laneid.push_back(from_json_ApollohdmapId(obj["laneid"]));
            }
        }
        if(obj.contains("engageadvice"))
        {
            msg.engageadvice = from_json_ApollocommonEngageAdvice(obj["engageadvice"]);
        }
        if(obj.contains("criticalregion"))
        {
            msg.criticalregion = (obj["criticalregion"].is_string()?atoi(obj["criticalregion"].get<std::string>().c_str()):obj["criticalregion"].get<int>());
        }
        if(obj.contains("trajectorytype"))
        {
            msg.trajectorytype = (obj["trajectorytype"].is_string()?atoi(obj["trajectorytype"].get<std::string>().c_str()):obj["trajectorytype"].get<int>());
        }
        if(obj.contains("targetlaneid"))
        {
            if(obj["targetlaneid"].is_array())
            {
                for (auto& element : obj["targetlaneid"])
                {
                    msg.targetlaneid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.targetlaneid.push_back(from_json_ApollohdmapId(obj["targetlaneid"]));
            }
        }
        if(obj.contains("rssinfo"))
        {
            msg.rssinfo = from_json_ApolloplanningRSSInfo(obj["rssinfo"]);
        }
        return msg;
    }
    template <>
    ApolloplanningADCTrajectory from_json<ApolloplanningADCTrajectory>(nlohmann::json obj){
        return from_json_ApolloplanningADCTrajectory(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningADCTrajectory &dt)
    {
        dt=from_json_ApolloplanningADCTrajectory(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningADCTrajectory & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningADCTrajectory & dt)
    {
        os << to_json(dt);
        return os;
    }
}
