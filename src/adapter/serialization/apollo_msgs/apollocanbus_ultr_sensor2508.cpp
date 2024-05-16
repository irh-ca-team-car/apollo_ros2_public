#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor2508.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusUltrSensor2508 &msg) {
        nlohmann::json obj;
        obj["uiuss9tofindirect"] = (msg.uiuss9tofindirect);
        obj["uiuss8tofindirect"] = (msg.uiuss8tofindirect);
        obj["uiuss11tofindirect"] = (msg.uiuss11tofindirect);
        obj["uiuss10tofindirect"] = (msg.uiuss10tofindirect);
        return obj;
    }
    ApollocanbusUltrSensor2508 from_json_ApollocanbusUltrSensor2508 (nlohmann::json obj) {
        ApollocanbusUltrSensor2508 msg;
        if(obj.contains("uiuss9tofindirect"))
        {
            msg.uiuss9tofindirect = (obj["uiuss9tofindirect"].is_string()?atof(obj["uiuss9tofindirect"].get<std::string>().c_str()):obj["uiuss9tofindirect"].get<double>());
        }
        if(obj.contains("uiuss8tofindirect"))
        {
            msg.uiuss8tofindirect = (obj["uiuss8tofindirect"].is_string()?atof(obj["uiuss8tofindirect"].get<std::string>().c_str()):obj["uiuss8tofindirect"].get<double>());
        }
        if(obj.contains("uiuss11tofindirect"))
        {
            msg.uiuss11tofindirect = (obj["uiuss11tofindirect"].is_string()?atof(obj["uiuss11tofindirect"].get<std::string>().c_str()):obj["uiuss11tofindirect"].get<double>());
        }
        if(obj.contains("uiuss10tofindirect"))
        {
            msg.uiuss10tofindirect = (obj["uiuss10tofindirect"].is_string()?atof(obj["uiuss10tofindirect"].get<std::string>().c_str()):obj["uiuss10tofindirect"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusUltrSensor2508 from_json<ApollocanbusUltrSensor2508>(nlohmann::json obj){
        return from_json_ApollocanbusUltrSensor2508(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusUltrSensor2508 &dt)
    {
        dt=from_json_ApollocanbusUltrSensor2508(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusUltrSensor2508 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusUltrSensor2508 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
