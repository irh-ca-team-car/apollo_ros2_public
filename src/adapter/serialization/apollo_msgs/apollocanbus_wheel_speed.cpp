#include "adapter/serialization/apollo_msgs/apollocanbus_wheel_speed.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWheelSpeed &msg) {
        nlohmann::json obj;
        obj["iswheelspdrrvalid"] = (msg.iswheelspdrrvalid);
        obj["wheeldirectionrr"] = (msg.wheeldirectionrr);
        obj["wheelspdrr"] = (msg.wheelspdrr);
        obj["iswheelspdrlvalid"] = (msg.iswheelspdrlvalid);
        obj["wheeldirectionrl"] = (msg.wheeldirectionrl);
        obj["wheelspdrl"] = (msg.wheelspdrl);
        obj["iswheelspdfrvalid"] = (msg.iswheelspdfrvalid);
        obj["wheeldirectionfr"] = (msg.wheeldirectionfr);
        obj["wheelspdfr"] = (msg.wheelspdfr);
        obj["iswheelspdflvalid"] = (msg.iswheelspdflvalid);
        obj["wheeldirectionfl"] = (msg.wheeldirectionfl);
        obj["wheelspdfl"] = (msg.wheelspdfl);
        return obj;
    }
    ApollocanbusWheelSpeed from_json_ApollocanbusWheelSpeed (nlohmann::json obj) {
        ApollocanbusWheelSpeed msg;
        if(obj.contains("iswheelspdrrvalid"))
        {
            msg.iswheelspdrrvalid = (obj["iswheelspdrrvalid"].is_string()?(bool)atoi(obj["iswheelspdrrvalid"].get<std::string>().c_str()):obj["iswheelspdrrvalid"].get<bool>());
        }
        if(obj.contains("wheeldirectionrr"))
        {
            msg.wheeldirectionrr = (obj["wheeldirectionrr"].is_string()?atoi(obj["wheeldirectionrr"].get<std::string>().c_str()):obj["wheeldirectionrr"].get<int>());
        }
        if(obj.contains("wheelspdrr"))
        {
            msg.wheelspdrr = (obj["wheelspdrr"].is_string()?atof(obj["wheelspdrr"].get<std::string>().c_str()):obj["wheelspdrr"].get<double>());
        }
        if(obj.contains("iswheelspdrlvalid"))
        {
            msg.iswheelspdrlvalid = (obj["iswheelspdrlvalid"].is_string()?(bool)atoi(obj["iswheelspdrlvalid"].get<std::string>().c_str()):obj["iswheelspdrlvalid"].get<bool>());
        }
        if(obj.contains("wheeldirectionrl"))
        {
            msg.wheeldirectionrl = (obj["wheeldirectionrl"].is_string()?atoi(obj["wheeldirectionrl"].get<std::string>().c_str()):obj["wheeldirectionrl"].get<int>());
        }
        if(obj.contains("wheelspdrl"))
        {
            msg.wheelspdrl = (obj["wheelspdrl"].is_string()?atof(obj["wheelspdrl"].get<std::string>().c_str()):obj["wheelspdrl"].get<double>());
        }
        if(obj.contains("iswheelspdfrvalid"))
        {
            msg.iswheelspdfrvalid = (obj["iswheelspdfrvalid"].is_string()?(bool)atoi(obj["iswheelspdfrvalid"].get<std::string>().c_str()):obj["iswheelspdfrvalid"].get<bool>());
        }
        if(obj.contains("wheeldirectionfr"))
        {
            msg.wheeldirectionfr = (obj["wheeldirectionfr"].is_string()?atoi(obj["wheeldirectionfr"].get<std::string>().c_str()):obj["wheeldirectionfr"].get<int>());
        }
        if(obj.contains("wheelspdfr"))
        {
            msg.wheelspdfr = (obj["wheelspdfr"].is_string()?atof(obj["wheelspdfr"].get<std::string>().c_str()):obj["wheelspdfr"].get<double>());
        }
        if(obj.contains("iswheelspdflvalid"))
        {
            msg.iswheelspdflvalid = (obj["iswheelspdflvalid"].is_string()?(bool)atoi(obj["iswheelspdflvalid"].get<std::string>().c_str()):obj["iswheelspdflvalid"].get<bool>());
        }
        if(obj.contains("wheeldirectionfl"))
        {
            msg.wheeldirectionfl = (obj["wheeldirectionfl"].is_string()?atoi(obj["wheeldirectionfl"].get<std::string>().c_str()):obj["wheeldirectionfl"].get<int>());
        }
        if(obj.contains("wheelspdfl"))
        {
            msg.wheelspdfl = (obj["wheelspdfl"].is_string()?atof(obj["wheelspdfl"].get<std::string>().c_str()):obj["wheelspdfl"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusWheelSpeed from_json<ApollocanbusWheelSpeed>(nlohmann::json obj){
        return from_json_ApollocanbusWheelSpeed(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWheelSpeed &dt)
    {
        dt=from_json_ApollocanbusWheelSpeed(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWheelSpeed & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWheelSpeed & dt)
    {
        os << to_json(dt);
        return os;
    }
}
