#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_intent.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionObstacleIntent &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        return obj;
    }
    ApollopredictionObstacleIntent from_json_ApollopredictionObstacleIntent (nlohmann::json obj) {
        ApollopredictionObstacleIntent msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApollopredictionObstacleIntent from_json<ApollopredictionObstacleIntent>(nlohmann::json obj){
        return from_json_ApollopredictionObstacleIntent(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionObstacleIntent &dt)
    {
        dt=from_json_ApollopredictionObstacleIntent(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionObstacleIntent & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionObstacleIntent & dt)
    {
        os << to_json(dt);
        return os;
    }
}
