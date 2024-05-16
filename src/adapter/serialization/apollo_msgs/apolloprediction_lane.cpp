#include "adapter/serialization/apollo_msgs/apolloprediction_lane.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLane &msg) {
        nlohmann::json obj;
        nlohmann::json arr_currentlanefeature;
        for (auto it = msg.currentlanefeature.begin(); it != msg.currentlanefeature.end(); ++it) {
            arr_currentlanefeature.push_back(to_json(*it));
        }
        obj["currentlanefeature"] = arr_currentlanefeature;
        obj["lanefeature"] = to_json(msg.lanefeature);
        nlohmann::json arr_nearbylanefeature;
        for (auto it = msg.nearbylanefeature.begin(); it != msg.nearbylanefeature.end(); ++it) {
            arr_nearbylanefeature.push_back(to_json(*it));
        }
        obj["nearbylanefeature"] = arr_nearbylanefeature;
        obj["lanegraph"] = to_json(msg.lanegraph);
        obj["lanegraphordered"] = to_json(msg.lanegraphordered);
        obj["labelupdatetimedelta"] = (msg.labelupdatetimedelta);
        return obj;
    }
    ApollopredictionLane from_json_ApollopredictionLane (nlohmann::json obj) {
        ApollopredictionLane msg;
        if(obj.contains("currentlanefeature"))
        {
            if(obj["currentlanefeature"].is_array())
            {
                for (auto& element : obj["currentlanefeature"])
                {
                    msg.currentlanefeature.push_back(from_json_ApollopredictionLaneFeature(element));
                }
            }
            else
            {
                msg.currentlanefeature.push_back(from_json_ApollopredictionLaneFeature(obj["currentlanefeature"]));
            }
        }
        if(obj.contains("lanefeature"))
        {
            msg.lanefeature = from_json_ApollopredictionLaneFeature(obj["lanefeature"]);
        }
        if(obj.contains("nearbylanefeature"))
        {
            if(obj["nearbylanefeature"].is_array())
            {
                for (auto& element : obj["nearbylanefeature"])
                {
                    msg.nearbylanefeature.push_back(from_json_ApollopredictionLaneFeature(element));
                }
            }
            else
            {
                msg.nearbylanefeature.push_back(from_json_ApollopredictionLaneFeature(obj["nearbylanefeature"]));
            }
        }
        if(obj.contains("lanegraph"))
        {
            msg.lanegraph = from_json_ApollopredictionLaneGraph(obj["lanegraph"]);
        }
        if(obj.contains("lanegraphordered"))
        {
            msg.lanegraphordered = from_json_ApollopredictionLaneGraph(obj["lanegraphordered"]);
        }
        if(obj.contains("labelupdatetimedelta"))
        {
            msg.labelupdatetimedelta = (obj["labelupdatetimedelta"].is_string()?atof(obj["labelupdatetimedelta"].get<std::string>().c_str()):obj["labelupdatetimedelta"].get<double>());
        }
        return msg;
    }
    template <>
    ApollopredictionLane from_json<ApollopredictionLane>(nlohmann::json obj){
        return from_json_ApollopredictionLane(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLane &dt)
    {
        dt=from_json_ApollopredictionLane(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLane & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLane & dt)
    {
        os << to_json(dt);
        return os;
    }
}
