#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_dim.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraDim &msg) {
        nlohmann::json obj;
        obj["h"] = (msg.h);
        obj["w"] = (msg.w);
        obj["l"] = (msg.l);
        return obj;
    }
    ApolloperceptioncameraDim from_json_ApolloperceptioncameraDim (nlohmann::json obj) {
        ApolloperceptioncameraDim msg;
        if(obj.contains("h"))
        {
            msg.h = (obj["h"].is_string()?(float)atof(obj["h"].get<std::string>().c_str()):obj["h"].get<float>());
        }
        if(obj.contains("w"))
        {
            msg.w = (obj["w"].is_string()?(float)atof(obj["w"].get<std::string>().c_str()):obj["w"].get<float>());
        }
        if(obj.contains("l"))
        {
            msg.l = (obj["l"].is_string()?(float)atof(obj["l"].get<std::string>().c_str()):obj["l"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraDim from_json<ApolloperceptioncameraDim>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraDim(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraDim &dt)
    {
        dt=from_json_ApolloperceptioncameraDim(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraDim & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraDim & dt)
    {
        os << to_json(dt);
        return os;
    }
}
