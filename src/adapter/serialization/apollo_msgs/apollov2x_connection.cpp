#include "adapter/serialization/apollo_msgs/apollov2x_connection.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xConnection &msg) {
        nlohmann::json obj;
        obj["allowdrivingbehavior"] = (msg.allowdrivingbehavior);
        obj["phaseid"] = (msg.phaseid);
        return obj;
    }
    Apollov2xConnection from_json_Apollov2xConnection (nlohmann::json obj) {
        Apollov2xConnection msg;
        if(obj.contains("allowdrivingbehavior"))
        {
            msg.allowdrivingbehavior = (obj["allowdrivingbehavior"].is_string()?atoi(obj["allowdrivingbehavior"].get<std::string>().c_str()):obj["allowdrivingbehavior"].get<int>());
        }
        if(obj.contains("phaseid"))
        {
            msg.phaseid = (obj["phaseid"].is_string()?atoi(obj["phaseid"].get<std::string>().c_str()):obj["phaseid"].get<int>());
        }
        return msg;
    }
    template <>
    Apollov2xConnection from_json<Apollov2xConnection>(nlohmann::json obj){
        return from_json_Apollov2xConnection(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xConnection &dt)
    {
        dt=from_json_Apollov2xConnection(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xConnection & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xConnection & dt)
    {
        os << to_json(dt);
        return os;
    }
}
