#include "adapter/serialization/apollo_msgs/apollocanbus_adc_motioncontrollimits112.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdcMotioncontrollimits112 &msg) {
        nlohmann::json obj;
        obj["adccmdthrottlecommandlimit"] = (msg.adccmdthrottlecommandlimit);
        obj["adccmdsteeringrate"] = (msg.adccmdsteeringrate);
        obj["adccmdsteerwheelanglelimit"] = (msg.adccmdsteerwheelanglelimit);
        return obj;
    }
    ApollocanbusAdcMotioncontrollimits112 from_json_ApollocanbusAdcMotioncontrollimits112 (nlohmann::json obj) {
        ApollocanbusAdcMotioncontrollimits112 msg;
        if(obj.contains("adccmdthrottlecommandlimit"))
        {
            msg.adccmdthrottlecommandlimit = (obj["adccmdthrottlecommandlimit"].is_string()?atof(obj["adccmdthrottlecommandlimit"].get<std::string>().c_str()):obj["adccmdthrottlecommandlimit"].get<double>());
        }
        if(obj.contains("adccmdsteeringrate"))
        {
            msg.adccmdsteeringrate = (obj["adccmdsteeringrate"].is_string()?atof(obj["adccmdsteeringrate"].get<std::string>().c_str()):obj["adccmdsteeringrate"].get<double>());
        }
        if(obj.contains("adccmdsteerwheelanglelimit"))
        {
            msg.adccmdsteerwheelanglelimit = (obj["adccmdsteerwheelanglelimit"].is_string()?atof(obj["adccmdsteerwheelanglelimit"].get<std::string>().c_str()):obj["adccmdsteerwheelanglelimit"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusAdcMotioncontrollimits112 from_json<ApollocanbusAdcMotioncontrollimits112>(nlohmann::json obj){
        return from_json_ApollocanbusAdcMotioncontrollimits112(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdcMotioncontrollimits112 &dt)
    {
        dt=from_json_ApollocanbusAdcMotioncontrollimits112(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdcMotioncontrollimits112 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdcMotioncontrollimits112 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
