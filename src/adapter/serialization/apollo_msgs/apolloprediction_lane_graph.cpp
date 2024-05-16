#include "adapter/serialization/apollo_msgs/apolloprediction_lane_graph.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneGraph &msg) {
        nlohmann::json obj;
        nlohmann::json arr_lanesequence;
        for (auto it = msg.lanesequence.begin(); it != msg.lanesequence.end(); ++it) {
            arr_lanesequence.push_back(to_json(*it));
        }
        obj["lanesequence"] = arr_lanesequence;
        return obj;
    }
    ApollopredictionLaneGraph from_json_ApollopredictionLaneGraph (nlohmann::json obj) {
        ApollopredictionLaneGraph msg;
        if(obj.contains("lanesequence"))
        {
            if(obj["lanesequence"].is_array())
            {
                for (auto& element : obj["lanesequence"])
                {
                    msg.lanesequence.push_back(from_json_ApollopredictionLaneSequence(element));
                }
            }
            else
            {
                msg.lanesequence.push_back(from_json_ApollopredictionLaneSequence(obj["lanesequence"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionLaneGraph from_json<ApollopredictionLaneGraph>(nlohmann::json obj){
        return from_json_ApollopredictionLaneGraph(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneGraph &dt)
    {
        dt=from_json_ApollopredictionLaneGraph(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneGraph & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneGraph & dt)
    {
        os << to_json(dt);
        return os;
    }
}
