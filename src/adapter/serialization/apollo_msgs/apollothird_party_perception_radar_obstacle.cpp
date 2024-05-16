#include "adapter/serialization/apollo_msgs/apollothird_party_perception_radar_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollothirdPartyPerceptionRadarObstacle &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["relativeposition"] = to_json(msg.relativeposition);
        obj["relativevelocity"] = to_json(msg.relativevelocity);
        obj["rcs"] = (msg.rcs);
        obj["movable"] = (msg.movable);
        obj["width"] = (msg.width);
        obj["length"] = (msg.length);
        obj["height"] = (msg.height);
        obj["theta"] = (msg.theta);
        obj["absoluteposition"] = to_json(msg.absoluteposition);
        obj["absolutevelocity"] = to_json(msg.absolutevelocity);
        obj["count"] = (msg.count);
        obj["movingframescount"] = (msg.movingframescount);
        return obj;
    }
    ApollothirdPartyPerceptionRadarObstacle from_json_ApollothirdPartyPerceptionRadarObstacle (nlohmann::json obj) {
        ApollothirdPartyPerceptionRadarObstacle msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("relativeposition"))
        {
            msg.relativeposition = from_json_ApollocommonPoint3D(obj["relativeposition"]);
        }
        if(obj.contains("relativevelocity"))
        {
            msg.relativevelocity = from_json_ApollocommonPoint3D(obj["relativevelocity"]);
        }
        if(obj.contains("rcs"))
        {
            msg.rcs = (obj["rcs"].is_string()?atof(obj["rcs"].get<std::string>().c_str()):obj["rcs"].get<double>());
        }
        if(obj.contains("movable"))
        {
            msg.movable = (obj["movable"].is_string()?(bool)atoi(obj["movable"].get<std::string>().c_str()):obj["movable"].get<bool>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atof(obj["width"].get<std::string>().c_str()):obj["width"].get<double>());
        }
        if(obj.contains("length"))
        {
            msg.length = (obj["length"].is_string()?atof(obj["length"].get<std::string>().c_str()):obj["length"].get<double>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atof(obj["height"].get<std::string>().c_str()):obj["height"].get<double>());
        }
        if(obj.contains("theta"))
        {
            msg.theta = (obj["theta"].is_string()?atof(obj["theta"].get<std::string>().c_str()):obj["theta"].get<double>());
        }
        if(obj.contains("absoluteposition"))
        {
            msg.absoluteposition = from_json_ApollocommonPoint3D(obj["absoluteposition"]);
        }
        if(obj.contains("absolutevelocity"))
        {
            msg.absolutevelocity = from_json_ApollocommonPoint3D(obj["absolutevelocity"]);
        }
        if(obj.contains("count"))
        {
            msg.count = (obj["count"].is_string()?atoi(obj["count"].get<std::string>().c_str()):obj["count"].get<int>());
        }
        if(obj.contains("movingframescount"))
        {
            msg.movingframescount = (obj["movingframescount"].is_string()?atoi(obj["movingframescount"].get<std::string>().c_str()):obj["movingframescount"].get<int>());
        }
        return msg;
    }
    template <>
    ApollothirdPartyPerceptionRadarObstacle from_json<ApollothirdPartyPerceptionRadarObstacle>(nlohmann::json obj){
        return from_json_ApollothirdPartyPerceptionRadarObstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollothirdPartyPerceptionRadarObstacle &dt)
    {
        dt=from_json_ApollothirdPartyPerceptionRadarObstacle(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollothirdPartyPerceptionRadarObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollothirdPartyPerceptionRadarObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
}
