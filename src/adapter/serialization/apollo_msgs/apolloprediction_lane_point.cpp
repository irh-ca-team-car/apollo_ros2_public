#include "adapter/serialization/apollo_msgs/apolloprediction_lane_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLanePoint &msg) {
        nlohmann::json obj;
        obj["position"] = to_json(msg.position);
        obj["heading"] = (msg.heading);
        obj["width"] = (msg.width);
        obj["relatives"] = (msg.relatives);
        obj["relativel"] = (msg.relativel);
        obj["anglediff"] = (msg.anglediff);
        obj["kappa"] = (msg.kappa);
        obj["scenariotype"] = (msg.scenariotype);
        obj["speedlimit"] = (msg.speedlimit);
        return obj;
    }
    ApollopredictionLanePoint from_json_ApollopredictionLanePoint (nlohmann::json obj) {
        ApollopredictionLanePoint msg;
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPoint3D(obj["position"]);
        }
        if(obj.contains("heading"))
        {
            msg.heading = (obj["heading"].is_string()?atof(obj["heading"].get<std::string>().c_str()):obj["heading"].get<double>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atof(obj["width"].get<std::string>().c_str()):obj["width"].get<double>());
        }
        if(obj.contains("relatives"))
        {
            msg.relatives = (obj["relatives"].is_string()?atof(obj["relatives"].get<std::string>().c_str()):obj["relatives"].get<double>());
        }
        if(obj.contains("relativel"))
        {
            msg.relativel = (obj["relativel"].is_string()?atof(obj["relativel"].get<std::string>().c_str()):obj["relativel"].get<double>());
        }
        if(obj.contains("anglediff"))
        {
            msg.anglediff = (obj["anglediff"].is_string()?atof(obj["anglediff"].get<std::string>().c_str()):obj["anglediff"].get<double>());
        }
        if(obj.contains("kappa"))
        {
            msg.kappa = (obj["kappa"].is_string()?atof(obj["kappa"].get<std::string>().c_str()):obj["kappa"].get<double>());
        }
        if(obj.contains("scenariotype"))
        {
            msg.scenariotype = (obj["scenariotype"].is_string()?atoi(obj["scenariotype"].get<std::string>().c_str()):obj["scenariotype"].get<int>());
        }
        if(obj.contains("speedlimit"))
        {
            msg.speedlimit = (obj["speedlimit"].is_string()?atof(obj["speedlimit"].get<std::string>().c_str()):obj["speedlimit"].get<double>());
        }
        return msg;
    }
    template <>
    ApollopredictionLanePoint from_json<ApollopredictionLanePoint>(nlohmann::json obj){
        return from_json_ApollopredictionLanePoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLanePoint &dt)
    {
        dt=from_json_ApollopredictionLanePoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLanePoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLanePoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
