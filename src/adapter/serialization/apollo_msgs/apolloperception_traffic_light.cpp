#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionTrafficLight &msg) {
        nlohmann::json obj;
        obj["color"] = (msg.color);
        obj["id"] = (msg.id);
        obj["confidence"] = (msg.confidence);
        obj["trackingtime"] = (msg.trackingtime);
        obj["blink"] = (msg.blink);
        obj["remainingtime"] = (msg.remainingtime);
        return obj;
    }
    ApolloperceptionTrafficLight from_json_ApolloperceptionTrafficLight (nlohmann::json obj) {
        ApolloperceptionTrafficLight msg;
        if(obj.contains("color"))
        {
            msg.color = (obj["color"].is_string()?atoi(obj["color"].get<std::string>().c_str()):obj["color"].get<int>());
        }
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("confidence"))
        {
            msg.confidence = (obj["confidence"].is_string()?atof(obj["confidence"].get<std::string>().c_str()):obj["confidence"].get<double>());
        }
        if(obj.contains("trackingtime"))
        {
            msg.trackingtime = (obj["trackingtime"].is_string()?atof(obj["trackingtime"].get<std::string>().c_str()):obj["trackingtime"].get<double>());
        }
        if(obj.contains("blink"))
        {
            msg.blink = (obj["blink"].is_string()?(bool)atoi(obj["blink"].get<std::string>().c_str()):obj["blink"].get<bool>());
        }
        if(obj.contains("remainingtime"))
        {
            msg.remainingtime = (obj["remainingtime"].is_string()?atof(obj["remainingtime"].get<std::string>().c_str()):obj["remainingtime"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionTrafficLight from_json<ApolloperceptionTrafficLight>(nlohmann::json obj){
        return from_json_ApolloperceptionTrafficLight(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionTrafficLight &dt)
    {
        dt=from_json_ApolloperceptionTrafficLight(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
}
