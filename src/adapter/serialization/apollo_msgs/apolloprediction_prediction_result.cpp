#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_result.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionResult &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["timestamp"] = (msg.timestamp);
        nlohmann::json arr_trajectory;
        for (auto it = msg.trajectory.begin(); it != msg.trajectory.end(); ++it) {
            arr_trajectory.push_back(to_json(*it));
        }
        obj["trajectory"] = arr_trajectory;
        obj["obstacleconf"] = to_json(msg.obstacleconf);
        obj["scenario"] = to_json(msg.scenario);
        return obj;
    }
    ApollopredictionPredictionResult from_json_ApollopredictionPredictionResult (nlohmann::json obj) {
        ApollopredictionPredictionResult msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
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
        if(obj.contains("obstacleconf"))
        {
            msg.obstacleconf = from_json_ApollopredictionObstacleConf(obj["obstacleconf"]);
        }
        if(obj.contains("scenario"))
        {
            msg.scenario = from_json_ApollopredictionScenario(obj["scenario"]);
        }
        return msg;
    }
    template <>
    ApollopredictionPredictionResult from_json<ApollopredictionPredictionResult>(nlohmann::json obj){
        return from_json_ApollopredictionPredictionResult(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionResult &dt)
    {
        dt=from_json_ApollopredictionPredictionResult(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionResult & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionResult & dt)
    {
        os << to_json(dt);
        return os;
    }
}
