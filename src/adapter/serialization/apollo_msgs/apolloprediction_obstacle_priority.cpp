#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_priority.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionObstaclePriority &msg) {
        nlohmann::json obj;
        obj["priority"] = (msg.priority);
        return obj;
    }
    ApollopredictionObstaclePriority from_json_ApollopredictionObstaclePriority (nlohmann::json obj) {
        ApollopredictionObstaclePriority msg;
        if(obj.contains("priority"))
        {
            msg.priority = (obj["priority"].is_string()?atoi(obj["priority"].get<std::string>().c_str()):obj["priority"].get<int>());
        }
        return msg;
    }
    template <>
    ApollopredictionObstaclePriority from_json<ApollopredictionObstaclePriority>(nlohmann::json obj){
        return from_json_ApollopredictionObstaclePriority(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionObstaclePriority &dt)
    {
        dt=from_json_ApollopredictionObstaclePriority(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionObstaclePriority & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionObstaclePriority & dt)
    {
        os << to_json(dt);
        return os;
    }
}
