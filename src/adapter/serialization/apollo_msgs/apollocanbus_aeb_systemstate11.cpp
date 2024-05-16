#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_systemstate11.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebSystemstate11 &msg) {
        nlohmann::json obj;
        obj["aebstate"] = (msg.aebstate);
        obj["aebbrakestate"] = (msg.aebbrakestate);
        obj["faultrank"] = (msg.faultrank);
        obj["currenttemperature"] = (msg.currenttemperature);
        obj["pasf1stop"] = (msg.pasf1stop);
        obj["pasf2stop"] = (msg.pasf2stop);
        obj["pasf3stop"] = (msg.pasf3stop);
        obj["pasf4stop"] = (msg.pasf4stop);
        obj["pasb1stop"] = (msg.pasb1stop);
        obj["pasb2stop"] = (msg.pasb2stop);
        obj["pasb3stop"] = (msg.pasb3stop);
        obj["pasb4stop"] = (msg.pasb4stop);
        obj["aeblivecounterrear"] = (msg.aeblivecounterrear);
        obj["aebcheksum"] = (msg.aebcheksum);
        return obj;
    }
    ApollocanbusAebSystemstate11 from_json_ApollocanbusAebSystemstate11 (nlohmann::json obj) {
        ApollocanbusAebSystemstate11 msg;
        if(obj.contains("aebstate"))
        {
            msg.aebstate = (obj["aebstate"].is_string()?atoi(obj["aebstate"].get<std::string>().c_str()):obj["aebstate"].get<int>());
        }
        if(obj.contains("aebbrakestate"))
        {
            msg.aebbrakestate = (obj["aebbrakestate"].is_string()?(bool)atoi(obj["aebbrakestate"].get<std::string>().c_str()):obj["aebbrakestate"].get<bool>());
        }
        if(obj.contains("faultrank"))
        {
            msg.faultrank = (obj["faultrank"].is_string()?atoi(obj["faultrank"].get<std::string>().c_str()):obj["faultrank"].get<int>());
        }
        if(obj.contains("currenttemperature"))
        {
            msg.currenttemperature = (obj["currenttemperature"].is_string()?atoi(obj["currenttemperature"].get<std::string>().c_str()):obj["currenttemperature"].get<int>());
        }
        if(obj.contains("pasf1stop"))
        {
            msg.pasf1stop = (obj["pasf1stop"].is_string()?(bool)atoi(obj["pasf1stop"].get<std::string>().c_str()):obj["pasf1stop"].get<bool>());
        }
        if(obj.contains("pasf2stop"))
        {
            msg.pasf2stop = (obj["pasf2stop"].is_string()?(bool)atoi(obj["pasf2stop"].get<std::string>().c_str()):obj["pasf2stop"].get<bool>());
        }
        if(obj.contains("pasf3stop"))
        {
            msg.pasf3stop = (obj["pasf3stop"].is_string()?(bool)atoi(obj["pasf3stop"].get<std::string>().c_str()):obj["pasf3stop"].get<bool>());
        }
        if(obj.contains("pasf4stop"))
        {
            msg.pasf4stop = (obj["pasf4stop"].is_string()?(bool)atoi(obj["pasf4stop"].get<std::string>().c_str()):obj["pasf4stop"].get<bool>());
        }
        if(obj.contains("pasb1stop"))
        {
            msg.pasb1stop = (obj["pasb1stop"].is_string()?(bool)atoi(obj["pasb1stop"].get<std::string>().c_str()):obj["pasb1stop"].get<bool>());
        }
        if(obj.contains("pasb2stop"))
        {
            msg.pasb2stop = (obj["pasb2stop"].is_string()?(bool)atoi(obj["pasb2stop"].get<std::string>().c_str()):obj["pasb2stop"].get<bool>());
        }
        if(obj.contains("pasb3stop"))
        {
            msg.pasb3stop = (obj["pasb3stop"].is_string()?(bool)atoi(obj["pasb3stop"].get<std::string>().c_str()):obj["pasb3stop"].get<bool>());
        }
        if(obj.contains("pasb4stop"))
        {
            msg.pasb4stop = (obj["pasb4stop"].is_string()?(bool)atoi(obj["pasb4stop"].get<std::string>().c_str()):obj["pasb4stop"].get<bool>());
        }
        if(obj.contains("aeblivecounterrear"))
        {
            msg.aeblivecounterrear = (obj["aeblivecounterrear"].is_string()?atoi(obj["aeblivecounterrear"].get<std::string>().c_str()):obj["aeblivecounterrear"].get<int>());
        }
        if(obj.contains("aebcheksum"))
        {
            msg.aebcheksum = (obj["aebcheksum"].is_string()?atoi(obj["aebcheksum"].get<std::string>().c_str()):obj["aebcheksum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusAebSystemstate11 from_json<ApollocanbusAebSystemstate11>(nlohmann::json obj){
        return from_json_ApollocanbusAebSystemstate11(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebSystemstate11 &dt)
    {
        dt=from_json_ApollocanbusAebSystemstate11(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebSystemstate11 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebSystemstate11 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
