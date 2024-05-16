#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor5511.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusUltrSensor5511 &msg) {
        nlohmann::json obj;
        obj["uiuss7tofdirect"] = (msg.uiuss7tofdirect);
        obj["uiuss6tofdirect"] = (msg.uiuss6tofdirect);
        obj["uiuss1tofdirect"] = (msg.uiuss1tofdirect);
        obj["uiuss0tofdirect"] = (msg.uiuss0tofdirect);
        return obj;
    }
    ApollocanbusUltrSensor5511 from_json_ApollocanbusUltrSensor5511 (nlohmann::json obj) {
        ApollocanbusUltrSensor5511 msg;
        if(obj.contains("uiuss7tofdirect"))
        {
            msg.uiuss7tofdirect = (obj["uiuss7tofdirect"].is_string()?atof(obj["uiuss7tofdirect"].get<std::string>().c_str()):obj["uiuss7tofdirect"].get<double>());
        }
        if(obj.contains("uiuss6tofdirect"))
        {
            msg.uiuss6tofdirect = (obj["uiuss6tofdirect"].is_string()?atof(obj["uiuss6tofdirect"].get<std::string>().c_str()):obj["uiuss6tofdirect"].get<double>());
        }
        if(obj.contains("uiuss1tofdirect"))
        {
            msg.uiuss1tofdirect = (obj["uiuss1tofdirect"].is_string()?atof(obj["uiuss1tofdirect"].get<std::string>().c_str()):obj["uiuss1tofdirect"].get<double>());
        }
        if(obj.contains("uiuss0tofdirect"))
        {
            msg.uiuss0tofdirect = (obj["uiuss0tofdirect"].is_string()?atof(obj["uiuss0tofdirect"].get<std::string>().c_str()):obj["uiuss0tofdirect"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusUltrSensor5511 from_json<ApollocanbusUltrSensor5511>(nlohmann::json obj){
        return from_json_ApollocanbusUltrSensor5511(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusUltrSensor5511 &dt)
    {
        dt=from_json_ApollocanbusUltrSensor5511(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusUltrSensor5511 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusUltrSensor5511 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
