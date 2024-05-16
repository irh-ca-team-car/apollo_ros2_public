#include "adapter/serialization/apollo_msgs/apollocanbus_wheel_speed_rpt7a.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWheelSpeedRpt7a &msg) {
        nlohmann::json obj;
        obj["wheelspdrearright"] = (msg.wheelspdrearright);
        obj["wheelspdrearleft"] = (msg.wheelspdrearleft);
        obj["wheelspdfrontright"] = (msg.wheelspdfrontright);
        obj["wheelspdfrontleft"] = (msg.wheelspdfrontleft);
        return obj;
    }
    ApollocanbusWheelSpeedRpt7a from_json_ApollocanbusWheelSpeedRpt7a (nlohmann::json obj) {
        ApollocanbusWheelSpeedRpt7a msg;
        if(obj.contains("wheelspdrearright"))
        {
            msg.wheelspdrearright = (obj["wheelspdrearright"].is_string()?atoi(obj["wheelspdrearright"].get<std::string>().c_str()):obj["wheelspdrearright"].get<int>());
        }
        if(obj.contains("wheelspdrearleft"))
        {
            msg.wheelspdrearleft = (obj["wheelspdrearleft"].is_string()?atoi(obj["wheelspdrearleft"].get<std::string>().c_str()):obj["wheelspdrearleft"].get<int>());
        }
        if(obj.contains("wheelspdfrontright"))
        {
            msg.wheelspdfrontright = (obj["wheelspdfrontright"].is_string()?atoi(obj["wheelspdfrontright"].get<std::string>().c_str()):obj["wheelspdfrontright"].get<int>());
        }
        if(obj.contains("wheelspdfrontleft"))
        {
            msg.wheelspdfrontleft = (obj["wheelspdfrontleft"].is_string()?atoi(obj["wheelspdfrontleft"].get<std::string>().c_str()):obj["wheelspdfrontleft"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusWheelSpeedRpt7a from_json<ApollocanbusWheelSpeedRpt7a>(nlohmann::json obj){
        return from_json_ApollocanbusWheelSpeedRpt7a(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWheelSpeedRpt7a &dt)
    {
        dt=from_json_ApollocanbusWheelSpeedRpt7a(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWheelSpeedRpt7a & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWheelSpeedRpt7a & dt)
    {
        os << to_json(dt);
        return os;
    }
}
