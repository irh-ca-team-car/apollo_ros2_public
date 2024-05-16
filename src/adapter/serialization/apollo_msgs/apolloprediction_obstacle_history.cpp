#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_history.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionObstacleHistory &msg) {
        nlohmann::json obj;
        nlohmann::json arr_feature;
        for (auto it = msg.feature.begin(); it != msg.feature.end(); ++it) {
            arr_feature.push_back(to_json(*it));
        }
        obj["feature"] = arr_feature;
        obj["istrainable"] = (msg.istrainable);
        return obj;
    }
    ApollopredictionObstacleHistory from_json_ApollopredictionObstacleHistory (nlohmann::json obj) {
        ApollopredictionObstacleHistory msg;
        if(obj.contains("feature"))
        {
            if(obj["feature"].is_array())
            {
                for (auto& element : obj["feature"])
                {
                    msg.feature.push_back(from_json_ApollopredictionFeature(element));
                }
            }
            else
            {
                msg.feature.push_back(from_json_ApollopredictionFeature(obj["feature"]));
            }
        }
        if(obj.contains("istrainable"))
        {
            msg.istrainable = (obj["istrainable"].is_string()?(bool)atoi(obj["istrainable"].get<std::string>().c_str()):obj["istrainable"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollopredictionObstacleHistory from_json<ApollopredictionObstacleHistory>(nlohmann::json obj){
        return from_json_ApollopredictionObstacleHistory(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionObstacleHistory &dt)
    {
        dt=from_json_ApollopredictionObstacleHistory(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionObstacleHistory & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionObstacleHistory & dt)
    {
        os << to_json(dt);
        return os;
    }
}
