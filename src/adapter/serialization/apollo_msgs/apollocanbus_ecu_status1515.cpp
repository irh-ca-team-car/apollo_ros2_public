#include "adapter/serialization/apollo_msgs/apollocanbus_ecu_status1515.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEcuStatus1515 &msg) {
        nlohmann::json obj;
        obj["speed"] = (msg.speed);
        obj["accspeed"] = (msg.accspeed);
        obj["ctrlsts"] = (msg.ctrlsts);
        obj["chassissts"] = (msg.chassissts);
        obj["chassiserr"] = (msg.chassiserr);
        return obj;
    }
    ApollocanbusEcuStatus1515 from_json_ApollocanbusEcuStatus1515 (nlohmann::json obj) {
        ApollocanbusEcuStatus1515 msg;
        if(obj.contains("speed"))
        {
            msg.speed = (obj["speed"].is_string()?atof(obj["speed"].get<std::string>().c_str()):obj["speed"].get<double>());
        }
        if(obj.contains("accspeed"))
        {
            msg.accspeed = (obj["accspeed"].is_string()?atof(obj["accspeed"].get<std::string>().c_str()):obj["accspeed"].get<double>());
        }
        if(obj.contains("ctrlsts"))
        {
            msg.ctrlsts = (obj["ctrlsts"].is_string()?atoi(obj["ctrlsts"].get<std::string>().c_str()):obj["ctrlsts"].get<int>());
        }
        if(obj.contains("chassissts"))
        {
            msg.chassissts = (obj["chassissts"].is_string()?atoi(obj["chassissts"].get<std::string>().c_str()):obj["chassissts"].get<int>());
        }
        if(obj.contains("chassiserr"))
        {
            msg.chassiserr = (obj["chassiserr"].is_string()?atoi(obj["chassiserr"].get<std::string>().c_str()):obj["chassiserr"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusEcuStatus1515 from_json<ApollocanbusEcuStatus1515>(nlohmann::json obj){
        return from_json_ApollocanbusEcuStatus1515(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEcuStatus1515 &dt)
    {
        dt=from_json_ApollocanbusEcuStatus1515(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEcuStatus1515 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEcuStatus1515 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
