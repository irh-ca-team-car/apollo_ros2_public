#include "adapter/serialization/apollo_msgs/apolloprediction_frame_env.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionFrameEnv &msg) {
        nlohmann::json obj;
        obj["timestamp"] = (msg.timestamp);
        obj["egohistory"] = to_json(msg.egohistory);
        nlohmann::json arr_obstacleshistory;
        for (auto it = msg.obstacleshistory.begin(); it != msg.obstacleshistory.end(); ++it) {
            arr_obstacleshistory.push_back(to_json(*it));
        }
        obj["obstacleshistory"] = arr_obstacleshistory;
        return obj;
    }
    ApollopredictionFrameEnv from_json_ApollopredictionFrameEnv (nlohmann::json obj) {
        ApollopredictionFrameEnv msg;
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("egohistory"))
        {
            msg.egohistory = from_json_ApollopredictionObstacleHistory(obj["egohistory"]);
        }
        if(obj.contains("obstacleshistory"))
        {
            if(obj["obstacleshistory"].is_array())
            {
                for (auto& element : obj["obstacleshistory"])
                {
                    msg.obstacleshistory.push_back(from_json_ApollopredictionObstacleHistory(element));
                }
            }
            else
            {
                msg.obstacleshistory.push_back(from_json_ApollopredictionObstacleHistory(obj["obstacleshistory"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionFrameEnv from_json<ApollopredictionFrameEnv>(nlohmann::json obj){
        return from_json_ApollopredictionFrameEnv(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionFrameEnv &dt)
    {
        dt=from_json_ApollopredictionFrameEnv(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionFrameEnv & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionFrameEnv & dt)
    {
        os << to_json(dt);
        return os;
    }
}
