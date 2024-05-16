#include "adapter/serialization/apollo_msgs/apollocanbus_check_response_signal.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusCheckResponseSignal &msg) {
        nlohmann::json obj;
        obj["isepsonline"] = (msg.isepsonline);
        obj["isepbonline"] = (msg.isepbonline);
        obj["isesponline"] = (msg.isesponline);
        obj["isvtogonline"] = (msg.isvtogonline);
        obj["isscuonline"] = (msg.isscuonline);
        obj["isswitchonline"] = (msg.isswitchonline);
        obj["isvcuonline"] = (msg.isvcuonline);
        return obj;
    }
    ApollocanbusCheckResponseSignal from_json_ApollocanbusCheckResponseSignal (nlohmann::json obj) {
        ApollocanbusCheckResponseSignal msg;
        if(obj.contains("isepsonline"))
        {
            msg.isepsonline = (obj["isepsonline"].is_string()?(bool)atoi(obj["isepsonline"].get<std::string>().c_str()):obj["isepsonline"].get<bool>());
        }
        if(obj.contains("isepbonline"))
        {
            msg.isepbonline = (obj["isepbonline"].is_string()?(bool)atoi(obj["isepbonline"].get<std::string>().c_str()):obj["isepbonline"].get<bool>());
        }
        if(obj.contains("isesponline"))
        {
            msg.isesponline = (obj["isesponline"].is_string()?(bool)atoi(obj["isesponline"].get<std::string>().c_str()):obj["isesponline"].get<bool>());
        }
        if(obj.contains("isvtogonline"))
        {
            msg.isvtogonline = (obj["isvtogonline"].is_string()?(bool)atoi(obj["isvtogonline"].get<std::string>().c_str()):obj["isvtogonline"].get<bool>());
        }
        if(obj.contains("isscuonline"))
        {
            msg.isscuonline = (obj["isscuonline"].is_string()?(bool)atoi(obj["isscuonline"].get<std::string>().c_str()):obj["isscuonline"].get<bool>());
        }
        if(obj.contains("isswitchonline"))
        {
            msg.isswitchonline = (obj["isswitchonline"].is_string()?(bool)atoi(obj["isswitchonline"].get<std::string>().c_str()):obj["isswitchonline"].get<bool>());
        }
        if(obj.contains("isvcuonline"))
        {
            msg.isvcuonline = (obj["isvcuonline"].is_string()?(bool)atoi(obj["isvcuonline"].get<std::string>().c_str()):obj["isvcuonline"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusCheckResponseSignal from_json<ApollocanbusCheckResponseSignal>(nlohmann::json obj){
        return from_json_ApollocanbusCheckResponseSignal(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusCheckResponseSignal &dt)
    {
        dt=from_json_ApollocanbusCheckResponseSignal(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusCheckResponseSignal & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusCheckResponseSignal & dt)
    {
        os << to_json(dt);
        return os;
    }
}
