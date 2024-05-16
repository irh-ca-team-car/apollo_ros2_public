#include "adapter/serialization/apollo_msgs/apollov2x_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xPoint &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        return obj;
    }
    Apollov2xPoint from_json_Apollov2xPoint (nlohmann::json obj) {
        Apollov2xPoint msg;
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
    Apollov2xPoint from_json<Apollov2xPoint>(nlohmann::json obj){
        return from_json_Apollov2xPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xPoint &dt)
    {
        dt=from_json_Apollov2xPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
