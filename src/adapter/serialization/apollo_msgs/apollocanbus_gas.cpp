#include "adapter/serialization/apollo_msgs/apollocanbus_gas.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGas &msg) {
        nlohmann::json obj;
        obj["isgaspedalerror"] = (msg.isgaspedalerror);
        obj["isgaspedalpressedmore"] = (msg.isgaspedalpressedmore);
        obj["gaspedalposition"] = (msg.gaspedalposition);
        obj["isgasvalid"] = (msg.isgasvalid);
        obj["throttleinput"] = (msg.throttleinput);
        obj["throttlecmd"] = (msg.throttlecmd);
        obj["throttleoutput"] = (msg.throttleoutput);
        obj["watchdogsource"] = (msg.watchdogsource);
        obj["throttleenabled"] = (msg.throttleenabled);
        obj["driveroverride"] = (msg.driveroverride);
        obj["driveractivity"] = (msg.driveractivity);
        obj["watchdogfault"] = (msg.watchdogfault);
        obj["channel1fault"] = (msg.channel1fault);
        obj["channel2fault"] = (msg.channel2fault);
        obj["connectorfault"] = (msg.connectorfault);
        obj["acceleratorpedal"] = (msg.acceleratorpedal);
        obj["acceleratorpedalrate"] = (msg.acceleratorpedalrate);
        obj["majorversion"] = (msg.majorversion);
        obj["minorversion"] = (msg.minorversion);
        obj["buildnumber"] = (msg.buildnumber);
        return obj;
    }
    ApollocanbusGas from_json_ApollocanbusGas (nlohmann::json obj) {
        ApollocanbusGas msg;
        if(obj.contains("isgaspedalerror"))
        {
            msg.isgaspedalerror = (obj["isgaspedalerror"].is_string()?(bool)atoi(obj["isgaspedalerror"].get<std::string>().c_str()):obj["isgaspedalerror"].get<bool>());
        }
        if(obj.contains("isgaspedalpressedmore"))
        {
            msg.isgaspedalpressedmore = (obj["isgaspedalpressedmore"].is_string()?(bool)atoi(obj["isgaspedalpressedmore"].get<std::string>().c_str()):obj["isgaspedalpressedmore"].get<bool>());
        }
        if(obj.contains("gaspedalposition"))
        {
            msg.gaspedalposition = (obj["gaspedalposition"].is_string()?atof(obj["gaspedalposition"].get<std::string>().c_str()):obj["gaspedalposition"].get<double>());
        }
        if(obj.contains("isgasvalid"))
        {
            msg.isgasvalid = (obj["isgasvalid"].is_string()?(bool)atoi(obj["isgasvalid"].get<std::string>().c_str()):obj["isgasvalid"].get<bool>());
        }
        if(obj.contains("throttleinput"))
        {
            msg.throttleinput = (obj["throttleinput"].is_string()?atof(obj["throttleinput"].get<std::string>().c_str()):obj["throttleinput"].get<double>());
        }
        if(obj.contains("throttlecmd"))
        {
            msg.throttlecmd = (obj["throttlecmd"].is_string()?atof(obj["throttlecmd"].get<std::string>().c_str()):obj["throttlecmd"].get<double>());
        }
        if(obj.contains("throttleoutput"))
        {
            msg.throttleoutput = (obj["throttleoutput"].is_string()?atof(obj["throttleoutput"].get<std::string>().c_str()):obj["throttleoutput"].get<double>());
        }
        if(obj.contains("watchdogsource"))
        {
            msg.watchdogsource = (obj["watchdogsource"].is_string()?atoi(obj["watchdogsource"].get<std::string>().c_str()):obj["watchdogsource"].get<int>());
        }
        if(obj.contains("throttleenabled"))
        {
            msg.throttleenabled = (obj["throttleenabled"].is_string()?(bool)atoi(obj["throttleenabled"].get<std::string>().c_str()):obj["throttleenabled"].get<bool>());
        }
        if(obj.contains("driveroverride"))
        {
            msg.driveroverride = (obj["driveroverride"].is_string()?(bool)atoi(obj["driveroverride"].get<std::string>().c_str()):obj["driveroverride"].get<bool>());
        }
        if(obj.contains("driveractivity"))
        {
            msg.driveractivity = (obj["driveractivity"].is_string()?(bool)atoi(obj["driveractivity"].get<std::string>().c_str()):obj["driveractivity"].get<bool>());
        }
        if(obj.contains("watchdogfault"))
        {
            msg.watchdogfault = (obj["watchdogfault"].is_string()?(bool)atoi(obj["watchdogfault"].get<std::string>().c_str()):obj["watchdogfault"].get<bool>());
        }
        if(obj.contains("channel1fault"))
        {
            msg.channel1fault = (obj["channel1fault"].is_string()?(bool)atoi(obj["channel1fault"].get<std::string>().c_str()):obj["channel1fault"].get<bool>());
        }
        if(obj.contains("channel2fault"))
        {
            msg.channel2fault = (obj["channel2fault"].is_string()?(bool)atoi(obj["channel2fault"].get<std::string>().c_str()):obj["channel2fault"].get<bool>());
        }
        if(obj.contains("connectorfault"))
        {
            msg.connectorfault = (obj["connectorfault"].is_string()?(bool)atoi(obj["connectorfault"].get<std::string>().c_str()):obj["connectorfault"].get<bool>());
        }
        if(obj.contains("acceleratorpedal"))
        {
            msg.acceleratorpedal = (obj["acceleratorpedal"].is_string()?atof(obj["acceleratorpedal"].get<std::string>().c_str()):obj["acceleratorpedal"].get<double>());
        }
        if(obj.contains("acceleratorpedalrate"))
        {
            msg.acceleratorpedalrate = (obj["acceleratorpedalrate"].is_string()?atof(obj["acceleratorpedalrate"].get<std::string>().c_str()):obj["acceleratorpedalrate"].get<double>());
        }
        if(obj.contains("majorversion"))
        {
            msg.majorversion = (obj["majorversion"].is_string()?atoi(obj["majorversion"].get<std::string>().c_str()):obj["majorversion"].get<int>());
        }
        if(obj.contains("minorversion"))
        {
            msg.minorversion = (obj["minorversion"].is_string()?atoi(obj["minorversion"].get<std::string>().c_str()):obj["minorversion"].get<int>());
        }
        if(obj.contains("buildnumber"))
        {
            msg.buildnumber = (obj["buildnumber"].is_string()?atoi(obj["buildnumber"].get<std::string>().c_str()):obj["buildnumber"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusGas from_json<ApollocanbusGas>(nlohmann::json obj){
        return from_json_ApollocanbusGas(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGas &dt)
    {
        dt=from_json_ApollocanbusGas(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGas & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGas & dt)
    {
        os << to_json(dt);
        return os;
    }
}
