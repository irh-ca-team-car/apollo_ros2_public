#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_trajectory_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionTrajectoryPoint &msg) {
        nlohmann::json obj;
        obj["pathpoint"] = to_json(msg.pathpoint);
        obj["timestamp"] = (msg.timestamp);
        return obj;
    }
    ApollopredictionPredictionTrajectoryPoint from_json_ApollopredictionPredictionTrajectoryPoint (nlohmann::json obj) {
        ApollopredictionPredictionTrajectoryPoint msg;
        if(obj.contains("pathpoint"))
        {
            msg.pathpoint = from_json_ApollopredictionPredictionPathPoint(obj["pathpoint"]);
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        return msg;
    }
    template <>
    ApollopredictionPredictionTrajectoryPoint from_json<ApollopredictionPredictionTrajectoryPoint>(nlohmann::json obj){
        return from_json_ApollopredictionPredictionTrajectoryPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionTrajectoryPoint &dt)
    {
        dt=from_json_ApollopredictionPredictionTrajectoryPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionTrajectoryPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionTrajectoryPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
