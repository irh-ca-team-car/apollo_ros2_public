#include "adapter/serialization/apollo_msgs/apolloplanning_internal_open_space_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalOpenSpaceDebug &msg) {
        nlohmann::json obj;
        obj["trajectories"] = to_json(msg.trajectories);
        obj["warmstarttrajectory"] = to_json(msg.warmstarttrajectory);
        obj["smoothedtrajectory"] = to_json(msg.smoothedtrajectory);
        nlohmann::json arr_warmstartduallambda;
        for (auto it = msg.warmstartduallambda.begin(); it != msg.warmstartduallambda.end(); ++it) {
            arr_warmstartduallambda.push_back((*it));
        }
        obj["warmstartduallambda"] = arr_warmstartduallambda;
        nlohmann::json arr_warmstartdualmiu;
        for (auto it = msg.warmstartdualmiu.begin(); it != msg.warmstartdualmiu.end(); ++it) {
            arr_warmstartdualmiu.push_back((*it));
        }
        obj["warmstartdualmiu"] = arr_warmstartdualmiu;
        nlohmann::json arr_optimizedduallambda;
        for (auto it = msg.optimizedduallambda.begin(); it != msg.optimizedduallambda.end(); ++it) {
            arr_optimizedduallambda.push_back((*it));
        }
        obj["optimizedduallambda"] = arr_optimizedduallambda;
        nlohmann::json arr_optimizeddualmiu;
        for (auto it = msg.optimizeddualmiu.begin(); it != msg.optimizeddualmiu.end(); ++it) {
            arr_optimizeddualmiu.push_back((*it));
        }
        obj["optimizeddualmiu"] = arr_optimizeddualmiu;
        nlohmann::json arr_xyboundary;
        for (auto it = msg.xyboundary.begin(); it != msg.xyboundary.end(); ++it) {
            arr_xyboundary.push_back((*it));
        }
        obj["xyboundary"] = arr_xyboundary;
        nlohmann::json arr_obstacles;
        for (auto it = msg.obstacles.begin(); it != msg.obstacles.end(); ++it) {
            arr_obstacles.push_back(to_json(*it));
        }
        obj["obstacles"] = arr_obstacles;
        obj["roishiftpoint"] = to_json(msg.roishiftpoint);
        obj["endpoint"] = to_json(msg.endpoint);
        obj["partitionedtrajectories"] = to_json(msg.partitionedtrajectories);
        obj["chosentrajectory"] = to_json(msg.chosentrajectory);
        obj["isfallbacktrajectory"] = (msg.isfallbacktrajectory);
        obj["fallbacktrajectory"] = to_json(msg.fallbacktrajectory);
        obj["trajectorystitchingpoint"] = to_json(msg.trajectorystitchingpoint);
        obj["futurecollisionpoint"] = to_json(msg.futurecollisionpoint);
        obj["timelatency"] = (msg.timelatency);
        obj["originpoint"] = to_json(msg.originpoint);
        obj["originheadingrad"] = (msg.originheadingrad);
        return obj;
    }
    ApolloplanningInternalOpenSpaceDebug from_json_ApolloplanningInternalOpenSpaceDebug (nlohmann::json obj) {
        ApolloplanningInternalOpenSpaceDebug msg;
        if(obj.contains("trajectories"))
        {
            msg.trajectories = from_json_ApolloplanningInternalTrajectories(obj["trajectories"]);
        }
        if(obj.contains("warmstarttrajectory"))
        {
            msg.warmstarttrajectory = from_json_ApollocommonVehicleMotion(obj["warmstarttrajectory"]);
        }
        if(obj.contains("smoothedtrajectory"))
        {
            msg.smoothedtrajectory = from_json_ApollocommonVehicleMotion(obj["smoothedtrajectory"]);
        }
        if(obj.contains("warmstartduallambda"))
        {
            if(obj["warmstartduallambda"].is_array())
            {
                for (auto& element : obj["warmstartduallambda"])
                {
                    msg.warmstartduallambda.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.warmstartduallambda.push_back((obj["warmstartduallambda"].is_string()?atof(obj["warmstartduallambda"].get<std::string>().c_str()):obj["warmstartduallambda"].get<double>()));
            }
        }
        if(obj.contains("warmstartdualmiu"))
        {
            if(obj["warmstartdualmiu"].is_array())
            {
                for (auto& element : obj["warmstartdualmiu"])
                {
                    msg.warmstartdualmiu.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.warmstartdualmiu.push_back((obj["warmstartdualmiu"].is_string()?atof(obj["warmstartdualmiu"].get<std::string>().c_str()):obj["warmstartdualmiu"].get<double>()));
            }
        }
        if(obj.contains("optimizedduallambda"))
        {
            if(obj["optimizedduallambda"].is_array())
            {
                for (auto& element : obj["optimizedduallambda"])
                {
                    msg.optimizedduallambda.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.optimizedduallambda.push_back((obj["optimizedduallambda"].is_string()?atof(obj["optimizedduallambda"].get<std::string>().c_str()):obj["optimizedduallambda"].get<double>()));
            }
        }
        if(obj.contains("optimizeddualmiu"))
        {
            if(obj["optimizeddualmiu"].is_array())
            {
                for (auto& element : obj["optimizeddualmiu"])
                {
                    msg.optimizeddualmiu.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.optimizeddualmiu.push_back((obj["optimizeddualmiu"].is_string()?atof(obj["optimizeddualmiu"].get<std::string>().c_str()):obj["optimizeddualmiu"].get<double>()));
            }
        }
        if(obj.contains("xyboundary"))
        {
            if(obj["xyboundary"].is_array())
            {
                for (auto& element : obj["xyboundary"])
                {
                    msg.xyboundary.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.xyboundary.push_back((obj["xyboundary"].is_string()?atof(obj["xyboundary"].get<std::string>().c_str()):obj["xyboundary"].get<double>()));
            }
        }
        if(obj.contains("obstacles"))
        {
            if(obj["obstacles"].is_array())
            {
                for (auto& element : obj["obstacles"])
                {
                    msg.obstacles.push_back(from_json_ApolloplanningInternalObstacleDebug(element));
                }
            }
            else
            {
                msg.obstacles.push_back(from_json_ApolloplanningInternalObstacleDebug(obj["obstacles"]));
            }
        }
        if(obj.contains("roishiftpoint"))
        {
            msg.roishiftpoint = from_json_ApollocommonTrajectoryPoint(obj["roishiftpoint"]);
        }
        if(obj.contains("endpoint"))
        {
            msg.endpoint = from_json_ApollocommonTrajectoryPoint(obj["endpoint"]);
        }
        if(obj.contains("partitionedtrajectories"))
        {
            msg.partitionedtrajectories = from_json_ApolloplanningInternalTrajectories(obj["partitionedtrajectories"]);
        }
        if(obj.contains("chosentrajectory"))
        {
            msg.chosentrajectory = from_json_ApolloplanningInternalTrajectories(obj["chosentrajectory"]);
        }
        if(obj.contains("isfallbacktrajectory"))
        {
            msg.isfallbacktrajectory = (obj["isfallbacktrajectory"].is_string()?(bool)atoi(obj["isfallbacktrajectory"].get<std::string>().c_str()):obj["isfallbacktrajectory"].get<bool>());
        }
        if(obj.contains("fallbacktrajectory"))
        {
            msg.fallbacktrajectory = from_json_ApolloplanningInternalTrajectories(obj["fallbacktrajectory"]);
        }
        if(obj.contains("trajectorystitchingpoint"))
        {
            msg.trajectorystitchingpoint = from_json_ApollocommonTrajectoryPoint(obj["trajectorystitchingpoint"]);
        }
        if(obj.contains("futurecollisionpoint"))
        {
            msg.futurecollisionpoint = from_json_ApollocommonTrajectoryPoint(obj["futurecollisionpoint"]);
        }
        if(obj.contains("timelatency"))
        {
            msg.timelatency = (obj["timelatency"].is_string()?atof(obj["timelatency"].get<std::string>().c_str()):obj["timelatency"].get<double>());
        }
        if(obj.contains("originpoint"))
        {
            msg.originpoint = from_json_ApollocommonPointENU(obj["originpoint"]);
        }
        if(obj.contains("originheadingrad"))
        {
            msg.originheadingrad = (obj["originheadingrad"].is_string()?atof(obj["originheadingrad"].get<std::string>().c_str()):obj["originheadingrad"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningInternalOpenSpaceDebug from_json<ApolloplanningInternalOpenSpaceDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalOpenSpaceDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalOpenSpaceDebug &dt)
    {
        dt=from_json_ApolloplanningInternalOpenSpaceDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalOpenSpaceDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalOpenSpaceDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
