#include "adapter/serialization/apollo_msgs/vector3.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Vector3 &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        return obj;
    }
    Vector3 from_json_Vector3 (nlohmann::json obj) {
        Vector3 msg;
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
        return msg;
    }
    template <>
    Vector3 from_json<Vector3>(nlohmann::json obj){
        return from_json_Vector3(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Vector3 &dt)
    {
        dt=from_json_Vector3(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Vector3 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Vector3 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
