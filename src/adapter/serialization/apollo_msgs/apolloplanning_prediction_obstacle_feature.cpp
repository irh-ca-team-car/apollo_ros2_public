#include "adapter/serialization/apollo_msgs/apolloplanning_prediction_obstacle_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPredictionObstacleFeature &msg) {
        nlohmann::json obj;
        obj["timestampsec"] = (msg.timestampsec);
        obj["predictedperiod"] = (msg.predictedperiod);
        obj["intent"] = to_json(msg.intent);
        obj["priority"] = to_json(msg.priority);
        obj["isstatic"] = (msg.isstatic);
        nlohmann::json arr_trajectory;
        for (auto it = msg.trajectory.begin(); it != msg.trajectory.end(); ++it) {
            arr_trajectory.push_back(to_json(*it));
        }
        obj["trajectory"] = arr_trajectory;
        return obj;
    }
    ApolloplanningPredictionObstacleFeature from_json_ApolloplanningPredictionObstacleFeature (nlohmann::json obj) {
        ApolloplanningPredictionObstacleFeature msg;
        if(obj.contains("timestampsec"))
        {
            msg.timestampsec = (obj["timestampsec"].is_string()?atof(obj["timestampsec"].get<std::string>().c_str()):obj["timestampsec"].get<double>());
        }
        if(obj.contains("predictedperiod"))
        {
            msg.predictedperiod = (obj["predictedperiod"].is_string()?atof(obj["predictedperiod"].get<std::string>().c_str()):obj["predictedperiod"].get<double>());
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
        if(obj.contains("trajectory"))
        {
            if(obj["trajectory"].is_array())
            {
                for (auto& element : obj["trajectory"])
                {
                    msg.trajectory.push_back(from_json_ApolloplanningPredictionTrajectoryFeature(element));
                }
            }
            else
            {
                msg.trajectory.push_back(from_json_ApolloplanningPredictionTrajectoryFeature(obj["trajectory"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningPredictionObstacleFeature from_json<ApolloplanningPredictionObstacleFeature>(nlohmann::json obj){
        return from_json_ApolloplanningPredictionObstacleFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPredictionObstacleFeature &dt)
    {
        dt=from_json_ApolloplanningPredictionObstacleFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPredictionObstacleFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPredictionObstacleFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
