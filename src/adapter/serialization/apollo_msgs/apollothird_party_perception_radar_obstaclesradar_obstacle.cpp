#include "adapter/serialization/apollo_msgs/apollothird_party_perception_radar_obstaclesradar_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollothirdPartyPerceptionRadarObstaclesradarObstacle &msg) {
        nlohmann::json obj;
        obj["key"] = (msg.key);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollothirdPartyPerceptionRadarObstaclesradarObstacle from_json_ApollothirdPartyPerceptionRadarObstaclesradarObstacle (nlohmann::json obj) {
        ApollothirdPartyPerceptionRadarObstaclesradarObstacle msg;
        if(obj.contains("key"))
        {
            msg.key = (obj["key"].is_string()?atoi(obj["key"].get<std::string>().c_str()):obj["key"].get<int>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_ApollothirdPartyPerceptionRadarObstacle(obj["data"]);
        }
        return msg;
    }
    template <>
    ApollothirdPartyPerceptionRadarObstaclesradarObstacle from_json<ApollothirdPartyPerceptionRadarObstaclesradarObstacle>(nlohmann::json obj){
        return from_json_ApollothirdPartyPerceptionRadarObstaclesradarObstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollothirdPartyPerceptionRadarObstaclesradarObstacle &dt)
    {
        dt=from_json_ApollothirdPartyPerceptionRadarObstaclesradarObstacle(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollothirdPartyPerceptionRadarObstaclesradarObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollothirdPartyPerceptionRadarObstaclesradarObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
}
