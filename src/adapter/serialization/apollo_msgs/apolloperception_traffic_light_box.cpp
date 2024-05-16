#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light_box.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionTrafficLightBox &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["width"] = (msg.width);
        obj["height"] = (msg.height);
        obj["color"] = (msg.color);
        obj["selected"] = (msg.selected);
        obj["cameraname"] = (msg.cameraname);
        return obj;
    }
    ApolloperceptionTrafficLightBox from_json_ApolloperceptionTrafficLightBox (nlohmann::json obj) {
        ApolloperceptionTrafficLightBox msg;
        if(obj.contains("x"))
        {
            msg.x = (obj["x"].is_string()?atoi(obj["x"].get<std::string>().c_str()):obj["x"].get<int>());
        }
        if(obj.contains("y"))
        {
            msg.y = (obj["y"].is_string()?atoi(obj["y"].get<std::string>().c_str()):obj["y"].get<int>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<int>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atoi(obj["height"].get<std::string>().c_str()):obj["height"].get<int>());
        }
        if(obj.contains("color"))
        {
            msg.color = (obj["color"].is_string()?atoi(obj["color"].get<std::string>().c_str()):obj["color"].get<int>());
        }
        if(obj.contains("selected"))
        {
            msg.selected = (obj["selected"].is_string()?(bool)atoi(obj["selected"].get<std::string>().c_str()):obj["selected"].get<bool>());
        }
        if(obj.contains("cameraname"))
        {
            msg.cameraname = (obj["cameraname"].is_string()?(obj["cameraname"].get<std::string>().c_str()):obj["cameraname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptionTrafficLightBox from_json<ApolloperceptionTrafficLightBox>(nlohmann::json obj){
        return from_json_ApolloperceptionTrafficLightBox(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionTrafficLightBox &dt)
    {
        dt=from_json_ApolloperceptionTrafficLightBox(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionTrafficLightBox & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionTrafficLightBox & dt)
    {
        os << to_json(dt);
        return os;
    }
}
