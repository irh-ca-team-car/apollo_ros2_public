#include "adapter/serialization/apollo_msgs/apollocanbus_hazard_lights_rpt214.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHazardLightsRpt214 &msg) {
        nlohmann::json obj;
        obj["outputvalue"] = (msg.outputvalue);
        obj["commandedvalue"] = (msg.commandedvalue);
        obj["manualinput"] = (msg.manualinput);
        obj["vehiclefault"] = (msg.vehiclefault);
        obj["pacmodfault"] = (msg.pacmodfault);
        obj["overrideactive"] = (msg.overrideactive);
        obj["outputreportedfault"] = (msg.outputreportedfault);
        obj["inputoutputfault"] = (msg.inputoutputfault);
        obj["enabled"] = (msg.enabled);
        obj["commandoutputfault"] = (msg.commandoutputfault);
        return obj;
    }
    ApollocanbusHazardLightsRpt214 from_json_ApollocanbusHazardLightsRpt214 (nlohmann::json obj) {
        ApollocanbusHazardLightsRpt214 msg;
        if(obj.contains("outputvalue"))
        {
            msg.outputvalue = (obj["outputvalue"].is_string()?(bool)atoi(obj["outputvalue"].get<std::string>().c_str()):obj["outputvalue"].get<bool>());
        }
        if(obj.contains("commandedvalue"))
        {
            msg.commandedvalue = (obj["commandedvalue"].is_string()?(bool)atoi(obj["commandedvalue"].get<std::string>().c_str()):obj["commandedvalue"].get<bool>());
        }
        if(obj.contains("manualinput"))
        {
            msg.manualinput = (obj["manualinput"].is_string()?(bool)atoi(obj["manualinput"].get<std::string>().c_str()):obj["manualinput"].get<bool>());
        }
        if(obj.contains("vehiclefault"))
        {
            msg.vehiclefault = (obj["vehiclefault"].is_string()?(bool)atoi(obj["vehiclefault"].get<std::string>().c_str()):obj["vehiclefault"].get<bool>());
        }
        if(obj.contains("pacmodfault"))
        {
            msg.pacmodfault = (obj["pacmodfault"].is_string()?(bool)atoi(obj["pacmodfault"].get<std::string>().c_str()):obj["pacmodfault"].get<bool>());
        }
        if(obj.contains("overrideactive"))
        {
            msg.overrideactive = (obj["overrideactive"].is_string()?(bool)atoi(obj["overrideactive"].get<std::string>().c_str()):obj["overrideactive"].get<bool>());
        }
        if(obj.contains("outputreportedfault"))
        {
            msg.outputreportedfault = (obj["outputreportedfault"].is_string()?(bool)atoi(obj["outputreportedfault"].get<std::string>().c_str()):obj["outputreportedfault"].get<bool>());
        }
        if(obj.contains("inputoutputfault"))
        {
            msg.inputoutputfault = (obj["inputoutputfault"].is_string()?(bool)atoi(obj["inputoutputfault"].get<std::string>().c_str()):obj["inputoutputfault"].get<bool>());
        }
        if(obj.contains("enabled"))
        {
            msg.enabled = (obj["enabled"].is_string()?(bool)atoi(obj["enabled"].get<std::string>().c_str()):obj["enabled"].get<bool>());
        }
        if(obj.contains("commandoutputfault"))
        {
            msg.commandoutputfault = (obj["commandoutputfault"].is_string()?(bool)atoi(obj["commandoutputfault"].get<std::string>().c_str()):obj["commandoutputfault"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusHazardLightsRpt214 from_json<ApollocanbusHazardLightsRpt214>(nlohmann::json obj){
        return from_json_ApollocanbusHazardLightsRpt214(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHazardLightsRpt214 &dt)
    {
        dt=from_json_ApollocanbusHazardLightsRpt214(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHazardLightsRpt214 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHazardLightsRpt214 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
