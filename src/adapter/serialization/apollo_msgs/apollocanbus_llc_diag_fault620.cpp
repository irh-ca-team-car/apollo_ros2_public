#include "adapter/serialization/apollo_msgs/apollocanbus_llc_diag_fault620.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcDiagFault620 &msg) {
        nlohmann::json obj;
        obj["llcdisengagecounterbrake"] = (msg.llcdisengagecounterbrake);
        obj["llcdisengagecountersteer"] = (msg.llcdisengagecountersteer);
        obj["llcdisengagecounterthrottle"] = (msg.llcdisengagecounterthrottle);
        obj["llcfbkfaultcounter"] = (msg.llcfbkfaultcounter);
        obj["llcdisengagecounterbutton"] = (msg.llcdisengagecounterbutton);
        obj["llcfbkversionyear"] = (msg.llcfbkversionyear);
        obj["llcfbkversionmonth"] = (msg.llcfbkversionmonth);
        obj["llcfbkversionday"] = (msg.llcfbkversionday);
        obj["llcfbkversionhour"] = (msg.llcfbkversionhour);
        return obj;
    }
    ApollocanbusLlcDiagFault620 from_json_ApollocanbusLlcDiagFault620 (nlohmann::json obj) {
        ApollocanbusLlcDiagFault620 msg;
        if(obj.contains("llcdisengagecounterbrake"))
        {
            msg.llcdisengagecounterbrake = (obj["llcdisengagecounterbrake"].is_string()?atoi(obj["llcdisengagecounterbrake"].get<std::string>().c_str()):obj["llcdisengagecounterbrake"].get<int>());
        }
        if(obj.contains("llcdisengagecountersteer"))
        {
            msg.llcdisengagecountersteer = (obj["llcdisengagecountersteer"].is_string()?atoi(obj["llcdisengagecountersteer"].get<std::string>().c_str()):obj["llcdisengagecountersteer"].get<int>());
        }
        if(obj.contains("llcdisengagecounterthrottle"))
        {
            msg.llcdisengagecounterthrottle = (obj["llcdisengagecounterthrottle"].is_string()?atoi(obj["llcdisengagecounterthrottle"].get<std::string>().c_str()):obj["llcdisengagecounterthrottle"].get<int>());
        }
        if(obj.contains("llcfbkfaultcounter"))
        {
            msg.llcfbkfaultcounter = (obj["llcfbkfaultcounter"].is_string()?atoi(obj["llcfbkfaultcounter"].get<std::string>().c_str()):obj["llcfbkfaultcounter"].get<int>());
        }
        if(obj.contains("llcdisengagecounterbutton"))
        {
            msg.llcdisengagecounterbutton = (obj["llcdisengagecounterbutton"].is_string()?atoi(obj["llcdisengagecounterbutton"].get<std::string>().c_str()):obj["llcdisengagecounterbutton"].get<int>());
        }
        if(obj.contains("llcfbkversionyear"))
        {
            msg.llcfbkversionyear = (obj["llcfbkversionyear"].is_string()?atoi(obj["llcfbkversionyear"].get<std::string>().c_str()):obj["llcfbkversionyear"].get<int>());
        }
        if(obj.contains("llcfbkversionmonth"))
        {
            msg.llcfbkversionmonth = (obj["llcfbkversionmonth"].is_string()?atoi(obj["llcfbkversionmonth"].get<std::string>().c_str()):obj["llcfbkversionmonth"].get<int>());
        }
        if(obj.contains("llcfbkversionday"))
        {
            msg.llcfbkversionday = (obj["llcfbkversionday"].is_string()?atoi(obj["llcfbkversionday"].get<std::string>().c_str()):obj["llcfbkversionday"].get<int>());
        }
        if(obj.contains("llcfbkversionhour"))
        {
            msg.llcfbkversionhour = (obj["llcfbkversionhour"].is_string()?atoi(obj["llcfbkversionhour"].get<std::string>().c_str()):obj["llcfbkversionhour"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusLlcDiagFault620 from_json<ApollocanbusLlcDiagFault620>(nlohmann::json obj){
        return from_json_ApollocanbusLlcDiagFault620(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcDiagFault620 &dt)
    {
        dt=from_json_ApollocanbusLlcDiagFault620(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcDiagFault620 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcDiagFault620 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
