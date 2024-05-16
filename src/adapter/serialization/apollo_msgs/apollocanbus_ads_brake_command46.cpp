#include "adapter/serialization/apollo_msgs/apollocanbus_ads_brake_command46.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsBrakeCommand46 &msg) {
        nlohmann::json obj;
        obj["driveenable"] = (msg.driveenable);
        obj["autobrakecommand"] = (msg.autobrakecommand);
        obj["autoparkingcommand"] = (msg.autoparkingcommand);
        obj["epbrampauxiliarycommand"] = (msg.epbrampauxiliarycommand);
        obj["autodrivercmdalivecounter"] = (msg.autodrivercmdalivecounter);
        obj["autodrivercmdchecksum"] = (msg.autodrivercmdchecksum);
        return obj;
    }
    ApollocanbusAdsBrakeCommand46 from_json_ApollocanbusAdsBrakeCommand46 (nlohmann::json obj) {
        ApollocanbusAdsBrakeCommand46 msg;
        if(obj.contains("driveenable"))
        {
            msg.driveenable = (obj["driveenable"].is_string()?(bool)atoi(obj["driveenable"].get<std::string>().c_str()):obj["driveenable"].get<bool>());
        }
        if(obj.contains("autobrakecommand"))
        {
            msg.autobrakecommand = (obj["autobrakecommand"].is_string()?atoi(obj["autobrakecommand"].get<std::string>().c_str()):obj["autobrakecommand"].get<int>());
        }
        if(obj.contains("autoparkingcommand"))
        {
            msg.autoparkingcommand = (obj["autoparkingcommand"].is_string()?(bool)atoi(obj["autoparkingcommand"].get<std::string>().c_str()):obj["autoparkingcommand"].get<bool>());
        }
        if(obj.contains("epbrampauxiliarycommand"))
        {
            msg.epbrampauxiliarycommand = (obj["epbrampauxiliarycommand"].is_string()?(bool)atoi(obj["epbrampauxiliarycommand"].get<std::string>().c_str()):obj["epbrampauxiliarycommand"].get<bool>());
        }
        if(obj.contains("autodrivercmdalivecounter"))
        {
            msg.autodrivercmdalivecounter = (obj["autodrivercmdalivecounter"].is_string()?atoi(obj["autodrivercmdalivecounter"].get<std::string>().c_str()):obj["autodrivercmdalivecounter"].get<int>());
        }
        if(obj.contains("autodrivercmdchecksum"))
        {
            msg.autodrivercmdchecksum = (obj["autodrivercmdchecksum"].is_string()?atoi(obj["autodrivercmdchecksum"].get<std::string>().c_str()):obj["autodrivercmdchecksum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusAdsBrakeCommand46 from_json<ApollocanbusAdsBrakeCommand46>(nlohmann::json obj){
        return from_json_ApollocanbusAdsBrakeCommand46(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsBrakeCommand46 &dt)
    {
        dt=from_json_ApollocanbusAdsBrakeCommand46(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsBrakeCommand46 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsBrakeCommand46 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
