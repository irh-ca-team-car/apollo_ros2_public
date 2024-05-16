#include "adapter/serialization/apollo_msgs/apollocanbus_brake.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrake &msg) {
        nlohmann::json obj;
        obj["isbrakepedalpressed"] = (msg.isbrakepedalpressed);
        obj["isbrakeforceexist"] = (msg.isbrakeforceexist);
        obj["isbrakeoverheat"] = (msg.isbrakeoverheat);
        obj["ishandbrakeon"] = (msg.ishandbrakeon);
        obj["brakepedalposition"] = (msg.brakepedalposition);
        obj["isbrakevalid"] = (msg.isbrakevalid);
        obj["brakeinput"] = (msg.brakeinput);
        obj["brakecmd"] = (msg.brakecmd);
        obj["brakeoutput"] = (msg.brakeoutput);
        obj["booinput"] = (msg.booinput);
        obj["boocmd"] = (msg.boocmd);
        obj["boooutput"] = (msg.boooutput);
        obj["watchdogapplyingbrakes"] = (msg.watchdogapplyingbrakes);
        obj["watchdogsource"] = (msg.watchdogsource);
        obj["brakeenabled"] = (msg.brakeenabled);
        obj["driveroverride"] = (msg.driveroverride);
        obj["driveractivity"] = (msg.driveractivity);
        obj["watchdogfault"] = (msg.watchdogfault);
        obj["channel1fault"] = (msg.channel1fault);
        obj["channel2fault"] = (msg.channel2fault);
        obj["boofault"] = (msg.boofault);
        obj["connectorfault"] = (msg.connectorfault);
        obj["braketorquereq"] = (msg.braketorquereq);
        obj["hsastatus"] = (msg.hsastatus);
        obj["braketorqueact"] = (msg.braketorqueact);
        obj["hsamode"] = (msg.hsamode);
        obj["wheeltorqueact"] = (msg.wheeltorqueact);
        obj["majorversion"] = (msg.majorversion);
        obj["minorversion"] = (msg.minorversion);
        obj["buildnumber"] = (msg.buildnumber);
        return obj;
    }
    ApollocanbusBrake from_json_ApollocanbusBrake (nlohmann::json obj) {
        ApollocanbusBrake msg;
        if(obj.contains("isbrakepedalpressed"))
        {
            msg.isbrakepedalpressed = (obj["isbrakepedalpressed"].is_string()?(bool)atoi(obj["isbrakepedalpressed"].get<std::string>().c_str()):obj["isbrakepedalpressed"].get<bool>());
        }
        if(obj.contains("isbrakeforceexist"))
        {
            msg.isbrakeforceexist = (obj["isbrakeforceexist"].is_string()?(bool)atoi(obj["isbrakeforceexist"].get<std::string>().c_str()):obj["isbrakeforceexist"].get<bool>());
        }
        if(obj.contains("isbrakeoverheat"))
        {
            msg.isbrakeoverheat = (obj["isbrakeoverheat"].is_string()?(bool)atoi(obj["isbrakeoverheat"].get<std::string>().c_str()):obj["isbrakeoverheat"].get<bool>());
        }
        if(obj.contains("ishandbrakeon"))
        {
            msg.ishandbrakeon = (obj["ishandbrakeon"].is_string()?(bool)atoi(obj["ishandbrakeon"].get<std::string>().c_str()):obj["ishandbrakeon"].get<bool>());
        }
        if(obj.contains("brakepedalposition"))
        {
            msg.brakepedalposition = (obj["brakepedalposition"].is_string()?atof(obj["brakepedalposition"].get<std::string>().c_str()):obj["brakepedalposition"].get<double>());
        }
        if(obj.contains("isbrakevalid"))
        {
            msg.isbrakevalid = (obj["isbrakevalid"].is_string()?(bool)atoi(obj["isbrakevalid"].get<std::string>().c_str()):obj["isbrakevalid"].get<bool>());
        }
        if(obj.contains("brakeinput"))
        {
            msg.brakeinput = (obj["brakeinput"].is_string()?atof(obj["brakeinput"].get<std::string>().c_str()):obj["brakeinput"].get<double>());
        }
        if(obj.contains("brakecmd"))
        {
            msg.brakecmd = (obj["brakecmd"].is_string()?atof(obj["brakecmd"].get<std::string>().c_str()):obj["brakecmd"].get<double>());
        }
        if(obj.contains("brakeoutput"))
        {
            msg.brakeoutput = (obj["brakeoutput"].is_string()?atof(obj["brakeoutput"].get<std::string>().c_str()):obj["brakeoutput"].get<double>());
        }
        if(obj.contains("booinput"))
        {
            msg.booinput = (obj["booinput"].is_string()?(bool)atoi(obj["booinput"].get<std::string>().c_str()):obj["booinput"].get<bool>());
        }
        if(obj.contains("boocmd"))
        {
            msg.boocmd = (obj["boocmd"].is_string()?(bool)atoi(obj["boocmd"].get<std::string>().c_str()):obj["boocmd"].get<bool>());
        }
        if(obj.contains("boooutput"))
        {
            msg.boooutput = (obj["boooutput"].is_string()?(bool)atoi(obj["boooutput"].get<std::string>().c_str()):obj["boooutput"].get<bool>());
        }
        if(obj.contains("watchdogapplyingbrakes"))
        {
            msg.watchdogapplyingbrakes = (obj["watchdogapplyingbrakes"].is_string()?(bool)atoi(obj["watchdogapplyingbrakes"].get<std::string>().c_str()):obj["watchdogapplyingbrakes"].get<bool>());
        }
        if(obj.contains("watchdogsource"))
        {
            msg.watchdogsource = (obj["watchdogsource"].is_string()?atoi(obj["watchdogsource"].get<std::string>().c_str()):obj["watchdogsource"].get<int>());
        }
        if(obj.contains("brakeenabled"))
        {
            msg.brakeenabled = (obj["brakeenabled"].is_string()?(bool)atoi(obj["brakeenabled"].get<std::string>().c_str()):obj["brakeenabled"].get<bool>());
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
        if(obj.contains("boofault"))
        {
            msg.boofault = (obj["boofault"].is_string()?(bool)atoi(obj["boofault"].get<std::string>().c_str()):obj["boofault"].get<bool>());
        }
        if(obj.contains("connectorfault"))
        {
            msg.connectorfault = (obj["connectorfault"].is_string()?(bool)atoi(obj["connectorfault"].get<std::string>().c_str()):obj["connectorfault"].get<bool>());
        }
        if(obj.contains("braketorquereq"))
        {
            msg.braketorquereq = (obj["braketorquereq"].is_string()?atof(obj["braketorquereq"].get<std::string>().c_str()):obj["braketorquereq"].get<double>());
        }
        if(obj.contains("hsastatus"))
        {
            msg.hsastatus = (obj["hsastatus"].is_string()?atoi(obj["hsastatus"].get<std::string>().c_str()):obj["hsastatus"].get<int>());
        }
        if(obj.contains("braketorqueact"))
        {
            msg.braketorqueact = (obj["braketorqueact"].is_string()?atof(obj["braketorqueact"].get<std::string>().c_str()):obj["braketorqueact"].get<double>());
        }
        if(obj.contains("hsamode"))
        {
            msg.hsamode = (obj["hsamode"].is_string()?atoi(obj["hsamode"].get<std::string>().c_str()):obj["hsamode"].get<int>());
        }
        if(obj.contains("wheeltorqueact"))
        {
            msg.wheeltorqueact = (obj["wheeltorqueact"].is_string()?atof(obj["wheeltorqueact"].get<std::string>().c_str()):obj["wheeltorqueact"].get<double>());
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
    ApollocanbusBrake from_json<ApollocanbusBrake>(nlohmann::json obj){
        return from_json_ApollocanbusBrake(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrake &dt)
    {
        dt=from_json_ApollocanbusBrake(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrake & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrake & dt)
    {
        os << to_json(dt);
        return os;
    }
}
