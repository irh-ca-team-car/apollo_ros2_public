#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor4510.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusUltrSensor4510 &msg) {
        nlohmann::json obj;
        obj["uiuss5tofindirect"] = (msg.uiuss5tofindirect);
        obj["uiuss4tofindirect"] = (msg.uiuss4tofindirect);
        obj["uiuss3tofindirect"] = (msg.uiuss3tofindirect);
        obj["uiuss2tofindirect"] = (msg.uiuss2tofindirect);
        return obj;
    }
    ApollocanbusUltrSensor4510 from_json_ApollocanbusUltrSensor4510 (nlohmann::json obj) {
        ApollocanbusUltrSensor4510 msg;
        if(obj.contains("uiuss5tofindirect"))
        {
            msg.uiuss5tofindirect = (obj["uiuss5tofindirect"].is_string()?atof(obj["uiuss5tofindirect"].get<std::string>().c_str()):obj["uiuss5tofindirect"].get<double>());
        }
        if(obj.contains("uiuss4tofindirect"))
        {
            msg.uiuss4tofindirect = (obj["uiuss4tofindirect"].is_string()?atof(obj["uiuss4tofindirect"].get<std::string>().c_str()):obj["uiuss4tofindirect"].get<double>());
        }
        if(obj.contains("uiuss3tofindirect"))
        {
            msg.uiuss3tofindirect = (obj["uiuss3tofindirect"].is_string()?atof(obj["uiuss3tofindirect"].get<std::string>().c_str()):obj["uiuss3tofindirect"].get<double>());
        }
        if(obj.contains("uiuss2tofindirect"))
        {
            msg.uiuss2tofindirect = (obj["uiuss2tofindirect"].is_string()?atof(obj["uiuss2tofindirect"].get<std::string>().c_str()):obj["uiuss2tofindirect"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusUltrSensor4510 from_json<ApollocanbusUltrSensor4510>(nlohmann::json obj){
        return from_json_ApollocanbusUltrSensor4510(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusUltrSensor4510 &dt)
    {
        dt=from_json_ApollocanbusUltrSensor4510(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusUltrSensor4510 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusUltrSensor4510 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
