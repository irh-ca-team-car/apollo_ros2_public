#include "adapter/serialization/apollo_msgs/apollocanbus_safety.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSafety &msg) {
        nlohmann::json obj;
        obj["isdrivercardoorclose"] = (msg.isdrivercardoorclose);
        obj["isdriverbuckled"] = (msg.isdriverbuckled);
        obj["emergencybutton"] = (msg.emergencybutton);
        obj["haserror"] = (msg.haserror);
        obj["ismotorinvertorfault"] = (msg.ismotorinvertorfault);
        obj["issystemfault"] = (msg.issystemfault);
        obj["ispowerbatteryfault"] = (msg.ispowerbatteryfault);
        obj["ismotorinvertorovertemperature"] = (msg.ismotorinvertorovertemperature);
        obj["issmallbatterychargedischargefault"] = (msg.issmallbatterychargedischargefault);
        obj["drivingmode"] = (msg.drivingmode);
        obj["ispassengerdooropen"] = (msg.ispassengerdooropen);
        obj["isrearleftdooropen"] = (msg.isrearleftdooropen);
        obj["isrearrightdooropen"] = (msg.isrearrightdooropen);
        obj["ishoodopen"] = (msg.ishoodopen);
        obj["istrunkopen"] = (msg.istrunkopen);
        obj["ispassengerdetected"] = (msg.ispassengerdetected);
        obj["ispassengerairbagenabled"] = (msg.ispassengerairbagenabled);
        obj["ispassengerbuckled"] = (msg.ispassengerbuckled);
        obj["frontlefttirepress"] = (msg.frontlefttirepress);
        obj["frontrighttirepress"] = (msg.frontrighttirepress);
        obj["rearlefttirepress"] = (msg.rearlefttirepress);
        obj["rearrighttirepress"] = (msg.rearrighttirepress);
        obj["cardrivingmode"] = (msg.cardrivingmode);
        return obj;
    }
    ApollocanbusSafety from_json_ApollocanbusSafety (nlohmann::json obj) {
        ApollocanbusSafety msg;
        if(obj.contains("isdrivercardoorclose"))
        {
            msg.isdrivercardoorclose = (obj["isdrivercardoorclose"].is_string()?(bool)atoi(obj["isdrivercardoorclose"].get<std::string>().c_str()):obj["isdrivercardoorclose"].get<bool>());
        }
        if(obj.contains("isdriverbuckled"))
        {
            msg.isdriverbuckled = (obj["isdriverbuckled"].is_string()?(bool)atoi(obj["isdriverbuckled"].get<std::string>().c_str()):obj["isdriverbuckled"].get<bool>());
        }
        if(obj.contains("emergencybutton"))
        {
            msg.emergencybutton = (obj["emergencybutton"].is_string()?atoi(obj["emergencybutton"].get<std::string>().c_str()):obj["emergencybutton"].get<int>());
        }
        if(obj.contains("haserror"))
        {
            msg.haserror = (obj["haserror"].is_string()?(bool)atoi(obj["haserror"].get<std::string>().c_str()):obj["haserror"].get<bool>());
        }
        if(obj.contains("ismotorinvertorfault"))
        {
            msg.ismotorinvertorfault = (obj["ismotorinvertorfault"].is_string()?(bool)atoi(obj["ismotorinvertorfault"].get<std::string>().c_str()):obj["ismotorinvertorfault"].get<bool>());
        }
        if(obj.contains("issystemfault"))
        {
            msg.issystemfault = (obj["issystemfault"].is_string()?(bool)atoi(obj["issystemfault"].get<std::string>().c_str()):obj["issystemfault"].get<bool>());
        }
        if(obj.contains("ispowerbatteryfault"))
        {
            msg.ispowerbatteryfault = (obj["ispowerbatteryfault"].is_string()?(bool)atoi(obj["ispowerbatteryfault"].get<std::string>().c_str()):obj["ispowerbatteryfault"].get<bool>());
        }
        if(obj.contains("ismotorinvertorovertemperature"))
        {
            msg.ismotorinvertorovertemperature = (obj["ismotorinvertorovertemperature"].is_string()?(bool)atoi(obj["ismotorinvertorovertemperature"].get<std::string>().c_str()):obj["ismotorinvertorovertemperature"].get<bool>());
        }
        if(obj.contains("issmallbatterychargedischargefault"))
        {
            msg.issmallbatterychargedischargefault = (obj["issmallbatterychargedischargefault"].is_string()?(bool)atoi(obj["issmallbatterychargedischargefault"].get<std::string>().c_str()):obj["issmallbatterychargedischargefault"].get<bool>());
        }
        if(obj.contains("drivingmode"))
        {
            msg.drivingmode = (obj["drivingmode"].is_string()?atoi(obj["drivingmode"].get<std::string>().c_str()):obj["drivingmode"].get<int>());
        }
        if(obj.contains("ispassengerdooropen"))
        {
            msg.ispassengerdooropen = (obj["ispassengerdooropen"].is_string()?(bool)atoi(obj["ispassengerdooropen"].get<std::string>().c_str()):obj["ispassengerdooropen"].get<bool>());
        }
        if(obj.contains("isrearleftdooropen"))
        {
            msg.isrearleftdooropen = (obj["isrearleftdooropen"].is_string()?(bool)atoi(obj["isrearleftdooropen"].get<std::string>().c_str()):obj["isrearleftdooropen"].get<bool>());
        }
        if(obj.contains("isrearrightdooropen"))
        {
            msg.isrearrightdooropen = (obj["isrearrightdooropen"].is_string()?(bool)atoi(obj["isrearrightdooropen"].get<std::string>().c_str()):obj["isrearrightdooropen"].get<bool>());
        }
        if(obj.contains("ishoodopen"))
        {
            msg.ishoodopen = (obj["ishoodopen"].is_string()?(bool)atoi(obj["ishoodopen"].get<std::string>().c_str()):obj["ishoodopen"].get<bool>());
        }
        if(obj.contains("istrunkopen"))
        {
            msg.istrunkopen = (obj["istrunkopen"].is_string()?(bool)atoi(obj["istrunkopen"].get<std::string>().c_str()):obj["istrunkopen"].get<bool>());
        }
        if(obj.contains("ispassengerdetected"))
        {
            msg.ispassengerdetected = (obj["ispassengerdetected"].is_string()?(bool)atoi(obj["ispassengerdetected"].get<std::string>().c_str()):obj["ispassengerdetected"].get<bool>());
        }
        if(obj.contains("ispassengerairbagenabled"))
        {
            msg.ispassengerairbagenabled = (obj["ispassengerairbagenabled"].is_string()?(bool)atoi(obj["ispassengerairbagenabled"].get<std::string>().c_str()):obj["ispassengerairbagenabled"].get<bool>());
        }
        if(obj.contains("ispassengerbuckled"))
        {
            msg.ispassengerbuckled = (obj["ispassengerbuckled"].is_string()?(bool)atoi(obj["ispassengerbuckled"].get<std::string>().c_str()):obj["ispassengerbuckled"].get<bool>());
        }
        if(obj.contains("frontlefttirepress"))
        {
            msg.frontlefttirepress = (obj["frontlefttirepress"].is_string()?atoi(obj["frontlefttirepress"].get<std::string>().c_str()):obj["frontlefttirepress"].get<int>());
        }
        if(obj.contains("frontrighttirepress"))
        {
            msg.frontrighttirepress = (obj["frontrighttirepress"].is_string()?atoi(obj["frontrighttirepress"].get<std::string>().c_str()):obj["frontrighttirepress"].get<int>());
        }
        if(obj.contains("rearlefttirepress"))
        {
            msg.rearlefttirepress = (obj["rearlefttirepress"].is_string()?atoi(obj["rearlefttirepress"].get<std::string>().c_str()):obj["rearlefttirepress"].get<int>());
        }
        if(obj.contains("rearrighttirepress"))
        {
            msg.rearrighttirepress = (obj["rearrighttirepress"].is_string()?atoi(obj["rearrighttirepress"].get<std::string>().c_str()):obj["rearrighttirepress"].get<int>());
        }
        if(obj.contains("cardrivingmode"))
        {
            msg.cardrivingmode = (obj["cardrivingmode"].is_string()?atoi(obj["cardrivingmode"].get<std::string>().c_str()):obj["cardrivingmode"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusSafety from_json<ApollocanbusSafety>(nlohmann::json obj){
        return from_json_ApollocanbusSafety(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSafety &dt)
    {
        dt=from_json_ApollocanbusSafety(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSafety & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSafety & dt)
    {
        os << to_json(dt);
        return os;
    }
}
