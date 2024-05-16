#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_path_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionPathPoint &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["velocityheading"] = (msg.velocityheading);
        return obj;
    }
    ApollopredictionPredictionPathPoint from_json_ApollopredictionPredictionPathPoint (nlohmann::json obj) {
        ApollopredictionPredictionPathPoint msg;
        if(obj.contains("x"))
        {
            msg.x = (obj["x"].is_string()?atof(obj["x"].get<std::string>().c_str()):obj["x"].get<double>());
        }
        if(obj.contains("y"))
        {
            msg.y = (obj["y"].is_string()?atof(obj["y"].get<std::string>().c_str()):obj["y"].get<double>());
        }
        if(obj.contains("velocityheading"))
        {
            msg.velocityheading = (obj["velocityheading"].is_string()?atof(obj["velocityheading"].get<std::string>().c_str()):obj["velocityheading"].get<double>());
        }
        return msg;
    }
    template <>
    ApollopredictionPredictionPathPoint from_json<ApollopredictionPredictionPathPoint>(nlohmann::json obj){
        return from_json_ApollopredictionPredictionPathPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionPathPoint &dt)
    {
        dt=from_json_ApollopredictionPredictionPathPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionPathPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionPathPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
