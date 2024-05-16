#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionConf &msg) {
        nlohmann::json obj;
        obj["topicconf"] = to_json(msg.topicconf);
        nlohmann::json arr_obstacleconf;
        for (auto it = msg.obstacleconf.begin(); it != msg.obstacleconf.end(); ++it) {
            arr_obstacleconf.push_back(to_json(*it));
        }
        obj["obstacleconf"] = arr_obstacleconf;
        return obj;
    }
    ApollopredictionPredictionConf from_json_ApollopredictionPredictionConf (nlohmann::json obj) {
        ApollopredictionPredictionConf msg;
        if(obj.contains("topicconf"))
        {
            msg.topicconf = from_json_ApollopredictionTopicConf(obj["topicconf"]);
        }
        if(obj.contains("obstacleconf"))
        {
            if(obj["obstacleconf"].is_array())
            {
                for (auto& element : obj["obstacleconf"])
                {
                    msg.obstacleconf.push_back(from_json_ApollopredictionObstacleConf(element));
                }
            }
            else
            {
                msg.obstacleconf.push_back(from_json_ApollopredictionObstacleConf(obj["obstacleconf"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionPredictionConf from_json<ApollopredictionPredictionConf>(nlohmann::json obj){
        return from_json_ApollopredictionPredictionConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionConf &dt)
    {
        dt=from_json_ApollopredictionPredictionConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
