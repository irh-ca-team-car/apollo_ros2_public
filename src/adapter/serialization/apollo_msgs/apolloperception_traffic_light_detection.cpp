#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light_detection.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionTrafficLightDetection &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_trafficlight;
        for (auto it = msg.trafficlight.begin(); it != msg.trafficlight.end(); ++it) {
            arr_trafficlight.push_back(to_json(*it));
        }
        obj["trafficlight"] = arr_trafficlight;
        obj["trafficlightdebug"] = to_json(msg.trafficlightdebug);
        obj["containlights"] = (msg.containlights);
        obj["cameraid"] = (msg.cameraid);
        return obj;
    }
    ApolloperceptionTrafficLightDetection from_json_ApolloperceptionTrafficLightDetection (nlohmann::json obj) {
        ApolloperceptionTrafficLightDetection msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("trafficlight"))
        {
            if(obj["trafficlight"].is_array())
            {
                for (auto& element : obj["trafficlight"])
                {
                    msg.trafficlight.push_back(from_json_ApolloperceptionTrafficLight(element));
                }
            }
            else
            {
                msg.trafficlight.push_back(from_json_ApolloperceptionTrafficLight(obj["trafficlight"]));
            }
        }
        if(obj.contains("trafficlightdebug"))
        {
            msg.trafficlightdebug = from_json_ApolloperceptionTrafficLightDebug(obj["trafficlightdebug"]);
        }
        if(obj.contains("containlights"))
        {
            msg.containlights = (obj["containlights"].is_string()?(bool)atoi(obj["containlights"].get<std::string>().c_str()):obj["containlights"].get<bool>());
        }
        if(obj.contains("cameraid"))
        {
            msg.cameraid = (obj["cameraid"].is_string()?atoi(obj["cameraid"].get<std::string>().c_str()):obj["cameraid"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptionTrafficLightDetection from_json<ApolloperceptionTrafficLightDetection>(nlohmann::json obj){
        return from_json_ApolloperceptionTrafficLightDetection(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionTrafficLightDetection &dt)
    {
        dt=from_json_ApolloperceptionTrafficLightDetection(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionTrafficLightDetection & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionTrafficLightDetection & dt)
    {
        os << to_json(dt);
        return os;
    }
}
