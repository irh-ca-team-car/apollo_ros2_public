#include "adapter/serialization/apollo_msgs/apollocanbus_horn_rpt79.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHornRpt79 &msg) {
        nlohmann::json obj;
        obj["outputvalue"] = (msg.outputvalue);
        obj["commandedvalue"] = (msg.commandedvalue);
        obj["manualinput"] = (msg.manualinput);
        return obj;
    }
    ApollocanbusHornRpt79 from_json_ApollocanbusHornRpt79 (nlohmann::json obj) {
        ApollocanbusHornRpt79 msg;
        if(obj.contains("outputvalue"))
        {
            msg.outputvalue = (obj["outputvalue"].is_string()?atoi(obj["outputvalue"].get<std::string>().c_str()):obj["outputvalue"].get<int>());
        }
        if(obj.contains("commandedvalue"))
        {
            msg.commandedvalue = (obj["commandedvalue"].is_string()?atoi(obj["commandedvalue"].get<std::string>().c_str()):obj["commandedvalue"].get<int>());
        }
        if(obj.contains("manualinput"))
        {
            msg.manualinput = (obj["manualinput"].is_string()?atoi(obj["manualinput"].get<std::string>().c_str()):obj["manualinput"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusHornRpt79 from_json<ApollocanbusHornRpt79>(nlohmann::json obj){
        return from_json_ApollocanbusHornRpt79(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHornRpt79 &dt)
    {
        dt=from_json_ApollocanbusHornRpt79(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHornRpt79 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHornRpt79 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
