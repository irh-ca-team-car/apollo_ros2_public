#include "adapter/serialization/apollo_msgs/apollov2x_position2_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xPosition2D &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        return obj;
    }
    Apollov2xPosition2D from_json_Apollov2xPosition2D (nlohmann::json obj) {
        Apollov2xPosition2D msg;
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
    Apollov2xPosition2D from_json<Apollov2xPosition2D>(nlohmann::json obj){
        return from_json_Apollov2xPosition2D(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xPosition2D &dt)
    {
        dt=from_json_Apollov2xPosition2D(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xPosition2D & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xPosition2D & dt)
    {
        os << to_json(dt);
        return os;
    }
}
