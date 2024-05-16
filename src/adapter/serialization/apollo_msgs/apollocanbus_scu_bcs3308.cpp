#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcs3308.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuBcs3308 &msg) {
        nlohmann::json obj;
        obj["bcsrrwheelspdvd"] = (msg.bcsrrwheelspdvd);
        obj["bcsrrwheeldirectionvd"] = (msg.bcsrrwheeldirectionvd);
        obj["bcsrlwheelspdvd"] = (msg.bcsrlwheelspdvd);
        obj["bcsrlwheeldirectionvd"] = (msg.bcsrlwheeldirectionvd);
        obj["bcsfrwheelspdvd"] = (msg.bcsfrwheelspdvd);
        obj["bcsfrwheeldirectionvd"] = (msg.bcsfrwheeldirectionvd);
        obj["bcsflwheelspdvd"] = (msg.bcsflwheelspdvd);
        obj["bcsflwheeldirectionvd"] = (msg.bcsflwheeldirectionvd);
        obj["bcsrrwheelspd"] = (msg.bcsrrwheelspd);
        obj["bcsrrwheeldirection"] = (msg.bcsrrwheeldirection);
        obj["bcsrlwheelspd"] = (msg.bcsrlwheelspd);
        obj["bcsrlwheeldirection"] = (msg.bcsrlwheeldirection);
        obj["bcsfrwheelspd"] = (msg.bcsfrwheelspd);
        obj["bcsfrwheeldirection"] = (msg.bcsfrwheeldirection);
        obj["bcsflwheelspd"] = (msg.bcsflwheelspd);
        obj["bcsflwheeldirection"] = (msg.bcsflwheeldirection);
        return obj;
    }
    ApollocanbusScuBcs3308 from_json_ApollocanbusScuBcs3308 (nlohmann::json obj) {
        ApollocanbusScuBcs3308 msg;
        if(obj.contains("bcsrrwheelspdvd"))
        {
            msg.bcsrrwheelspdvd = (obj["bcsrrwheelspdvd"].is_string()?atoi(obj["bcsrrwheelspdvd"].get<std::string>().c_str()):obj["bcsrrwheelspdvd"].get<int>());
        }
        if(obj.contains("bcsrrwheeldirectionvd"))
        {
            msg.bcsrrwheeldirectionvd = (obj["bcsrrwheeldirectionvd"].is_string()?atoi(obj["bcsrrwheeldirectionvd"].get<std::string>().c_str()):obj["bcsrrwheeldirectionvd"].get<int>());
        }
        if(obj.contains("bcsrlwheelspdvd"))
        {
            msg.bcsrlwheelspdvd = (obj["bcsrlwheelspdvd"].is_string()?atoi(obj["bcsrlwheelspdvd"].get<std::string>().c_str()):obj["bcsrlwheelspdvd"].get<int>());
        }
        if(obj.contains("bcsrlwheeldirectionvd"))
        {
            msg.bcsrlwheeldirectionvd = (obj["bcsrlwheeldirectionvd"].is_string()?atoi(obj["bcsrlwheeldirectionvd"].get<std::string>().c_str()):obj["bcsrlwheeldirectionvd"].get<int>());
        }
        if(obj.contains("bcsfrwheelspdvd"))
        {
            msg.bcsfrwheelspdvd = (obj["bcsfrwheelspdvd"].is_string()?atoi(obj["bcsfrwheelspdvd"].get<std::string>().c_str()):obj["bcsfrwheelspdvd"].get<int>());
        }
        if(obj.contains("bcsfrwheeldirectionvd"))
        {
            msg.bcsfrwheeldirectionvd = (obj["bcsfrwheeldirectionvd"].is_string()?atoi(obj["bcsfrwheeldirectionvd"].get<std::string>().c_str()):obj["bcsfrwheeldirectionvd"].get<int>());
        }
        if(obj.contains("bcsflwheelspdvd"))
        {
            msg.bcsflwheelspdvd = (obj["bcsflwheelspdvd"].is_string()?atoi(obj["bcsflwheelspdvd"].get<std::string>().c_str()):obj["bcsflwheelspdvd"].get<int>());
        }
        if(obj.contains("bcsflwheeldirectionvd"))
        {
            msg.bcsflwheeldirectionvd = (obj["bcsflwheeldirectionvd"].is_string()?atoi(obj["bcsflwheeldirectionvd"].get<std::string>().c_str()):obj["bcsflwheeldirectionvd"].get<int>());
        }
        if(obj.contains("bcsrrwheelspd"))
        {
            msg.bcsrrwheelspd = (obj["bcsrrwheelspd"].is_string()?atof(obj["bcsrrwheelspd"].get<std::string>().c_str()):obj["bcsrrwheelspd"].get<double>());
        }
        if(obj.contains("bcsrrwheeldirection"))
        {
            msg.bcsrrwheeldirection = (obj["bcsrrwheeldirection"].is_string()?atoi(obj["bcsrrwheeldirection"].get<std::string>().c_str()):obj["bcsrrwheeldirection"].get<int>());
        }
        if(obj.contains("bcsrlwheelspd"))
        {
            msg.bcsrlwheelspd = (obj["bcsrlwheelspd"].is_string()?atof(obj["bcsrlwheelspd"].get<std::string>().c_str()):obj["bcsrlwheelspd"].get<double>());
        }
        if(obj.contains("bcsrlwheeldirection"))
        {
            msg.bcsrlwheeldirection = (obj["bcsrlwheeldirection"].is_string()?atoi(obj["bcsrlwheeldirection"].get<std::string>().c_str()):obj["bcsrlwheeldirection"].get<int>());
        }
        if(obj.contains("bcsfrwheelspd"))
        {
            msg.bcsfrwheelspd = (obj["bcsfrwheelspd"].is_string()?atof(obj["bcsfrwheelspd"].get<std::string>().c_str()):obj["bcsfrwheelspd"].get<double>());
        }
        if(obj.contains("bcsfrwheeldirection"))
        {
            msg.bcsfrwheeldirection = (obj["bcsfrwheeldirection"].is_string()?atoi(obj["bcsfrwheeldirection"].get<std::string>().c_str()):obj["bcsfrwheeldirection"].get<int>());
        }
        if(obj.contains("bcsflwheelspd"))
        {
            msg.bcsflwheelspd = (obj["bcsflwheelspd"].is_string()?atof(obj["bcsflwheelspd"].get<std::string>().c_str()):obj["bcsflwheelspd"].get<double>());
        }
        if(obj.contains("bcsflwheeldirection"))
        {
            msg.bcsflwheeldirection = (obj["bcsflwheeldirection"].is_string()?atoi(obj["bcsflwheeldirection"].get<std::string>().c_str()):obj["bcsflwheeldirection"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusScuBcs3308 from_json<ApollocanbusScuBcs3308>(nlohmann::json obj){
        return from_json_ApollocanbusScuBcs3308(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuBcs3308 &dt)
    {
        dt=from_json_ApollocanbusScuBcs3308(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuBcs3308 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuBcs3308 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
