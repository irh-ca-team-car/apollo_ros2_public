#include "adapter/serialization/apollo_msgs/apollocanbus_eps.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEps &msg) {
        nlohmann::json obj;
        obj["isepsfail"] = (msg.isepsfail);
        obj["epscontrolstate"] = (msg.epscontrolstate);
        obj["epsdriverhandtorq"] = (msg.epsdriverhandtorq);
        obj["issteeringanglevalid"] = (msg.issteeringanglevalid);
        obj["steeringangle"] = (msg.steeringangle);
        obj["steeringanglespd"] = (msg.steeringanglespd);
        obj["istrimmingstatus"] = (msg.istrimmingstatus);
        obj["iscalibrationstatus"] = (msg.iscalibrationstatus);
        obj["isfailurestatus"] = (msg.isfailurestatus);
        obj["allowenterautonomousmode"] = (msg.allowenterautonomousmode);
        obj["currentdrivingmode"] = (msg.currentdrivingmode);
        obj["steeringanglecmd"] = (msg.steeringanglecmd);
        obj["vehiclespeed"] = (msg.vehiclespeed);
        obj["epastorque"] = (msg.epastorque);
        obj["steeringenabled"] = (msg.steeringenabled);
        obj["driveroverride"] = (msg.driveroverride);
        obj["driveractivity"] = (msg.driveractivity);
        obj["watchdogfault"] = (msg.watchdogfault);
        obj["channel1fault"] = (msg.channel1fault);
        obj["channel2fault"] = (msg.channel2fault);
        obj["calibrationfault"] = (msg.calibrationfault);
        obj["connectorfault"] = (msg.connectorfault);
        obj["timestamp65"] = (msg.timestamp65);
        obj["majorversion"] = (msg.majorversion);
        obj["minorversion"] = (msg.minorversion);
        obj["buildnumber"] = (msg.buildnumber);
        return obj;
    }
    ApollocanbusEps from_json_ApollocanbusEps (nlohmann::json obj) {
        ApollocanbusEps msg;
        if(obj.contains("isepsfail"))
        {
            msg.isepsfail = (obj["isepsfail"].is_string()?(bool)atoi(obj["isepsfail"].get<std::string>().c_str()):obj["isepsfail"].get<bool>());
        }
        if(obj.contains("epscontrolstate"))
        {
            msg.epscontrolstate = (obj["epscontrolstate"].is_string()?atoi(obj["epscontrolstate"].get<std::string>().c_str()):obj["epscontrolstate"].get<int>());
        }
        if(obj.contains("epsdriverhandtorq"))
        {
            msg.epsdriverhandtorq = (obj["epsdriverhandtorq"].is_string()?atof(obj["epsdriverhandtorq"].get<std::string>().c_str()):obj["epsdriverhandtorq"].get<double>());
        }
        if(obj.contains("issteeringanglevalid"))
        {
            msg.issteeringanglevalid = (obj["issteeringanglevalid"].is_string()?(bool)atoi(obj["issteeringanglevalid"].get<std::string>().c_str()):obj["issteeringanglevalid"].get<bool>());
        }
        if(obj.contains("steeringangle"))
        {
            msg.steeringangle = (obj["steeringangle"].is_string()?atof(obj["steeringangle"].get<std::string>().c_str()):obj["steeringangle"].get<double>());
        }
        if(obj.contains("steeringanglespd"))
        {
            msg.steeringanglespd = (obj["steeringanglespd"].is_string()?atof(obj["steeringanglespd"].get<std::string>().c_str()):obj["steeringanglespd"].get<double>());
        }
        if(obj.contains("istrimmingstatus"))
        {
            msg.istrimmingstatus = (obj["istrimmingstatus"].is_string()?(bool)atoi(obj["istrimmingstatus"].get<std::string>().c_str()):obj["istrimmingstatus"].get<bool>());
        }
        if(obj.contains("iscalibrationstatus"))
        {
            msg.iscalibrationstatus = (obj["iscalibrationstatus"].is_string()?(bool)atoi(obj["iscalibrationstatus"].get<std::string>().c_str()):obj["iscalibrationstatus"].get<bool>());
        }
        if(obj.contains("isfailurestatus"))
        {
            msg.isfailurestatus = (obj["isfailurestatus"].is_string()?(bool)atoi(obj["isfailurestatus"].get<std::string>().c_str()):obj["isfailurestatus"].get<bool>());
        }
        if(obj.contains("allowenterautonomousmode"))
        {
            msg.allowenterautonomousmode = (obj["allowenterautonomousmode"].is_string()?atoi(obj["allowenterautonomousmode"].get<std::string>().c_str()):obj["allowenterautonomousmode"].get<int>());
        }
        if(obj.contains("currentdrivingmode"))
        {
            msg.currentdrivingmode = (obj["currentdrivingmode"].is_string()?atoi(obj["currentdrivingmode"].get<std::string>().c_str()):obj["currentdrivingmode"].get<int>());
        }
        if(obj.contains("steeringanglecmd"))
        {
            msg.steeringanglecmd = (obj["steeringanglecmd"].is_string()?atof(obj["steeringanglecmd"].get<std::string>().c_str()):obj["steeringanglecmd"].get<double>());
        }
        if(obj.contains("vehiclespeed"))
        {
            msg.vehiclespeed = (obj["vehiclespeed"].is_string()?atof(obj["vehiclespeed"].get<std::string>().c_str()):obj["vehiclespeed"].get<double>());
        }
        if(obj.contains("epastorque"))
        {
            msg.epastorque = (obj["epastorque"].is_string()?atof(obj["epastorque"].get<std::string>().c_str()):obj["epastorque"].get<double>());
        }
        if(obj.contains("steeringenabled"))
        {
            msg.steeringenabled = (obj["steeringenabled"].is_string()?(bool)atoi(obj["steeringenabled"].get<std::string>().c_str()):obj["steeringenabled"].get<bool>());
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
        if(obj.contains("calibrationfault"))
        {
            msg.calibrationfault = (obj["calibrationfault"].is_string()?(bool)atoi(obj["calibrationfault"].get<std::string>().c_str()):obj["calibrationfault"].get<bool>());
        }
        if(obj.contains("connectorfault"))
        {
            msg.connectorfault = (obj["connectorfault"].is_string()?(bool)atoi(obj["connectorfault"].get<std::string>().c_str()):obj["connectorfault"].get<bool>());
        }
        if(obj.contains("timestamp65"))
        {
            msg.timestamp65 = (obj["timestamp65"].is_string()?atof(obj["timestamp65"].get<std::string>().c_str()):obj["timestamp65"].get<double>());
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
    ApollocanbusEps from_json<ApollocanbusEps>(nlohmann::json obj){
        return from_json_ApollocanbusEps(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEps &dt)
    {
        dt=from_json_ApollocanbusEps(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEps & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEps & dt)
    {
        os << to_json(dt);
        return os;
    }
}
