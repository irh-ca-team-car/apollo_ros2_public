#include "adapter/serialization/apollo_msgs/quaternion.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Quaternion &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        obj["w"] = (msg.w);
        return obj;
    }
    Quaternion from_json_Quaternion (nlohmann::json obj) {
        Quaternion msg;
        if(obj.contains("x"))
        {
            msg.x = (obj["x"].is_string()?atof(obj["x"].get<std::string>().c_str()):obj["x"].get<double>());
        }
        if(obj.contains("y"))
        {
            msg.y = (obj["y"].is_string()?atof(obj["y"].get<std::string>().c_str()):obj["y"].get<double>());
        }
        if(obj.contains("z"))
        {
            msg.z = (obj["z"].is_string()?atof(obj["z"].get<std::string>().c_str()):obj["z"].get<double>());
        }
        if(obj.contains("w"))
        {
            msg.w = (obj["w"].is_string()?atof(obj["w"].get<std::string>().c_str()):obj["w"].get<double>());
        }
        return msg;
    }
    template <>
    Quaternion from_json<Quaternion>(nlohmann::json obj){
        return from_json_Quaternion(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Quaternion &dt)
    {
        dt=from_json_Quaternion(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Quaternion & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Quaternion & dt)
    {
        os << to_json(dt);
        return os;
    }
}
