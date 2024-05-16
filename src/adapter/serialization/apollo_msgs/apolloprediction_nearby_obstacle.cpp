#include "adapter/serialization/apollo_msgs/apolloprediction_nearby_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionNearbyObstacle &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["s"] = (msg.s);
        obj["l"] = (msg.l);
        return obj;
    }
    ApollopredictionNearbyObstacle from_json_ApollopredictionNearbyObstacle (nlohmann::json obj) {
        ApollopredictionNearbyObstacle msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("l"))
        {
            msg.l = (obj["l"].is_string()?atof(obj["l"].get<std::string>().c_str()):obj["l"].get<double>());
        }
        return msg;
    }
    template <>
    ApollopredictionNearbyObstacle from_json<ApollopredictionNearbyObstacle>(nlohmann::json obj){
        return from_json_ApollopredictionNearbyObstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionNearbyObstacle &dt)
    {
        dt=from_json_ApollopredictionNearbyObstacle(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionNearbyObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionNearbyObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
}
