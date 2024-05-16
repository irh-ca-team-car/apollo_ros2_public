#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_detection_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficLightDetectionFeature &msg) {
        nlohmann::json obj;
        obj["messagetimestampsec"] = (msg.messagetimestampsec);
        nlohmann::json arr_trafficlight;
        for (auto it = msg.trafficlight.begin(); it != msg.trafficlight.end(); ++it) {
            arr_trafficlight.push_back(to_json(*it));
        }
        obj["trafficlight"] = arr_trafficlight;
        return obj;
    }
    ApolloplanningTrafficLightDetectionFeature from_json_ApolloplanningTrafficLightDetectionFeature (nlohmann::json obj) {
        ApolloplanningTrafficLightDetectionFeature msg;
        if(obj.contains("messagetimestampsec"))
        {
            msg.messagetimestampsec = (obj["messagetimestampsec"].is_string()?atof(obj["messagetimestampsec"].get<std::string>().c_str()):obj["messagetimestampsec"].get<double>());
        }
        if(obj.contains("trafficlight"))
        {
            if(obj["trafficlight"].is_array())
            {
                for (auto& element : obj["trafficlight"])
                {
                    msg.trafficlight.push_back(from_json_ApolloplanningTrafficLightFeature(element));
                }
            }
            else
            {
                msg.trafficlight.push_back(from_json_ApolloplanningTrafficLightFeature(obj["trafficlight"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningTrafficLightDetectionFeature from_json<ApolloplanningTrafficLightDetectionFeature>(nlohmann::json obj){
        return from_json_ApolloplanningTrafficLightDetectionFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficLightDetectionFeature &dt)
    {
        dt=from_json_ApolloplanningTrafficLightDetectionFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficLightDetectionFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficLightDetectionFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
