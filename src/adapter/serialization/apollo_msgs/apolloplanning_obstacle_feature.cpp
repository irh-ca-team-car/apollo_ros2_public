#include "adapter/serialization/apollo_msgs/apolloplanning_obstacle_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObstacleFeature &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["length"] = (msg.length);
        obj["width"] = (msg.width);
        obj["height"] = (msg.height);
        obj["type"] = (msg.type);
        obj["obstacletrajectory"] = to_json(msg.obstacletrajectory);
        obj["obstacleprediction"] = to_json(msg.obstacleprediction);
        return obj;
    }
    ApolloplanningObstacleFeature from_json_ApolloplanningObstacleFeature (nlohmann::json obj) {
        ApolloplanningObstacleFeature msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("length"))
        {
            msg.length = (obj["length"].is_string()?atof(obj["length"].get<std::string>().c_str()):obj["length"].get<double>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atof(obj["width"].get<std::string>().c_str()):obj["width"].get<double>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atof(obj["height"].get<std::string>().c_str()):obj["height"].get<double>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("obstacletrajectory"))
        {
            msg.obstacletrajectory = from_json_ApolloplanningObstacleTrajectoryFeature(obj["obstacletrajectory"]);
        }
        if(obj.contains("obstacleprediction"))
        {
            msg.obstacleprediction = from_json_ApolloplanningPredictionObstacleFeature(obj["obstacleprediction"]);
        }
        return msg;
    }
    template <>
    ApolloplanningObstacleFeature from_json<ApolloplanningObstacleFeature>(nlohmann::json obj){
        return from_json_ApolloplanningObstacleFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObstacleFeature &dt)
    {
        dt=from_json_ApolloplanningObstacleFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObstacleFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObstacleFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
