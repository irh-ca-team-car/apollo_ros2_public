#include "adapter/serialization/apollo_msgs/apolloprediction_obstacle_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionObstacleConf &msg) {
        nlohmann::json obj;
        obj["obstacletype"] = (msg.obstacletype);
        obj["obstaclestatus"] = (msg.obstaclestatus);
        obj["prioritytype"] = (msg.prioritytype);
        obj["evaluatortype"] = (msg.evaluatortype);
        obj["predictortype"] = (msg.predictortype);
        return obj;
    }
    ApollopredictionObstacleConf from_json_ApollopredictionObstacleConf (nlohmann::json obj) {
        ApollopredictionObstacleConf msg;
        if(obj.contains("obstacletype"))
        {
            msg.obstacletype = (obj["obstacletype"].is_string()?atoi(obj["obstacletype"].get<std::string>().c_str()):obj["obstacletype"].get<int>());
        }
        if(obj.contains("obstaclestatus"))
        {
            msg.obstaclestatus = (obj["obstaclestatus"].is_string()?atoi(obj["obstaclestatus"].get<std::string>().c_str()):obj["obstaclestatus"].get<int>());
        }
        if(obj.contains("prioritytype"))
        {
            msg.prioritytype = (obj["prioritytype"].is_string()?atoi(obj["prioritytype"].get<std::string>().c_str()):obj["prioritytype"].get<int>());
        }
        if(obj.contains("evaluatortype"))
        {
            msg.evaluatortype = (obj["evaluatortype"].is_string()?atoi(obj["evaluatortype"].get<std::string>().c_str()):obj["evaluatortype"].get<int>());
        }
        if(obj.contains("predictortype"))
        {
            msg.predictortype = (obj["predictortype"].is_string()?atoi(obj["predictortype"].get<std::string>().c_str()):obj["predictortype"].get<int>());
        }
        return msg;
    }
    template <>
    ApollopredictionObstacleConf from_json<ApollopredictionObstacleConf>(nlohmann::json obj){
        return from_json_ApollopredictionObstacleConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionObstacleConf &dt)
    {
        dt=from_json_ApollopredictionObstacleConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionObstacleConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionObstacleConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
