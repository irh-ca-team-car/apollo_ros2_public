#include "adapter/serialization/apollo_msgs/apollov2x_rsi_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xRsiPoint &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        return obj;
    }
    Apollov2xRsiPoint from_json_Apollov2xRsiPoint (nlohmann::json obj) {
        Apollov2xRsiPoint msg;
        if(obj.contains("x"))
        {
            msg.x = (obj["x"].is_string()?atof(obj["x"].get<std::string>().c_str()):obj["x"].get<double>());
        }
        if(obj.contains("y"))
        {
            msg.y = (obj["y"].is_string()?atof(obj["y"].get<std::string>().c_str()):obj["y"].get<double>());
        }
        return msg;
    }
    template <>
    Apollov2xRsiPoint from_json<Apollov2xRsiPoint>(nlohmann::json obj){
        return from_json_Apollov2xRsiPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xRsiPoint &dt)
    {
        dt=from_json_Apollov2xRsiPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xRsiPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xRsiPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
