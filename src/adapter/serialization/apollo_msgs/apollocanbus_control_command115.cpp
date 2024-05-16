#include "adapter/serialization/apollo_msgs/apollocanbus_control_command115.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusControlCommand115 &msg) {
        nlohmann::json obj;
        obj["ctrlcmd"] = (msg.ctrlcmd);
        return obj;
    }
    ApollocanbusControlCommand115 from_json_ApollocanbusControlCommand115 (nlohmann::json obj) {
        ApollocanbusControlCommand115 msg;
        if(obj.contains("ctrlcmd"))
        {
            msg.ctrlcmd = (obj["ctrlcmd"].is_string()?atoi(obj["ctrlcmd"].get<std::string>().c_str()):obj["ctrlcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusControlCommand115 from_json<ApollocanbusControlCommand115>(nlohmann::json obj){
        return from_json_ApollocanbusControlCommand115(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusControlCommand115 &dt)
    {
        dt=from_json_ApollocanbusControlCommand115(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusControlCommand115 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusControlCommand115 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
