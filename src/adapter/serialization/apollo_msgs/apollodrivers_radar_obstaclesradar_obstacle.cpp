#include "adapter/serialization/apollo_msgs/apollodrivers_radar_obstaclesradar_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRadarObstaclesradarObstacle &msg) {
        nlohmann::json obj;
        obj["key"] = (msg.key);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollodriversRadarObstaclesradarObstacle from_json_ApollodriversRadarObstaclesradarObstacle (nlohmann::json obj) {
        ApollodriversRadarObstaclesradarObstacle msg;
        if(obj.contains("key"))
        {
            msg.key = (obj["key"].is_string()?atoi(obj["key"].get<std::string>().c_str()):obj["key"].get<int>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_ApollodriversRadarObstacle(obj["data"]);
        }
        return msg;
    }
    template <>
    ApollodriversRadarObstaclesradarObstacle from_json<ApollodriversRadarObstaclesradarObstacle>(nlohmann::json obj){
        return from_json_ApollodriversRadarObstaclesradarObstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRadarObstaclesradarObstacle &dt)
    {
        dt=from_json_ApollodriversRadarObstaclesradarObstacle(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversRadarObstaclesradarObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRadarObstaclesradarObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
}
