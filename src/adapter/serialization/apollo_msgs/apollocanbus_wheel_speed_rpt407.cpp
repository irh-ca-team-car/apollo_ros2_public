#include "adapter/serialization/apollo_msgs/apollocanbus_wheel_speed_rpt407.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWheelSpeedRpt407 &msg) {
        nlohmann::json obj;
        obj["wheelspdrearright"] = (msg.wheelspdrearright);
        obj["wheelspdrearleft"] = (msg.wheelspdrearleft);
        obj["wheelspdfrontright"] = (msg.wheelspdfrontright);
        obj["wheelspdfrontleft"] = (msg.wheelspdfrontleft);
        return obj;
    }
    ApollocanbusWheelSpeedRpt407 from_json_ApollocanbusWheelSpeedRpt407 (nlohmann::json obj) {
        ApollocanbusWheelSpeedRpt407 msg;
        if(obj.contains("wheelspdrearright"))
        {
            msg.wheelspdrearright = (obj["wheelspdrearright"].is_string()?atof(obj["wheelspdrearright"].get<std::string>().c_str()):obj["wheelspdrearright"].get<double>());
        }
        if(obj.contains("wheelspdrearleft"))
        {
            msg.wheelspdrearleft = (obj["wheelspdrearleft"].is_string()?atof(obj["wheelspdrearleft"].get<std::string>().c_str()):obj["wheelspdrearleft"].get<double>());
        }
        if(obj.contains("wheelspdfrontright"))
        {
            msg.wheelspdfrontright = (obj["wheelspdfrontright"].is_string()?atof(obj["wheelspdfrontright"].get<std::string>().c_str()):obj["wheelspdfrontright"].get<double>());
        }
        if(obj.contains("wheelspdfrontleft"))
        {
            msg.wheelspdfrontleft = (obj["wheelspdfrontleft"].is_string()?atof(obj["wheelspdfrontleft"].get<std::string>().c_str()):obj["wheelspdfrontleft"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusWheelSpeedRpt407 from_json<ApollocanbusWheelSpeedRpt407>(nlohmann::json obj){
        return from_json_ApollocanbusWheelSpeedRpt407(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWheelSpeedRpt407 &dt)
    {
        dt=from_json_ApollocanbusWheelSpeedRpt407(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWheelSpeedRpt407 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWheelSpeedRpt407 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
