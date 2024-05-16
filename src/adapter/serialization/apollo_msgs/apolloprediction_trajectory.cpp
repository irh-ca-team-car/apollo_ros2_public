#include "adapter/serialization/apollo_msgs/apolloprediction_trajectory.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionTrajectory &msg) {
        nlohmann::json obj;
        obj["probability"] = (msg.probability);
        nlohmann::json arr_trajectorypoint;
        for (auto it = msg.trajectorypoint.begin(); it != msg.trajectorypoint.end(); ++it) {
            arr_trajectorypoint.push_back(to_json(*it));
        }
        obj["trajectorypoint"] = arr_trajectorypoint;
        return obj;
    }
    ApollopredictionTrajectory from_json_ApollopredictionTrajectory (nlohmann::json obj) {
        ApollopredictionTrajectory msg;
        if(obj.contains("probability"))
        {
            msg.probability = (obj["probability"].is_string()?atof(obj["probability"].get<std::string>().c_str()):obj["probability"].get<double>());
        }
        if(obj.contains("trajectorypoint"))
        {
            if(obj["trajectorypoint"].is_array())
            {
                for (auto& element : obj["trajectorypoint"])
                {
                    msg.trajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(element));
                }
            }
            else
            {
                msg.trajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(obj["trajectorypoint"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionTrajectory from_json<ApollopredictionTrajectory>(nlohmann::json obj){
        return from_json_ApollopredictionTrajectory(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionTrajectory &dt)
    {
        dt=from_json_ApollopredictionTrajectory(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionTrajectory & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionTrajectory & dt)
    {
        os << to_json(dt);
        return os;
    }
}
