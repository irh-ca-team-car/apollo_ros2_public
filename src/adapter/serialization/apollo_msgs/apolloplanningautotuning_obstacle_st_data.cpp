#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_obstacle_st_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningObstacleSTData &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["speed"] = (msg.speed);
        obj["isvirtual"] = (msg.isvirtual);
        obj["probability"] = (msg.probability);
        nlohmann::json arr_polygon;
        for (auto it = msg.polygon.begin(); it != msg.polygon.end(); ++it) {
            arr_polygon.push_back(to_json(*it));
        }
        obj["polygon"] = arr_polygon;
        nlohmann::json arr_distribution;
        for (auto it = msg.distribution.begin(); it != msg.distribution.end(); ++it) {
            arr_distribution.push_back(to_json(*it));
        }
        obj["distribution"] = arr_distribution;
        return obj;
    }
    ApolloplanningautotuningObstacleSTData from_json_ApolloplanningautotuningObstacleSTData (nlohmann::json obj) {
        ApolloplanningautotuningObstacleSTData msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("speed"))
        {
            msg.speed = (obj["speed"].is_string()?atof(obj["speed"].get<std::string>().c_str()):obj["speed"].get<double>());
        }
        if(obj.contains("isvirtual"))
        {
            msg.isvirtual = (obj["isvirtual"].is_string()?(bool)atoi(obj["isvirtual"].get<std::string>().c_str()):obj["isvirtual"].get<bool>());
        }
        if(obj.contains("probability"))
        {
            msg.probability = (obj["probability"].is_string()?atof(obj["probability"].get<std::string>().c_str()):obj["probability"].get<double>());
        }
        if(obj.contains("polygon"))
        {
            if(obj["polygon"].is_array())
            {
                for (auto& element : obj["polygon"])
                {
                    msg.polygon.push_back(from_json_ApolloplanningautotuningSTPointPair(element));
                }
            }
            else
            {
                msg.polygon.push_back(from_json_ApolloplanningautotuningSTPointPair(obj["polygon"]));
            }
        }
        if(obj.contains("distribution"))
        {
            if(obj["distribution"].is_array())
            {
                for (auto& element : obj["distribution"])
                {
                    msg.distribution.push_back(from_json_ApolloplanningautotuningSTPointPair(element));
                }
            }
            else
            {
                msg.distribution.push_back(from_json_ApolloplanningautotuningSTPointPair(obj["distribution"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningObstacleSTData from_json<ApolloplanningautotuningObstacleSTData>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningObstacleSTData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningObstacleSTData &dt)
    {
        dt=from_json_ApolloplanningautotuningObstacleSTData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningObstacleSTData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningObstacleSTData & dt)
    {
        os << to_json(dt);
        return os;
    }
}
