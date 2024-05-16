#include "adapter/serialization/apollo_msgs/apollocanbus_dash_controls_right_rpt210.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDashControlsRightRpt210 &msg) {
        nlohmann::json obj;
        obj["outputvalue"] = (msg.outputvalue);
        obj["commandedvalue"] = (msg.commandedvalue);
        obj["vehiclefault"] = (msg.vehiclefault);
        obj["pacmodfault"] = (msg.pacmodfault);
        obj["overrideactive"] = (msg.overrideactive);
        obj["outputreportedfault"] = (msg.outputreportedfault);
        obj["inputoutputfault"] = (msg.inputoutputfault);
        obj["enabled"] = (msg.enabled);
        obj["commandoutputfault"] = (msg.commandoutputfault);
        obj["manualinput"] = (msg.manualinput);
        return obj;
    }
    ApollocanbusDashControlsRightRpt210 from_json_ApollocanbusDashControlsRightRpt210 (nlohmann::json obj) {
        ApollocanbusDashControlsRightRpt210 msg;
        if(obj.contains("outputvalue"))
        {
            msg.outputvalue = (obj["outputvalue"].is_string()?atoi(obj["outputvalue"].get<std::string>().c_str()):obj["outputvalue"].get<int>());
        }
        if(obj.contains("commandedvalue"))
        {
            msg.commandedvalue = (obj["commandedvalue"].is_string()?atoi(obj["commandedvalue"].get<std::string>().c_str()):obj["commandedvalue"].get<int>());
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
        if(obj.contains("manualinput"))
        {
            msg.manualinput = (obj["manualinput"].is_string()?atoi(obj["manualinput"].get<std::string>().c_str()):obj["manualinput"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusDashControlsRightRpt210 from_json<ApollocanbusDashControlsRightRpt210>(nlohmann::json obj){
        return from_json_ApollocanbusDashControlsRightRpt210(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDashControlsRightRpt210 &dt)
    {
        dt=from_json_ApollocanbusDashControlsRightRpt210(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDashControlsRightRpt210 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDashControlsRightRpt210 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
