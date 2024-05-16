#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_obstacle_st_raw_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningObstacleSTRawData &msg) {
        nlohmann::json obj;
        nlohmann::json arr_obstaclestdata;
        for (auto it = msg.obstaclestdata.begin(); it != msg.obstaclestdata.end(); ++it) {
            arr_obstaclestdata.push_back(to_json(*it));
        }
        obj["obstaclestdata"] = arr_obstaclestdata;
        nlohmann::json arr_obstaclestnudge;
        for (auto it = msg.obstaclestnudge.begin(); it != msg.obstaclestnudge.end(); ++it) {
            arr_obstaclestnudge.push_back(to_json(*it));
        }
        obj["obstaclestnudge"] = arr_obstaclestnudge;
        nlohmann::json arr_obstaclestsidepass;
        for (auto it = msg.obstaclestsidepass.begin(); it != msg.obstaclestsidepass.end(); ++it) {
            arr_obstaclestsidepass.push_back(to_json(*it));
        }
        obj["obstaclestsidepass"] = arr_obstaclestsidepass;
        return obj;
    }
    ApolloplanningautotuningObstacleSTRawData from_json_ApolloplanningautotuningObstacleSTRawData (nlohmann::json obj) {
        ApolloplanningautotuningObstacleSTRawData msg;
        if(obj.contains("obstaclestdata"))
        {
            if(obj["obstaclestdata"].is_array())
            {
                for (auto& element : obj["obstaclestdata"])
                {
                    msg.obstaclestdata.push_back(from_json_ApolloplanningautotuningObstacleSTData(element));
                }
            }
            else
            {
                msg.obstaclestdata.push_back(from_json_ApolloplanningautotuningObstacleSTData(obj["obstaclestdata"]));
            }
        }
        if(obj.contains("obstaclestnudge"))
        {
            if(obj["obstaclestnudge"].is_array())
            {
                for (auto& element : obj["obstaclestnudge"])
                {
                    msg.obstaclestnudge.push_back(from_json_ApolloplanningautotuningObstacleSTData(element));
                }
            }
            else
            {
                msg.obstaclestnudge.push_back(from_json_ApolloplanningautotuningObstacleSTData(obj["obstaclestnudge"]));
            }
        }
        if(obj.contains("obstaclestsidepass"))
        {
            if(obj["obstaclestsidepass"].is_array())
            {
                for (auto& element : obj["obstaclestsidepass"])
                {
                    msg.obstaclestsidepass.push_back(from_json_ApolloplanningautotuningObstacleSTData(element));
                }
            }
            else
            {
                msg.obstaclestsidepass.push_back(from_json_ApolloplanningautotuningObstacleSTData(obj["obstaclestsidepass"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningObstacleSTRawData from_json<ApolloplanningautotuningObstacleSTRawData>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningObstacleSTRawData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningObstacleSTRawData &dt)
    {
        dt=from_json_ApolloplanningautotuningObstacleSTRawData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningObstacleSTRawData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningObstacleSTRawData & dt)
    {
        os << to_json(dt);
        return os;
    }
}
