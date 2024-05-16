#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_vehicle_status_report101.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuVehicleStatusReport101 &msg) {
        nlohmann::json obj;
        obj["driveenableresp"] = (msg.driveenableresp);
        obj["vcuhighvoltagecircuitstate"] = (msg.vcuhighvoltagecircuitstate);
        obj["vcudcdcenabledstates"] = (msg.vcudcdcenabledstates);
        obj["controlmoderesp"] = (msg.controlmoderesp);
        obj["vcuvehiclespeed"] = (msg.vcuvehiclespeed);
        obj["vculowbatterychargingfunctionst"] = (msg.vculowbatterychargingfunctionst);
        obj["vcudisplaysoc"] = (msg.vcudisplaysoc);
        obj["vcumotorspeed"] = (msg.vcumotorspeed);
        obj["vcumotordirection"] = (msg.vcumotordirection);
        obj["vcumotorspeedvalid"] = (msg.vcumotorspeedvalid);
        obj["vcustatusreptalivecounter"] = (msg.vcustatusreptalivecounter);
        obj["vcustatusreptchecksum"] = (msg.vcustatusreptchecksum);
        return obj;
    }
    ApollocanbusVcuVehicleStatusReport101 from_json_ApollocanbusVcuVehicleStatusReport101 (nlohmann::json obj) {
        ApollocanbusVcuVehicleStatusReport101 msg;
        if(obj.contains("driveenableresp"))
        {
            msg.driveenableresp = (obj["driveenableresp"].is_string()?(bool)atoi(obj["driveenableresp"].get<std::string>().c_str()):obj["driveenableresp"].get<bool>());
        }
        if(obj.contains("vcuhighvoltagecircuitstate"))
        {
            msg.vcuhighvoltagecircuitstate = (obj["vcuhighvoltagecircuitstate"].is_string()?(bool)atoi(obj["vcuhighvoltagecircuitstate"].get<std::string>().c_str()):obj["vcuhighvoltagecircuitstate"].get<bool>());
        }
        if(obj.contains("vcudcdcenabledstates"))
        {
            msg.vcudcdcenabledstates = (obj["vcudcdcenabledstates"].is_string()?(bool)atoi(obj["vcudcdcenabledstates"].get<std::string>().c_str()):obj["vcudcdcenabledstates"].get<bool>());
        }
        if(obj.contains("controlmoderesp"))
        {
            msg.controlmoderesp = (obj["controlmoderesp"].is_string()?atoi(obj["controlmoderesp"].get<std::string>().c_str()):obj["controlmoderesp"].get<int>());
        }
        if(obj.contains("vcuvehiclespeed"))
        {
            msg.vcuvehiclespeed = (obj["vcuvehiclespeed"].is_string()?atof(obj["vcuvehiclespeed"].get<std::string>().c_str()):obj["vcuvehiclespeed"].get<double>());
        }
        if(obj.contains("vculowbatterychargingfunctionst"))
        {
            msg.vculowbatterychargingfunctionst = (obj["vculowbatterychargingfunctionst"].is_string()?atoi(obj["vculowbatterychargingfunctionst"].get<std::string>().c_str()):obj["vculowbatterychargingfunctionst"].get<int>());
        }
        if(obj.contains("vcudisplaysoc"))
        {
            msg.vcudisplaysoc = (obj["vcudisplaysoc"].is_string()?atoi(obj["vcudisplaysoc"].get<std::string>().c_str()):obj["vcudisplaysoc"].get<int>());
        }
        if(obj.contains("vcumotorspeed"))
        {
            msg.vcumotorspeed = (obj["vcumotorspeed"].is_string()?atof(obj["vcumotorspeed"].get<std::string>().c_str()):obj["vcumotorspeed"].get<double>());
        }
        if(obj.contains("vcumotordirection"))
        {
            msg.vcumotordirection = (obj["vcumotordirection"].is_string()?atoi(obj["vcumotordirection"].get<std::string>().c_str()):obj["vcumotordirection"].get<int>());
        }
        if(obj.contains("vcumotorspeedvalid"))
        {
            msg.vcumotorspeedvalid = (obj["vcumotorspeedvalid"].is_string()?(bool)atoi(obj["vcumotorspeedvalid"].get<std::string>().c_str()):obj["vcumotorspeedvalid"].get<bool>());
        }
        if(obj.contains("vcustatusreptalivecounter"))
        {
            msg.vcustatusreptalivecounter = (obj["vcustatusreptalivecounter"].is_string()?atoi(obj["vcustatusreptalivecounter"].get<std::string>().c_str()):obj["vcustatusreptalivecounter"].get<int>());
        }
        if(obj.contains("vcustatusreptchecksum"))
        {
            msg.vcustatusreptchecksum = (obj["vcustatusreptchecksum"].is_string()?atoi(obj["vcustatusreptchecksum"].get<std::string>().c_str()):obj["vcustatusreptchecksum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVcuVehicleStatusReport101 from_json<ApollocanbusVcuVehicleStatusReport101>(nlohmann::json obj){
        return from_json_ApollocanbusVcuVehicleStatusReport101(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuVehicleStatusReport101 &dt)
    {
        dt=from_json_ApollocanbusVcuVehicleStatusReport101(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuVehicleStatusReport101 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuVehicleStatusReport101 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
