#include "adapter/serialization/apollo_msgs/apollov2x_phase.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xPhase &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["color"] = (msg.color);
        obj["colorremainingtimes"] = (msg.colorremainingtimes);
        return obj;
    }
    Apollov2xPhase from_json_Apollov2xPhase (nlohmann::json obj) {
        Apollov2xPhase msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("color"))
        {
            msg.color = (obj["color"].is_string()?atoi(obj["color"].get<std::string>().c_str()):obj["color"].get<int>());
        }
        if(obj.contains("colorremainingtimes"))
        {
            msg.colorremainingtimes = (obj["colorremainingtimes"].is_string()?atoi(obj["colorremainingtimes"].get<std::string>().c_str()):obj["colorremainingtimes"].get<int>());
        }
        return msg;
    }
    template <>
    Apollov2xPhase from_json<Apollov2xPhase>(nlohmann::json obj){
        return from_json_Apollov2xPhase(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xPhase &dt)
    {
        dt=from_json_Apollov2xPhase(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xPhase & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xPhase & dt)
    {
        os << to_json(dt);
        return os;
    }
}
