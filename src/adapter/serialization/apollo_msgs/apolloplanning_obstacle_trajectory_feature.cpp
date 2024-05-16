#include "adapter/serialization/apollo_msgs/apolloplanning_obstacle_trajectory_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObstacleTrajectoryFeature &msg) {
        nlohmann::json obj;
        nlohmann::json arr_perceptionobstaclehistory;
        for (auto it = msg.perceptionobstaclehistory.begin(); it != msg.perceptionobstaclehistory.end(); ++it) {
            arr_perceptionobstaclehistory.push_back(to_json(*it));
        }
        obj["perceptionobstaclehistory"] = arr_perceptionobstaclehistory;
        nlohmann::json arr_evaluatedtrajectorypoint;
        for (auto it = msg.evaluatedtrajectorypoint.begin(); it != msg.evaluatedtrajectorypoint.end(); ++it) {
            arr_evaluatedtrajectorypoint.push_back(to_json(*it));
        }
        obj["evaluatedtrajectorypoint"] = arr_evaluatedtrajectorypoint;
        return obj;
    }
    ApolloplanningObstacleTrajectoryFeature from_json_ApolloplanningObstacleTrajectoryFeature (nlohmann::json obj) {
        ApolloplanningObstacleTrajectoryFeature msg;
        if(obj.contains("perceptionobstaclehistory"))
        {
            if(obj["perceptionobstaclehistory"].is_array())
            {
                for (auto& element : obj["perceptionobstaclehistory"])
                {
                    msg.perceptionobstaclehistory.push_back(from_json_ApolloplanningPerceptionObstacleFeature(element));
                }
            }
            else
            {
                msg.perceptionobstaclehistory.push_back(from_json_ApolloplanningPerceptionObstacleFeature(obj["perceptionobstaclehistory"]));
            }
        }
        if(obj.contains("evaluatedtrajectorypoint"))
        {
            if(obj["evaluatedtrajectorypoint"].is_array())
            {
                for (auto& element : obj["evaluatedtrajectorypoint"])
                {
                    msg.evaluatedtrajectorypoint.push_back(from_json_ApolloplanningTrajectoryPointFeature(element));
                }
            }
            else
            {
                msg.evaluatedtrajectorypoint.push_back(from_json_ApolloplanningTrajectoryPointFeature(obj["evaluatedtrajectorypoint"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningObstacleTrajectoryFeature from_json<ApolloplanningObstacleTrajectoryFeature>(nlohmann::json obj){
        return from_json_ApolloplanningObstacleTrajectoryFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObstacleTrajectoryFeature &dt)
    {
        dt=from_json_ApolloplanningObstacleTrajectoryFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObstacleTrajectoryFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObstacleTrajectoryFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
