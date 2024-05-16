#include "adapter/serialization/apollo_msgs/apolloplanning_iterative_anchoring_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningIterativeAnchoringConfig &msg) {
        nlohmann::json obj;
        obj["interpolateddeltas"] = (msg.interpolateddeltas);
        obj["reanchoringtrailsnum"] = (msg.reanchoringtrailsnum);
        obj["reanchoringposstddev"] = (msg.reanchoringposstddev);
        obj["reanchoringlengthstddev"] = (msg.reanchoringlengthstddev);
        obj["estimatebound"] = (msg.estimatebound);
        obj["defaultbound"] = (msg.defaultbound);
        obj["vehicleshortestdimension"] = (msg.vehicleshortestdimension);
        obj["femposdeviationsmootherconfig"] = to_json(msg.femposdeviationsmootherconfig);
        obj["collisiondecreaseratio"] = (msg.collisiondecreaseratio);
        obj["maxforwardv"] = (msg.maxforwardv);
        obj["maxreversev"] = (msg.maxreversev);
        obj["maxforwardacc"] = (msg.maxforwardacc);
        obj["maxreverseacc"] = (msg.maxreverseacc);
        obj["maxaccjerk"] = (msg.maxaccjerk);
        obj["deltat"] = (msg.deltat);
        obj["scurveconfig"] = to_json(msg.scurveconfig);
        return obj;
    }
    ApolloplanningIterativeAnchoringConfig from_json_ApolloplanningIterativeAnchoringConfig (nlohmann::json obj) {
        ApolloplanningIterativeAnchoringConfig msg;
        if(obj.contains("interpolateddeltas"))
        {
            msg.interpolateddeltas = (obj["interpolateddeltas"].is_string()?atof(obj["interpolateddeltas"].get<std::string>().c_str()):obj["interpolateddeltas"].get<double>());
        }
        if(obj.contains("reanchoringtrailsnum"))
        {
            msg.reanchoringtrailsnum = (obj["reanchoringtrailsnum"].is_string()?atoi(obj["reanchoringtrailsnum"].get<std::string>().c_str()):obj["reanchoringtrailsnum"].get<int>());
        }
        if(obj.contains("reanchoringposstddev"))
        {
            msg.reanchoringposstddev = (obj["reanchoringposstddev"].is_string()?atof(obj["reanchoringposstddev"].get<std::string>().c_str()):obj["reanchoringposstddev"].get<double>());
        }
        if(obj.contains("reanchoringlengthstddev"))
        {
            msg.reanchoringlengthstddev = (obj["reanchoringlengthstddev"].is_string()?atof(obj["reanchoringlengthstddev"].get<std::string>().c_str()):obj["reanchoringlengthstddev"].get<double>());
        }
        if(obj.contains("estimatebound"))
        {
            msg.estimatebound = (obj["estimatebound"].is_string()?(bool)atoi(obj["estimatebound"].get<std::string>().c_str()):obj["estimatebound"].get<bool>());
        }
        if(obj.contains("defaultbound"))
        {
            msg.defaultbound = (obj["defaultbound"].is_string()?atof(obj["defaultbound"].get<std::string>().c_str()):obj["defaultbound"].get<double>());
        }
        if(obj.contains("vehicleshortestdimension"))
        {
            msg.vehicleshortestdimension = (obj["vehicleshortestdimension"].is_string()?atof(obj["vehicleshortestdimension"].get<std::string>().c_str()):obj["vehicleshortestdimension"].get<double>());
        }
        if(obj.contains("femposdeviationsmootherconfig"))
        {
            msg.femposdeviationsmootherconfig = from_json_ApolloplanningFemPosDeviationSmootherConfig(obj["femposdeviationsmootherconfig"]);
        }
        if(obj.contains("collisiondecreaseratio"))
        {
            msg.collisiondecreaseratio = (obj["collisiondecreaseratio"].is_string()?atof(obj["collisiondecreaseratio"].get<std::string>().c_str()):obj["collisiondecreaseratio"].get<double>());
        }
        if(obj.contains("maxforwardv"))
        {
            msg.maxforwardv = (obj["maxforwardv"].is_string()?atof(obj["maxforwardv"].get<std::string>().c_str()):obj["maxforwardv"].get<double>());
        }
        if(obj.contains("maxreversev"))
        {
            msg.maxreversev = (obj["maxreversev"].is_string()?atof(obj["maxreversev"].get<std::string>().c_str()):obj["maxreversev"].get<double>());
        }
        if(obj.contains("maxforwardacc"))
        {
            msg.maxforwardacc = (obj["maxforwardacc"].is_string()?atof(obj["maxforwardacc"].get<std::string>().c_str()):obj["maxforwardacc"].get<double>());
        }
        if(obj.contains("maxreverseacc"))
        {
            msg.maxreverseacc = (obj["maxreverseacc"].is_string()?atof(obj["maxreverseacc"].get<std::string>().c_str()):obj["maxreverseacc"].get<double>());
        }
        if(obj.contains("maxaccjerk"))
        {
            msg.maxaccjerk = (obj["maxaccjerk"].is_string()?atof(obj["maxaccjerk"].get<std::string>().c_str()):obj["maxaccjerk"].get<double>());
        }
        if(obj.contains("deltat"))
        {
            msg.deltat = (obj["deltat"].is_string()?atof(obj["deltat"].get<std::string>().c_str()):obj["deltat"].get<double>());
        }
        if(obj.contains("scurveconfig"))
        {
            msg.scurveconfig = from_json_ApolloplanningPiecewiseJerkSpeedOptimizerConfig(obj["scurveconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningIterativeAnchoringConfig from_json<ApolloplanningIterativeAnchoringConfig>(nlohmann::json obj){
        return from_json_ApolloplanningIterativeAnchoringConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningIterativeAnchoringConfig &dt)
    {
        dt=from_json_ApolloplanningIterativeAnchoringConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningIterativeAnchoringConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningIterativeAnchoringConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
