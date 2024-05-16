#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_report505.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuReport505 &msg) {
        nlohmann::json obj;
        obj["vehiclemodestate"] = (msg.vehiclemodestate);
        obj["frontcrashstate"] = (msg.frontcrashstate);
        obj["backcrashstate"] = (msg.backcrashstate);
        obj["aebstate"] = (msg.aebstate);
        obj["acc"] = (msg.acc);
        obj["speed"] = (msg.speed);
        return obj;
    }
    ApollocanbusVcuReport505 from_json_ApollocanbusVcuReport505 (nlohmann::json obj) {
        ApollocanbusVcuReport505 msg;
        if(obj.contains("vehiclemodestate"))
        {
            msg.vehiclemodestate = (obj["vehiclemodestate"].is_string()?atoi(obj["vehiclemodestate"].get<std::string>().c_str()):obj["vehiclemodestate"].get<int>());
        }
        if(obj.contains("frontcrashstate"))
        {
            msg.frontcrashstate = (obj["frontcrashstate"].is_string()?atoi(obj["frontcrashstate"].get<std::string>().c_str()):obj["frontcrashstate"].get<int>());
        }
        if(obj.contains("backcrashstate"))
        {
            msg.backcrashstate = (obj["backcrashstate"].is_string()?atoi(obj["backcrashstate"].get<std::string>().c_str()):obj["backcrashstate"].get<int>());
        }
        if(obj.contains("aebstate"))
        {
            msg.aebstate = (obj["aebstate"].is_string()?atoi(obj["aebstate"].get<std::string>().c_str()):obj["aebstate"].get<int>());
        }
        if(obj.contains("acc"))
        {
            msg.acc = (obj["acc"].is_string()?atof(obj["acc"].get<std::string>().c_str()):obj["acc"].get<double>());
        }
        if(obj.contains("speed"))
        {
            msg.speed = (obj["speed"].is_string()?atof(obj["speed"].get<std::string>().c_str()):obj["speed"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusVcuReport505 from_json<ApollocanbusVcuReport505>(nlohmann::json obj){
        return from_json_ApollocanbusVcuReport505(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuReport505 &dt)
    {
        dt=from_json_ApollocanbusVcuReport505(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuReport505 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuReport505 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
