#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor3509.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusUltrSensor3509 &msg) {
        nlohmann::json obj;
        obj["uiuss5tofdirect"] = (msg.uiuss5tofdirect);
        obj["uiuss4tofdirect"] = (msg.uiuss4tofdirect);
        obj["uiuss3tofdirect"] = (msg.uiuss3tofdirect);
        obj["uiuss2tofdirect"] = (msg.uiuss2tofdirect);
        return obj;
    }
    ApollocanbusUltrSensor3509 from_json_ApollocanbusUltrSensor3509 (nlohmann::json obj) {
        ApollocanbusUltrSensor3509 msg;
        if(obj.contains("uiuss5tofdirect"))
        {
            msg.uiuss5tofdirect = (obj["uiuss5tofdirect"].is_string()?atof(obj["uiuss5tofdirect"].get<std::string>().c_str()):obj["uiuss5tofdirect"].get<double>());
        }
        if(obj.contains("uiuss4tofdirect"))
        {
            msg.uiuss4tofdirect = (obj["uiuss4tofdirect"].is_string()?atof(obj["uiuss4tofdirect"].get<std::string>().c_str()):obj["uiuss4tofdirect"].get<double>());
        }
        if(obj.contains("uiuss3tofdirect"))
        {
            msg.uiuss3tofdirect = (obj["uiuss3tofdirect"].is_string()?atof(obj["uiuss3tofdirect"].get<std::string>().c_str()):obj["uiuss3tofdirect"].get<double>());
        }
        if(obj.contains("uiuss2tofdirect"))
        {
            msg.uiuss2tofdirect = (obj["uiuss2tofdirect"].is_string()?atof(obj["uiuss2tofdirect"].get<std::string>().c_str()):obj["uiuss2tofdirect"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusUltrSensor3509 from_json<ApollocanbusUltrSensor3509>(nlohmann::json obj){
        return from_json_ApollocanbusUltrSensor3509(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusUltrSensor3509 &dt)
    {
        dt=from_json_ApollocanbusUltrSensor3509(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusUltrSensor3509 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusUltrSensor3509 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
