#include "adapter/serialization/apollo_msgs/apollocanbus_global_rpt6a.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGlobalRpt6a &msg) {
        nlohmann::json obj;
        obj["pacmodstatus"] = (msg.pacmodstatus);
        obj["overridestatus"] = (msg.overridestatus);
        obj["vehcantimeout"] = (msg.vehcantimeout);
        obj["strcantimeout"] = (msg.strcantimeout);
        obj["brkcantimeout"] = (msg.brkcantimeout);
        obj["usrcantimeout"] = (msg.usrcantimeout);
        obj["usrcanreaderrors"] = (msg.usrcanreaderrors);
        return obj;
    }
    ApollocanbusGlobalRpt6a from_json_ApollocanbusGlobalRpt6a (nlohmann::json obj) {
        ApollocanbusGlobalRpt6a msg;
        if(obj.contains("pacmodstatus"))
        {
            msg.pacmodstatus = (obj["pacmodstatus"].is_string()?atoi(obj["pacmodstatus"].get<std::string>().c_str()):obj["pacmodstatus"].get<int>());
        }
        if(obj.contains("overridestatus"))
        {
            msg.overridestatus = (obj["overridestatus"].is_string()?atoi(obj["overridestatus"].get<std::string>().c_str()):obj["overridestatus"].get<int>());
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
    ApollocanbusGlobalRpt6a from_json<ApollocanbusGlobalRpt6a>(nlohmann::json obj){
        return from_json_ApollocanbusGlobalRpt6a(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGlobalRpt6a &dt)
    {
        dt=from_json_ApollocanbusGlobalRpt6a(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGlobalRpt6a & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGlobalRpt6a & dt)
    {
        os << to_json(dt);
        return os;
    }
}
