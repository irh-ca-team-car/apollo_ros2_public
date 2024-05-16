#include "adapter/serialization/apollo_msgs/vector4.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Vector4 &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        obj["i"] = (msg.i);
        obj["isground"] = (msg.isground);
        return obj;
    }
    Vector4 from_json_Vector4 (nlohmann::json obj) {
        Vector4 msg;
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
        if(obj.contains("i"))
        {
            msg.i = (obj["i"].is_string()?atof(obj["i"].get<std::string>().c_str()):obj["i"].get<double>());
        }
        if(obj.contains("isground"))
        {
            msg.isground = (obj["isground"].is_string()?(bool)atoi(obj["isground"].get<std::string>().c_str()):obj["isground"].get<bool>());
        }
        return msg;
    }
    template <>
    Vector4 from_json<Vector4>(nlohmann::json obj){
        return from_json_Vector4(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Vector4 &dt)
    {
        dt=from_json_Vector4(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Vector4 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Vector4 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
