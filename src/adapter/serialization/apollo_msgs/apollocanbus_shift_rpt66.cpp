#include "adapter/serialization/apollo_msgs/apollocanbus_shift_rpt66.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusShiftRpt66 &msg) {
        nlohmann::json obj;
        obj["manualinput"] = (msg.manualinput);
        obj["commandedvalue"] = (msg.commandedvalue);
        obj["outputvalue"] = (msg.outputvalue);
        return obj;
    }
    ApollocanbusShiftRpt66 from_json_ApollocanbusShiftRpt66 (nlohmann::json obj) {
        ApollocanbusShiftRpt66 msg;
        if(obj.contains("manualinput"))
        {
            msg.manualinput = (obj["manualinput"].is_string()?atoi(obj["manualinput"].get<std::string>().c_str()):obj["manualinput"].get<int>());
        }
        if(obj.contains("commandedvalue"))
        {
            msg.commandedvalue = (obj["commandedvalue"].is_string()?atoi(obj["commandedvalue"].get<std::string>().c_str()):obj["commandedvalue"].get<int>());
        }
        if(obj.contains("outputvalue"))
        {
            msg.outputvalue = (obj["outputvalue"].is_string()?atoi(obj["outputvalue"].get<std::string>().c_str()):obj["outputvalue"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusShiftRpt66 from_json<ApollocanbusShiftRpt66>(nlohmann::json obj){
        return from_json_ApollocanbusShiftRpt66(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusShiftRpt66 &dt)
    {
        dt=from_json_ApollocanbusShiftRpt66(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusShiftRpt66 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusShiftRpt66 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
