#include "adapter/serialization/apollo_msgs/apolloperceptioninference_b_box3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBBox3D &msg) {
        nlohmann::json obj;
        obj["h"] = (msg.h);
        obj["w"] = (msg.w);
        obj["l"] = (msg.l);
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        obj["alpha"] = (msg.alpha);
        return obj;
    }
    ApolloperceptioninferenceBBox3D from_json_ApolloperceptioninferenceBBox3D (nlohmann::json obj) {
        ApolloperceptioninferenceBBox3D msg;
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
        if(obj.contains("x"))
        {
            msg.x = (obj["x"].is_string()?(float)atof(obj["x"].get<std::string>().c_str()):obj["x"].get<float>());
        }
        if(obj.contains("y"))
        {
            msg.y = (obj["y"].is_string()?(float)atof(obj["y"].get<std::string>().c_str()):obj["y"].get<float>());
        }
        if(obj.contains("z"))
        {
            msg.z = (obj["z"].is_string()?(float)atof(obj["z"].get<std::string>().c_str()):obj["z"].get<float>());
        }
        if(obj.contains("alpha"))
        {
            msg.alpha = (obj["alpha"].is_string()?(float)atof(obj["alpha"].get<std::string>().c_str()):obj["alpha"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceBBox3D from_json<ApolloperceptioninferenceBBox3D>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceBBox3D(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBBox3D &dt)
    {
        dt=from_json_ApolloperceptioninferenceBBox3D(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBBox3D & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBBox3D & dt)
    {
        os << to_json(dt);
        return os;
    }
}
