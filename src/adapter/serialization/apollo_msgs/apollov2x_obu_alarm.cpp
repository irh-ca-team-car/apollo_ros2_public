#include "adapter/serialization/apollo_msgs/apollov2x_obu_alarm.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xObuAlarm &msg) {
        nlohmann::json obj;
        obj["modenum"] = (msg.modenum);
        obj["errornum"] = (msg.errornum);
        obj["errormsg"] = (msg.errormsg);
        return obj;
    }
    Apollov2xObuAlarm from_json_Apollov2xObuAlarm (nlohmann::json obj) {
        Apollov2xObuAlarm msg;
        if(obj.contains("modenum"))
        {
            msg.modenum = (obj["modenum"].is_string()?atof(obj["modenum"].get<std::string>().c_str()):obj["modenum"].get<double>());
        }
        if(obj.contains("errornum"))
        {
            msg.errornum = (obj["errornum"].is_string()?atoi(obj["errornum"].get<std::string>().c_str()):obj["errornum"].get<int>());
        }
        if(obj.contains("errormsg"))
        {
            msg.errormsg = (obj["errormsg"].is_string()?(obj["errormsg"].get<std::string>().c_str()):obj["errormsg"].get<std::string>());
        }
        return msg;
    }
    template <>
    Apollov2xObuAlarm from_json<Apollov2xObuAlarm>(nlohmann::json obj){
        return from_json_Apollov2xObuAlarm(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xObuAlarm &dt)
    {
        dt=from_json_Apollov2xObuAlarm(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xObuAlarm & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xObuAlarm & dt)
    {
        os << to_json(dt);
        return os;
    }
}
