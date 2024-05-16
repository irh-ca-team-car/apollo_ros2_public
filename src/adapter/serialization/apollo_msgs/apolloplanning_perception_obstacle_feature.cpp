#include "adapter/serialization/apollo_msgs/apolloplanning_perception_obstacle_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPerceptionObstacleFeature &msg) {
        nlohmann::json obj;
        obj["timestampsec"] = (msg.timestampsec);
        obj["position"] = to_json(msg.position);
        obj["theta"] = (msg.theta);
        obj["velocity"] = to_json(msg.velocity);
        obj["acceleration"] = to_json(msg.acceleration);
        nlohmann::json arr_polygonpoint;
        for (auto it = msg.polygonpoint.begin(); it != msg.polygonpoint.end(); ++it) {
            arr_polygonpoint.push_back(to_json(*it));
        }
        obj["polygonpoint"] = arr_polygonpoint;
        return obj;
    }
    ApolloplanningPerceptionObstacleFeature from_json_ApolloplanningPerceptionObstacleFeature (nlohmann::json obj) {
        ApolloplanningPerceptionObstacleFeature msg;
        if(obj.contains("timestampsec"))
        {
            msg.timestampsec = (obj["timestampsec"].is_string()?atof(obj["timestampsec"].get<std::string>().c_str()):obj["timestampsec"].get<double>());
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPoint3D(obj["position"]);
        }
        if(obj.contains("theta"))
        {
            msg.theta = (obj["theta"].is_string()?atof(obj["theta"].get<std::string>().c_str()):obj["theta"].get<double>());
        }
        if(obj.contains("velocity"))
        {
            msg.velocity = from_json_ApollocommonPoint3D(obj["velocity"]);
        }
        if(obj.contains("acceleration"))
        {
            msg.acceleration = from_json_ApollocommonPoint3D(obj["acceleration"]);
        }
        if(obj.contains("polygonpoint"))
        {
            if(obj["polygonpoint"].is_array())
            {
                for (auto& element : obj["polygonpoint"])
                {
                    msg.polygonpoint.push_back(from_json_ApollocommonPoint3D(element));
                }
            }
            else
            {
                msg.polygonpoint.push_back(from_json_ApollocommonPoint3D(obj["polygonpoint"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningPerceptionObstacleFeature from_json<ApolloplanningPerceptionObstacleFeature>(nlohmann::json obj){
        return from_json_ApolloplanningPerceptionObstacleFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPerceptionObstacleFeature &dt)
    {
        dt=from_json_ApolloplanningPerceptionObstacleFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPerceptionObstacleFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPerceptionObstacleFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
