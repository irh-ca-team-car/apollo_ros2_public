#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_rearwheelspeed354.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebRearwheelspeed354 &msg) {
        nlohmann::json obj;
        obj["wheelspeedrlvalid"] = (msg.wheelspeedrlvalid);
        obj["wheelspeedrl"] = (msg.wheelspeedrl);
        obj["wheelspeedrrvalid"] = (msg.wheelspeedrrvalid);
        obj["wheelspeedrr"] = (msg.wheelspeedrr);
        obj["wheelspeedrldirect"] = (msg.wheelspeedrldirect);
        obj["wheelspeedrrdirect"] = (msg.wheelspeedrrdirect);
        obj["alivecounterrear"] = (msg.alivecounterrear);
        obj["checksumrear"] = (msg.checksumrear);
        return obj;
    }
    ApollocanbusAebRearwheelspeed354 from_json_ApollocanbusAebRearwheelspeed354 (nlohmann::json obj) {
        ApollocanbusAebRearwheelspeed354 msg;
        if(obj.contains("wheelspeedrlvalid"))
        {
            msg.wheelspeedrlvalid = (obj["wheelspeedrlvalid"].is_string()?(bool)atoi(obj["wheelspeedrlvalid"].get<std::string>().c_str()):obj["wheelspeedrlvalid"].get<bool>());
        }
        if(obj.contains("wheelspeedrl"))
        {
            msg.wheelspeedrl = (obj["wheelspeedrl"].is_string()?atof(obj["wheelspeedrl"].get<std::string>().c_str()):obj["wheelspeedrl"].get<double>());
        }
        if(obj.contains("wheelspeedrrvalid"))
        {
            msg.wheelspeedrrvalid = (obj["wheelspeedrrvalid"].is_string()?(bool)atoi(obj["wheelspeedrrvalid"].get<std::string>().c_str()):obj["wheelspeedrrvalid"].get<bool>());
        }
        if(obj.contains("wheelspeedrr"))
        {
            msg.wheelspeedrr = (obj["wheelspeedrr"].is_string()?atof(obj["wheelspeedrr"].get<std::string>().c_str()):obj["wheelspeedrr"].get<double>());
        }
        if(obj.contains("wheelspeedrldirect"))
        {
            msg.wheelspeedrldirect = (obj["wheelspeedrldirect"].is_string()?atof(obj["wheelspeedrldirect"].get<std::string>().c_str()):obj["wheelspeedrldirect"].get<double>());
        }
        if(obj.contains("wheelspeedrrdirect"))
        {
            msg.wheelspeedrrdirect = (obj["wheelspeedrrdirect"].is_string()?atof(obj["wheelspeedrrdirect"].get<std::string>().c_str()):obj["wheelspeedrrdirect"].get<double>());
        }
        if(obj.contains("alivecounterrear"))
        {
            msg.alivecounterrear = (obj["alivecounterrear"].is_string()?atof(obj["alivecounterrear"].get<std::string>().c_str()):obj["alivecounterrear"].get<double>());
        }
        if(obj.contains("checksumrear"))
        {
            msg.checksumrear = (obj["checksumrear"].is_string()?atof(obj["checksumrear"].get<std::string>().c_str()):obj["checksumrear"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusAebRearwheelspeed354 from_json<ApollocanbusAebRearwheelspeed354>(nlohmann::json obj){
        return from_json_ApollocanbusAebRearwheelspeed354(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebRearwheelspeed354 &dt)
    {
        dt=from_json_ApollocanbusAebRearwheelspeed354(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebRearwheelspeed354 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebRearwheelspeed354 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
