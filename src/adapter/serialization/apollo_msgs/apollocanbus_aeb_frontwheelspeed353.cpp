#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_frontwheelspeed353.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebFrontwheelspeed353 &msg) {
        nlohmann::json obj;
        obj["vehiclespeedvalid"] = (msg.vehiclespeedvalid);
        obj["vehiclespeed"] = (msg.vehiclespeed);
        obj["vehiclerealdirect"] = (msg.vehiclerealdirect);
        obj["wheelspeedflvalid"] = (msg.wheelspeedflvalid);
        obj["wheelspeedfl"] = (msg.wheelspeedfl);
        obj["wheelspeedfrvalid"] = (msg.wheelspeedfrvalid);
        obj["wheelspeedfr"] = (msg.wheelspeedfr);
        obj["wheelspeedfldirect"] = (msg.wheelspeedfldirect);
        obj["wheelspeedfrdirect"] = (msg.wheelspeedfrdirect);
        obj["alivecounterfront"] = (msg.alivecounterfront);
        obj["checksumfront"] = (msg.checksumfront);
        return obj;
    }
    ApollocanbusAebFrontwheelspeed353 from_json_ApollocanbusAebFrontwheelspeed353 (nlohmann::json obj) {
        ApollocanbusAebFrontwheelspeed353 msg;
        if(obj.contains("vehiclespeedvalid"))
        {
            msg.vehiclespeedvalid = (obj["vehiclespeedvalid"].is_string()?(bool)atoi(obj["vehiclespeedvalid"].get<std::string>().c_str()):obj["vehiclespeedvalid"].get<bool>());
        }
        if(obj.contains("vehiclespeed"))
        {
            msg.vehiclespeed = (obj["vehiclespeed"].is_string()?atof(obj["vehiclespeed"].get<std::string>().c_str()):obj["vehiclespeed"].get<double>());
        }
        if(obj.contains("vehiclerealdirect"))
        {
            msg.vehiclerealdirect = (obj["vehiclerealdirect"].is_string()?atof(obj["vehiclerealdirect"].get<std::string>().c_str()):obj["vehiclerealdirect"].get<double>());
        }
        if(obj.contains("wheelspeedflvalid"))
        {
            msg.wheelspeedflvalid = (obj["wheelspeedflvalid"].is_string()?(bool)atoi(obj["wheelspeedflvalid"].get<std::string>().c_str()):obj["wheelspeedflvalid"].get<bool>());
        }
        if(obj.contains("wheelspeedfl"))
        {
            msg.wheelspeedfl = (obj["wheelspeedfl"].is_string()?atof(obj["wheelspeedfl"].get<std::string>().c_str()):obj["wheelspeedfl"].get<double>());
        }
        if(obj.contains("wheelspeedfrvalid"))
        {
            msg.wheelspeedfrvalid = (obj["wheelspeedfrvalid"].is_string()?(bool)atoi(obj["wheelspeedfrvalid"].get<std::string>().c_str()):obj["wheelspeedfrvalid"].get<bool>());
        }
        if(obj.contains("wheelspeedfr"))
        {
            msg.wheelspeedfr = (obj["wheelspeedfr"].is_string()?atof(obj["wheelspeedfr"].get<std::string>().c_str()):obj["wheelspeedfr"].get<double>());
        }
        if(obj.contains("wheelspeedfldirect"))
        {
            msg.wheelspeedfldirect = (obj["wheelspeedfldirect"].is_string()?atof(obj["wheelspeedfldirect"].get<std::string>().c_str()):obj["wheelspeedfldirect"].get<double>());
        }
        if(obj.contains("wheelspeedfrdirect"))
        {
            msg.wheelspeedfrdirect = (obj["wheelspeedfrdirect"].is_string()?atof(obj["wheelspeedfrdirect"].get<std::string>().c_str()):obj["wheelspeedfrdirect"].get<double>());
        }
        if(obj.contains("alivecounterfront"))
        {
            msg.alivecounterfront = (obj["alivecounterfront"].is_string()?atof(obj["alivecounterfront"].get<std::string>().c_str()):obj["alivecounterfront"].get<double>());
        }
        if(obj.contains("checksumfront"))
        {
            msg.checksumfront = (obj["checksumfront"].is_string()?atof(obj["checksumfront"].get<std::string>().c_str()):obj["checksumfront"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusAebFrontwheelspeed353 from_json<ApollocanbusAebFrontwheelspeed353>(nlohmann::json obj){
        return from_json_ApollocanbusAebFrontwheelspeed353(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebFrontwheelspeed353 &dt)
    {
        dt=from_json_ApollocanbusAebFrontwheelspeed353(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebFrontwheelspeed353 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebFrontwheelspeed353 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
