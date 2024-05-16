#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionObstacle &msg) {
        nlohmann::json obj;
        obj["perceptionobstacle"] = to_json(msg.perceptionobstacle);
        obj["timestamp"] = (msg.timestamp);
        obj["predictedperiod"] = (msg.predictedperiod);
        nlohmann::json arr_trajectory;
        for (auto it = msg.trajectory.begin(); it != msg.trajectory.end(); ++it) {
            arr_trajectory.push_back(to_json(*it));
        }
        obj["trajectory"] = arr_trajectory;
        obj["intent"] = to_json(msg.intent);
        obj["priority"] = to_json(msg.priority);
        obj["isstatic"] = (msg.isstatic);
        nlohmann::json arr_feature;
        for (auto it = msg.feature.begin(); it != msg.feature.end(); ++it) {
            arr_feature.push_back(to_json(*it));
        }
        obj["feature"] = arr_feature;
        return obj;
    }
    ApollopredictionPredictionObstacle from_json_ApollopredictionPredictionObstacle (nlohmann::json obj) {
        ApollopredictionPredictionObstacle msg;
        if(obj.contains("perceptionobstacle"))
        {
            msg.perceptionobstacle = from_json_ApolloperceptionPerceptionObstacle(obj["perceptionobstacle"]);
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("predictedperiod"))
        {
            msg.predictedperiod = (obj["predictedperiod"].is_string()?atof(obj["predictedperiod"].get<std::string>().c_str()):obj["predictedperiod"].get<double>());
        }
        if(obj.contains("trajectory"))
        {
            if(obj["trajectory"].is_array())
            {
                for (auto& element : obj["trajectory"])
                {
                    msg.trajectory.push_back(from_json_ApollopredictionTrajectory(element));
                }
            }
            else
            {
                msg.trajectory.push_back(from_json_ApollopredictionTrajectory(obj["trajectory"]));
            }
        }
        if(obj.contains("intent"))
        {
            msg.intent = from_json_ApollopredictionObstacleIntent(obj["intent"]);
        }
        if(obj.contains("priority"))
        {
            msg.priority = from_json_ApollopredictionObstaclePriority(obj["priority"]);
        }
        if(obj.contains("isstatic"))
        {
            msg.isstatic = (obj["isstatic"].is_string()?(bool)atoi(obj["isstatic"].get<std::string>().c_str()):obj["isstatic"].get<bool>());
        }
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
        return msg;
    }
    template <>
    ApollopredictionPredictionObstacle from_json<ApollopredictionPredictionObstacle>(nlohmann::json obj){
        return from_json_ApollopredictionPredictionObstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionObstacle &dt)
    {
        dt=from_json_ApollopredictionPredictionObstacle(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
}
