#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_vehicle_fault_response201.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuVehicleFaultResponse201 &msg) {
        nlohmann::json obj;
        obj["vehicleerrorindicationsvcu"] = (msg.vehicleerrorindicationsvcu);
        obj["brakesystemerrorehb"] = (msg.brakesystemerrorehb);
        obj["epserror"] = (msg.epserror);
        obj["motorerror"] = (msg.motorerror);
        obj["epberror"] = (msg.epberror);
        obj["highvoltagebatteryerrorbcu"] = (msg.highvoltagebatteryerrorbcu);
        obj["automodeexitreasonlosscommuni"] = (msg.automodeexitreasonlosscommuni);
        obj["automodeexitreasonreqsignalno"] = (msg.automodeexitreasonreqsignalno);
        obj["automodeexitreasonlowpower"] = (msg.automodeexitreasonlowpower);
        obj["automodeexitreasonhighvolt"] = (msg.automodeexitreasonhighvolt);
        obj["automodeexitreasonvehicleflt"] = (msg.automodeexitreasonvehicleflt);
        obj["automodeexitreasonpressemerg"] = (msg.automodeexitreasonpressemerg);
        obj["automodeexitreasonpressremot"] = (msg.automodeexitreasonpressremot);
        obj["automodeexitreasonpducontrol"] = (msg.automodeexitreasonpducontrol);
        obj["vcufaultreptalivecounter"] = (msg.vcufaultreptalivecounter);
        obj["vcufaultreptchecksum"] = (msg.vcufaultreptchecksum);
        return obj;
    }
    ApollocanbusVcuVehicleFaultResponse201 from_json_ApollocanbusVcuVehicleFaultResponse201 (nlohmann::json obj) {
        ApollocanbusVcuVehicleFaultResponse201 msg;
        if(obj.contains("vehicleerrorindicationsvcu"))
        {
            msg.vehicleerrorindicationsvcu = (obj["vehicleerrorindicationsvcu"].is_string()?atoi(obj["vehicleerrorindicationsvcu"].get<std::string>().c_str()):obj["vehicleerrorindicationsvcu"].get<int>());
        }
        if(obj.contains("brakesystemerrorehb"))
        {
            msg.brakesystemerrorehb = (obj["brakesystemerrorehb"].is_string()?atoi(obj["brakesystemerrorehb"].get<std::string>().c_str()):obj["brakesystemerrorehb"].get<int>());
        }
        if(obj.contains("epserror"))
        {
            msg.epserror = (obj["epserror"].is_string()?atoi(obj["epserror"].get<std::string>().c_str()):obj["epserror"].get<int>());
        }
        if(obj.contains("motorerror"))
        {
            msg.motorerror = (obj["motorerror"].is_string()?atoi(obj["motorerror"].get<std::string>().c_str()):obj["motorerror"].get<int>());
        }
        if(obj.contains("epberror"))
        {
            msg.epberror = (obj["epberror"].is_string()?atoi(obj["epberror"].get<std::string>().c_str()):obj["epberror"].get<int>());
        }
        if(obj.contains("highvoltagebatteryerrorbcu"))
        {
            msg.highvoltagebatteryerrorbcu = (obj["highvoltagebatteryerrorbcu"].is_string()?atoi(obj["highvoltagebatteryerrorbcu"].get<std::string>().c_str()):obj["highvoltagebatteryerrorbcu"].get<int>());
        }
        if(obj.contains("automodeexitreasonlosscommuni"))
        {
            msg.automodeexitreasonlosscommuni = (obj["automodeexitreasonlosscommuni"].is_string()?(bool)atoi(obj["automodeexitreasonlosscommuni"].get<std::string>().c_str()):obj["automodeexitreasonlosscommuni"].get<bool>());
        }
        if(obj.contains("automodeexitreasonreqsignalno"))
        {
            msg.automodeexitreasonreqsignalno = (obj["automodeexitreasonreqsignalno"].is_string()?(bool)atoi(obj["automodeexitreasonreqsignalno"].get<std::string>().c_str()):obj["automodeexitreasonreqsignalno"].get<bool>());
        }
        if(obj.contains("automodeexitreasonlowpower"))
        {
            msg.automodeexitreasonlowpower = (obj["automodeexitreasonlowpower"].is_string()?(bool)atoi(obj["automodeexitreasonlowpower"].get<std::string>().c_str()):obj["automodeexitreasonlowpower"].get<bool>());
        }
        if(obj.contains("automodeexitreasonhighvolt"))
        {
            msg.automodeexitreasonhighvolt = (obj["automodeexitreasonhighvolt"].is_string()?(bool)atoi(obj["automodeexitreasonhighvolt"].get<std::string>().c_str()):obj["automodeexitreasonhighvolt"].get<bool>());
        }
        if(obj.contains("automodeexitreasonvehicleflt"))
        {
            msg.automodeexitreasonvehicleflt = (obj["automodeexitreasonvehicleflt"].is_string()?(bool)atoi(obj["automodeexitreasonvehicleflt"].get<std::string>().c_str()):obj["automodeexitreasonvehicleflt"].get<bool>());
        }
        if(obj.contains("automodeexitreasonpressemerg"))
        {
            msg.automodeexitreasonpressemerg = (obj["automodeexitreasonpressemerg"].is_string()?(bool)atoi(obj["automodeexitreasonpressemerg"].get<std::string>().c_str()):obj["automodeexitreasonpressemerg"].get<bool>());
        }
        if(obj.contains("automodeexitreasonpressremot"))
        {
            msg.automodeexitreasonpressremot = (obj["automodeexitreasonpressremot"].is_string()?(bool)atoi(obj["automodeexitreasonpressremot"].get<std::string>().c_str()):obj["automodeexitreasonpressremot"].get<bool>());
        }
        if(obj.contains("automodeexitreasonpducontrol"))
        {
            msg.automodeexitreasonpducontrol = (obj["automodeexitreasonpducontrol"].is_string()?(bool)atoi(obj["automodeexitreasonpducontrol"].get<std::string>().c_str()):obj["automodeexitreasonpducontrol"].get<bool>());
        }
        if(obj.contains("vcufaultreptalivecounter"))
        {
            msg.vcufaultreptalivecounter = (obj["vcufaultreptalivecounter"].is_string()?atoi(obj["vcufaultreptalivecounter"].get<std::string>().c_str()):obj["vcufaultreptalivecounter"].get<int>());
        }
        if(obj.contains("vcufaultreptchecksum"))
        {
            msg.vcufaultreptchecksum = (obj["vcufaultreptchecksum"].is_string()?atoi(obj["vcufaultreptchecksum"].get<std::string>().c_str()):obj["vcufaultreptchecksum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVcuVehicleFaultResponse201 from_json<ApollocanbusVcuVehicleFaultResponse201>(nlohmann::json obj){
        return from_json_ApollocanbusVcuVehicleFaultResponse201(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuVehicleFaultResponse201 &dt)
    {
        dt=from_json_ApollocanbusVcuVehicleFaultResponse201(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuVehicleFaultResponse201 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuVehicleFaultResponse201 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
