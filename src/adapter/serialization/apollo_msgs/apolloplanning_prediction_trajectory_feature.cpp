#include "adapter/serialization/apollo_msgs/apolloplanning_prediction_trajectory_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPredictionTrajectoryFeature &msg) {
        nlohmann::json obj;
        obj["probability"] = (msg.probability);
        nlohmann::json arr_trajectorypoint;
        for (auto it = msg.trajectorypoint.begin(); it != msg.trajectorypoint.end(); ++it) {
            arr_trajectorypoint.push_back(to_json(*it));
        }
        obj["trajectorypoint"] = arr_trajectorypoint;
        return obj;
    }
    ApolloplanningPredictionTrajectoryFeature from_json_ApolloplanningPredictionTrajectoryFeature (nlohmann::json obj) {
        ApolloplanningPredictionTrajectoryFeature msg;
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
                    msg.trajectorypoint.push_back(from_json_ApolloplanningTrajectoryPointFeature(element));
                }
            }
            else
            {
                msg.trajectorypoint.push_back(from_json_ApolloplanningTrajectoryPointFeature(obj["trajectorypoint"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningPredictionTrajectoryFeature from_json<ApolloplanningPredictionTrajectoryFeature>(nlohmann::json obj){
        return from_json_ApolloplanningPredictionTrajectoryFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPredictionTrajectoryFeature &dt)
    {
        dt=from_json_ApolloplanningPredictionTrajectoryFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPredictionTrajectoryFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPredictionTrajectoryFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
