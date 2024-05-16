#include "adapter/serialization/apollo_msgs/apollocanbus_ultr_sensor1507.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusUltrSensor1507 &msg) {
        nlohmann::json obj;
        obj["uiuss9tofdirect"] = (msg.uiuss9tofdirect);
        obj["uiuss8tofdirect"] = (msg.uiuss8tofdirect);
        obj["uiuss11tofdirect"] = (msg.uiuss11tofdirect);
        obj["uiuss10tofdirect"] = (msg.uiuss10tofdirect);
        return obj;
    }
    ApollocanbusUltrSensor1507 from_json_ApollocanbusUltrSensor1507 (nlohmann::json obj) {
        ApollocanbusUltrSensor1507 msg;
        if(obj.contains("uiuss9tofdirect"))
        {
            msg.uiuss9tofdirect = (obj["uiuss9tofdirect"].is_string()?atof(obj["uiuss9tofdirect"].get<std::string>().c_str()):obj["uiuss9tofdirect"].get<double>());
        }
        if(obj.contains("uiuss8tofdirect"))
        {
            msg.uiuss8tofdirect = (obj["uiuss8tofdirect"].is_string()?atof(obj["uiuss8tofdirect"].get<std::string>().c_str()):obj["uiuss8tofdirect"].get<double>());
        }
        if(obj.contains("uiuss11tofdirect"))
        {
            msg.uiuss11tofdirect = (obj["uiuss11tofdirect"].is_string()?atof(obj["uiuss11tofdirect"].get<std::string>().c_str()):obj["uiuss11tofdirect"].get<double>());
        }
        if(obj.contains("uiuss10tofdirect"))
        {
            msg.uiuss10tofdirect = (obj["uiuss10tofdirect"].is_string()?atof(obj["uiuss10tofdirect"].get<std::string>().c_str()):obj["uiuss10tofdirect"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusUltrSensor1507 from_json<ApollocanbusUltrSensor1507>(nlohmann::json obj){
        return from_json_ApollocanbusUltrSensor1507(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusUltrSensor1507 &dt)
    {
        dt=from_json_ApollocanbusUltrSensor1507(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusUltrSensor1507 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusUltrSensor1507 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
