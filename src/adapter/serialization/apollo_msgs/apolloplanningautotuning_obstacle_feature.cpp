#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_obstacle_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningObstacleFeature &msg) {
        nlohmann::json obj;
        obj["longitudinaldistance"] = (msg.longitudinaldistance);
        obj["obstaclespeed"] = (msg.obstaclespeed);
        obj["lateraldistance"] = (msg.lateraldistance);
        obj["probability"] = (msg.probability);
        obj["relativev"] = (msg.relativev);
        return obj;
    }
    ApolloplanningautotuningObstacleFeature from_json_ApolloplanningautotuningObstacleFeature (nlohmann::json obj) {
        ApolloplanningautotuningObstacleFeature msg;
        if(obj.contains("longitudinaldistance"))
        {
            msg.longitudinaldistance = (obj["longitudinaldistance"].is_string()?atof(obj["longitudinaldistance"].get<std::string>().c_str()):obj["longitudinaldistance"].get<double>());
        }
        if(obj.contains("obstaclespeed"))
        {
            msg.obstaclespeed = (obj["obstaclespeed"].is_string()?atof(obj["obstaclespeed"].get<std::string>().c_str()):obj["obstaclespeed"].get<double>());
        }
        if(obj.contains("lateraldistance"))
        {
            msg.lateraldistance = (obj["lateraldistance"].is_string()?atof(obj["lateraldistance"].get<std::string>().c_str()):obj["lateraldistance"].get<double>());
        }
        if(obj.contains("probability"))
        {
            msg.probability = (obj["probability"].is_string()?atof(obj["probability"].get<std::string>().c_str()):obj["probability"].get<double>());
        }
        if(obj.contains("relativev"))
        {
            msg.relativev = (obj["relativev"].is_string()?atof(obj["relativev"].get<std::string>().c_str()):obj["relativev"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningObstacleFeature from_json<ApolloplanningautotuningObstacleFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningObstacleFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningObstacleFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningObstacleFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningObstacleFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningObstacleFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
