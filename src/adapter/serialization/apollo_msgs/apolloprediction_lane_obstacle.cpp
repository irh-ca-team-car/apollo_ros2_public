#include "adapter/serialization/apollo_msgs/apolloprediction_lane_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneObstacle &msg) {
        nlohmann::json obj;
        obj["obstacleid"] = (msg.obstacleid);
        obj["laneid"] = (msg.laneid);
        obj["lanes"] = (msg.lanes);
        obj["lanel"] = (msg.lanel);
        return obj;
    }
    ApollopredictionLaneObstacle from_json_ApollopredictionLaneObstacle (nlohmann::json obj) {
        ApollopredictionLaneObstacle msg;
        if(obj.contains("obstacleid"))
        {
            msg.obstacleid = (obj["obstacleid"].is_string()?atoi(obj["obstacleid"].get<std::string>().c_str()):obj["obstacleid"].get<int>());
        }
        if(obj.contains("laneid"))
        {
            msg.laneid = (obj["laneid"].is_string()?(obj["laneid"].get<std::string>().c_str()):obj["laneid"].get<std::string>());
        }
        if(obj.contains("lanes"))
        {
            msg.lanes = (obj["lanes"].is_string()?atof(obj["lanes"].get<std::string>().c_str()):obj["lanes"].get<double>());
        }
        if(obj.contains("lanel"))
        {
            msg.lanel = (obj["lanel"].is_string()?atof(obj["lanel"].get<std::string>().c_str()):obj["lanel"].get<double>());
        }
        return msg;
    }
    template <>
    ApollopredictionLaneObstacle from_json<ApollopredictionLaneObstacle>(nlohmann::json obj){
        return from_json_ApollopredictionLaneObstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneObstacle &dt)
    {
        dt=from_json_ApollopredictionLaneObstacle(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
}
