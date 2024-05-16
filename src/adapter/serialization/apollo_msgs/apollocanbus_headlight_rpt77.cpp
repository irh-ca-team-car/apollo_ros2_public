#include "adapter/serialization/apollo_msgs/apollocanbus_headlight_rpt77.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHeadlightRpt77 &msg) {
        nlohmann::json obj;
        obj["outputvalue"] = (msg.outputvalue);
        obj["manualinput"] = (msg.manualinput);
        obj["commandedvalue"] = (msg.commandedvalue);
        return obj;
    }
    ApollocanbusHeadlightRpt77 from_json_ApollocanbusHeadlightRpt77 (nlohmann::json obj) {
        ApollocanbusHeadlightRpt77 msg;
        if(obj.contains("outputvalue"))
        {
            msg.outputvalue = (obj["outputvalue"].is_string()?atoi(obj["outputvalue"].get<std::string>().c_str()):obj["outputvalue"].get<int>());
        }
        if(obj.contains("manualinput"))
        {
            msg.manualinput = (obj["manualinput"].is_string()?atoi(obj["manualinput"].get<std::string>().c_str()):obj["manualinput"].get<int>());
        }
        if(obj.contains("commandedvalue"))
        {
            msg.commandedvalue = (obj["commandedvalue"].is_string()?atoi(obj["commandedvalue"].get<std::string>().c_str()):obj["commandedvalue"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusHeadlightRpt77 from_json<ApollocanbusHeadlightRpt77>(nlohmann::json obj){
        return from_json_ApollocanbusHeadlightRpt77(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHeadlightRpt77 &dt)
    {
        dt=from_json_ApollocanbusHeadlightRpt77(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHeadlightRpt77 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHeadlightRpt77 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
