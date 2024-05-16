#include "adapter/serialization/apollo_msgs/apollocanbus_accel_rpt200.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAccelRpt200 &msg) {
        nlohmann::json obj;
        obj["vehiclefault"] = (msg.vehiclefault);
        obj["pacmodfault"] = (msg.pacmodfault);
        obj["outputreportedfault"] = (msg.outputreportedfault);
        obj["inputoutputfault"] = (msg.inputoutputfault);
        obj["commandoutputfault"] = (msg.commandoutputfault);
        obj["overrideactive"] = (msg.overrideactive);
        obj["enabled"] = (msg.enabled);
        obj["manualinput"] = (msg.manualinput);
        obj["commandedvalue"] = (msg.commandedvalue);
        obj["outputvalue"] = (msg.outputvalue);
        return obj;
    }
    ApollocanbusAccelRpt200 from_json_ApollocanbusAccelRpt200 (nlohmann::json obj) {
        ApollocanbusAccelRpt200 msg;
        if(obj.contains("vehiclefault"))
        {
            msg.vehiclefault = (obj["vehiclefault"].is_string()?(bool)atoi(obj["vehiclefault"].get<std::string>().c_str()):obj["vehiclefault"].get<bool>());
        }
        if(obj.contains("pacmodfault"))
        {
            msg.pacmodfault = (obj["pacmodfault"].is_string()?(bool)atoi(obj["pacmodfault"].get<std::string>().c_str()):obj["pacmodfault"].get<bool>());
        }
        if(obj.contains("outputreportedfault"))
        {
            msg.outputreportedfault = (obj["outputreportedfault"].is_string()?(bool)atoi(obj["outputreportedfault"].get<std::string>().c_str()):obj["outputreportedfault"].get<bool>());
        }
        if(obj.contains("inputoutputfault"))
        {
            msg.inputoutputfault = (obj["inputoutputfault"].is_string()?(bool)atoi(obj["inputoutputfault"].get<std::string>().c_str()):obj["inputoutputfault"].get<bool>());
        }
        if(obj.contains("commandoutputfault"))
        {
            msg.commandoutputfault = (obj["commandoutputfault"].is_string()?(bool)atoi(obj["commandoutputfault"].get<std::string>().c_str()):obj["commandoutputfault"].get<bool>());
        }
        if(obj.contains("overrideactive"))
        {
            msg.overrideactive = (obj["overrideactive"].is_string()?(bool)atoi(obj["overrideactive"].get<std::string>().c_str()):obj["overrideactive"].get<bool>());
        }
        if(obj.contains("enabled"))
        {
            msg.enabled = (obj["enabled"].is_string()?(bool)atoi(obj["enabled"].get<std::string>().c_str()):obj["enabled"].get<bool>());
        }
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
    ApollocanbusAccelRpt200 from_json<ApollocanbusAccelRpt200>(nlohmann::json obj){
        return from_json_ApollocanbusAccelRpt200(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAccelRpt200 &dt)
    {
        dt=from_json_ApollocanbusAccelRpt200(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAccelRpt200 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAccelRpt200 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
