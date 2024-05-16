#include "adapter/serialization/apollo_msgs/apollocanbus_ads_drive_command50.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsDriveCommand50 &msg) {
        nlohmann::json obj;
        obj["driveenable"] = (msg.driveenable);
        obj["autoshiftcommand"] = (msg.autoshiftcommand);
        obj["autodrivetorque"] = (msg.autodrivetorque);
        obj["autodrivercmdalivecounter"] = (msg.autodrivercmdalivecounter);
        obj["autodrivercmdchecksum"] = (msg.autodrivercmdchecksum);
        return obj;
    }
    ApollocanbusAdsDriveCommand50 from_json_ApollocanbusAdsDriveCommand50 (nlohmann::json obj) {
        ApollocanbusAdsDriveCommand50 msg;
        if(obj.contains("driveenable"))
        {
            msg.driveenable = (obj["driveenable"].is_string()?(bool)atoi(obj["driveenable"].get<std::string>().c_str()):obj["driveenable"].get<bool>());
        }
        if(obj.contains("autoshiftcommand"))
        {
            msg.autoshiftcommand = (obj["autoshiftcommand"].is_string()?atoi(obj["autoshiftcommand"].get<std::string>().c_str()):obj["autoshiftcommand"].get<int>());
        }
        if(obj.contains("autodrivetorque"))
        {
            msg.autodrivetorque = (obj["autodrivetorque"].is_string()?atof(obj["autodrivetorque"].get<std::string>().c_str()):obj["autodrivetorque"].get<double>());
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
    ApollocanbusAdsDriveCommand50 from_json<ApollocanbusAdsDriveCommand50>(nlohmann::json obj){
        return from_json_ApollocanbusAdsDriveCommand50(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsDriveCommand50 &dt)
    {
        dt=from_json_ApollocanbusAdsDriveCommand50(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsDriveCommand50 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsDriveCommand50 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
