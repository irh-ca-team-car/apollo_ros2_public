#include "adapter/serialization/apollo_msgs/apollocanbus_accel_rpt68.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAccelRpt68 &msg) {
        nlohmann::json obj;
        obj["manualinput"] = (msg.manualinput);
        obj["commandedvalue"] = (msg.commandedvalue);
        obj["outputvalue"] = (msg.outputvalue);
        return obj;
    }
    ApollocanbusAccelRpt68 from_json_ApollocanbusAccelRpt68 (nlohmann::json obj) {
        ApollocanbusAccelRpt68 msg;
        if(obj.contains("manualinput"))
        {
            msg.manualinput = (obj["manualinput"].is_string()?atof(obj["manualinput"].get<std::string>().c_str()):obj["manualinput"].get<double>());
        }
        if(obj.contains("commandedvalue"))
        {
            msg.commandedvalue = (obj["commandedvalue"].is_string()?atof(obj["commandedvalue"].get<std::string>().c_str()):obj["commandedvalue"].get<double>());
        }
        if(obj.contains("outputvalue"))
        {
            msg.outputvalue = (obj["outputvalue"].is_string()?atof(obj["outputvalue"].get<std::string>().c_str()):obj["outputvalue"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusAccelRpt68 from_json<ApollocanbusAccelRpt68>(nlohmann::json obj){
        return from_json_ApollocanbusAccelRpt68(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAccelRpt68 &dt)
    {
        dt=from_json_ApollocanbusAccelRpt68(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAccelRpt68 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAccelRpt68 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
