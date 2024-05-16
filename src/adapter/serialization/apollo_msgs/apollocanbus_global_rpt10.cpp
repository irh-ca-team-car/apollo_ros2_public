#include "adapter/serialization/apollo_msgs/apollocanbus_global_rpt10.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGlobalRpt10 &msg) {
        nlohmann::json obj;
        obj["configfaultactive"] = (msg.configfaultactive);
        obj["pacmodsubsystemtimeout"] = (msg.pacmodsubsystemtimeout);
        obj["pacmodsystemenabled"] = (msg.pacmodsystemenabled);
        obj["pacmodsystemoverrideactive"] = (msg.pacmodsystemoverrideactive);
        obj["pacmodsystemfaultactive"] = (msg.pacmodsystemfaultactive);
        obj["vehcantimeout"] = (msg.vehcantimeout);
        obj["strcantimeout"] = (msg.strcantimeout);
        obj["brkcantimeout"] = (msg.brkcantimeout);
        obj["usrcantimeout"] = (msg.usrcantimeout);
        obj["usrcanreaderrors"] = (msg.usrcanreaderrors);
        return obj;
    }
    ApollocanbusGlobalRpt10 from_json_ApollocanbusGlobalRpt10 (nlohmann::json obj) {
        ApollocanbusGlobalRpt10 msg;
        if(obj.contains("configfaultactive"))
        {
            msg.configfaultactive = (obj["configfaultactive"].is_string()?(bool)atoi(obj["configfaultactive"].get<std::string>().c_str()):obj["configfaultactive"].get<bool>());
        }
        if(obj.contains("pacmodsubsystemtimeout"))
        {
            msg.pacmodsubsystemtimeout = (obj["pacmodsubsystemtimeout"].is_string()?(bool)atoi(obj["pacmodsubsystemtimeout"].get<std::string>().c_str()):obj["pacmodsubsystemtimeout"].get<bool>());
        }
        if(obj.contains("pacmodsystemenabled"))
        {
            msg.pacmodsystemenabled = (obj["pacmodsystemenabled"].is_string()?atoi(obj["pacmodsystemenabled"].get<std::string>().c_str()):obj["pacmodsystemenabled"].get<int>());
        }
        if(obj.contains("pacmodsystemoverrideactive"))
        {
            msg.pacmodsystemoverrideactive = (obj["pacmodsystemoverrideactive"].is_string()?atoi(obj["pacmodsystemoverrideactive"].get<std::string>().c_str()):obj["pacmodsystemoverrideactive"].get<int>());
        }
        if(obj.contains("pacmodsystemfaultactive"))
        {
            msg.pacmodsystemfaultactive = (obj["pacmodsystemfaultactive"].is_string()?(bool)atoi(obj["pacmodsystemfaultactive"].get<std::string>().c_str()):obj["pacmodsystemfaultactive"].get<bool>());
        }
        if(obj.contains("vehcantimeout"))
        {
            msg.vehcantimeout = (obj["vehcantimeout"].is_string()?(bool)atoi(obj["vehcantimeout"].get<std::string>().c_str()):obj["vehcantimeout"].get<bool>());
        }
        if(obj.contains("strcantimeout"))
        {
            msg.strcantimeout = (obj["strcantimeout"].is_string()?(bool)atoi(obj["strcantimeout"].get<std::string>().c_str()):obj["strcantimeout"].get<bool>());
        }
        if(obj.contains("brkcantimeout"))
        {
            msg.brkcantimeout = (obj["brkcantimeout"].is_string()?atoi(obj["brkcantimeout"].get<std::string>().c_str()):obj["brkcantimeout"].get<int>());
        }
        if(obj.contains("usrcantimeout"))
        {
            msg.usrcantimeout = (obj["usrcantimeout"].is_string()?(bool)atoi(obj["usrcantimeout"].get<std::string>().c_str()):obj["usrcantimeout"].get<bool>());
        }
        if(obj.contains("usrcanreaderrors"))
        {
            msg.usrcanreaderrors = (obj["usrcanreaderrors"].is_string()?atoi(obj["usrcanreaderrors"].get<std::string>().c_str()):obj["usrcanreaderrors"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusGlobalRpt10 from_json<ApollocanbusGlobalRpt10>(nlohmann::json obj){
        return from_json_ApollocanbusGlobalRpt10(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGlobalRpt10 &dt)
    {
        dt=from_json_ApollocanbusGlobalRpt10(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGlobalRpt10 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGlobalRpt10 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
