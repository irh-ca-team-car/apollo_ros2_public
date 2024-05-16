#include "adapter/serialization/apollo_msgs/apollocanbus_ems.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEms &msg) {
        nlohmann::json obj;
        obj["isengineaccavailable"] = (msg.isengineaccavailable);
        obj["isengineaccerror"] = (msg.isengineaccerror);
        obj["enginestate"] = (msg.enginestate);
        obj["maxenginetorqpercent"] = (msg.maxenginetorqpercent);
        obj["minenginetorqpercent"] = (msg.minenginetorqpercent);
        obj["baseenginetorqconstant"] = (msg.baseenginetorqconstant);
        obj["isenginespeederror"] = (msg.isenginespeederror);
        obj["enginespeed"] = (msg.enginespeed);
        obj["enginetorque"] = (msg.enginetorque);
        obj["isoverenginetorque"] = (msg.isoverenginetorque);
        obj["enginerpm"] = (msg.enginerpm);
        return obj;
    }
    ApollocanbusEms from_json_ApollocanbusEms (nlohmann::json obj) {
        ApollocanbusEms msg;
        if(obj.contains("isengineaccavailable"))
        {
            msg.isengineaccavailable = (obj["isengineaccavailable"].is_string()?(bool)atoi(obj["isengineaccavailable"].get<std::string>().c_str()):obj["isengineaccavailable"].get<bool>());
        }
        if(obj.contains("isengineaccerror"))
        {
            msg.isengineaccerror = (obj["isengineaccerror"].is_string()?(bool)atoi(obj["isengineaccerror"].get<std::string>().c_str()):obj["isengineaccerror"].get<bool>());
        }
        if(obj.contains("enginestate"))
        {
            msg.enginestate = (obj["enginestate"].is_string()?atoi(obj["enginestate"].get<std::string>().c_str()):obj["enginestate"].get<int>());
        }
        if(obj.contains("maxenginetorqpercent"))
        {
            msg.maxenginetorqpercent = (obj["maxenginetorqpercent"].is_string()?atof(obj["maxenginetorqpercent"].get<std::string>().c_str()):obj["maxenginetorqpercent"].get<double>());
        }
        if(obj.contains("minenginetorqpercent"))
        {
            msg.minenginetorqpercent = (obj["minenginetorqpercent"].is_string()?atof(obj["minenginetorqpercent"].get<std::string>().c_str()):obj["minenginetorqpercent"].get<double>());
        }
        if(obj.contains("baseenginetorqconstant"))
        {
            msg.baseenginetorqconstant = (obj["baseenginetorqconstant"].is_string()?atoi(obj["baseenginetorqconstant"].get<std::string>().c_str()):obj["baseenginetorqconstant"].get<int>());
        }
        if(obj.contains("isenginespeederror"))
        {
            msg.isenginespeederror = (obj["isenginespeederror"].is_string()?(bool)atoi(obj["isenginespeederror"].get<std::string>().c_str()):obj["isenginespeederror"].get<bool>());
        }
        if(obj.contains("enginespeed"))
        {
            msg.enginespeed = (obj["enginespeed"].is_string()?atof(obj["enginespeed"].get<std::string>().c_str()):obj["enginespeed"].get<double>());
        }
        if(obj.contains("enginetorque"))
        {
            msg.enginetorque = (obj["enginetorque"].is_string()?atoi(obj["enginetorque"].get<std::string>().c_str()):obj["enginetorque"].get<int>());
        }
        if(obj.contains("isoverenginetorque"))
        {
            msg.isoverenginetorque = (obj["isoverenginetorque"].is_string()?(bool)atoi(obj["isoverenginetorque"].get<std::string>().c_str()):obj["isoverenginetorque"].get<bool>());
        }
        if(obj.contains("enginerpm"))
        {
            msg.enginerpm = (obj["enginerpm"].is_string()?atof(obj["enginerpm"].get<std::string>().c_str()):obj["enginerpm"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusEms from_json<ApollocanbusEms>(nlohmann::json obj){
        return from_json_ApollocanbusEms(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEms &dt)
    {
        dt=from_json_ApollocanbusEms(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEms & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEms & dt)
    {
        os << to_json(dt);
        return os;
    }
}
