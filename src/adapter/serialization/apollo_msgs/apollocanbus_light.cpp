#include "adapter/serialization/apollo_msgs/apollocanbus_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLight &msg) {
        nlohmann::json obj;
        obj["turnlighttype"] = (msg.turnlighttype);
        obj["beamlamptype"] = (msg.beamlamptype);
        obj["isbrakelampon"] = (msg.isbrakelampon);
        obj["isautolight"] = (msg.isautolight);
        obj["wipergear"] = (msg.wipergear);
        obj["lotiongear"] = (msg.lotiongear);
        obj["ishornon"] = (msg.ishornon);
        obj["lincolnlamptype"] = (msg.lincolnlamptype);
        obj["lincolnwiper"] = (msg.lincolnwiper);
        obj["lincolnambient"] = (msg.lincolnambient);
        return obj;
    }
    ApollocanbusLight from_json_ApollocanbusLight (nlohmann::json obj) {
        ApollocanbusLight msg;
        if(obj.contains("turnlighttype"))
        {
            msg.turnlighttype = (obj["turnlighttype"].is_string()?atoi(obj["turnlighttype"].get<std::string>().c_str()):obj["turnlighttype"].get<int>());
        }
        if(obj.contains("beamlamptype"))
        {
            msg.beamlamptype = (obj["beamlamptype"].is_string()?atoi(obj["beamlamptype"].get<std::string>().c_str()):obj["beamlamptype"].get<int>());
        }
        if(obj.contains("isbrakelampon"))
        {
            msg.isbrakelampon = (obj["isbrakelampon"].is_string()?(bool)atoi(obj["isbrakelampon"].get<std::string>().c_str()):obj["isbrakelampon"].get<bool>());
        }
        if(obj.contains("isautolight"))
        {
            msg.isautolight = (obj["isautolight"].is_string()?(bool)atoi(obj["isautolight"].get<std::string>().c_str()):obj["isautolight"].get<bool>());
        }
        if(obj.contains("wipergear"))
        {
            msg.wipergear = (obj["wipergear"].is_string()?atoi(obj["wipergear"].get<std::string>().c_str()):obj["wipergear"].get<int>());
        }
        if(obj.contains("lotiongear"))
        {
            msg.lotiongear = (obj["lotiongear"].is_string()?atoi(obj["lotiongear"].get<std::string>().c_str()):obj["lotiongear"].get<int>());
        }
        if(obj.contains("ishornon"))
        {
            msg.ishornon = (obj["ishornon"].is_string()?(bool)atoi(obj["ishornon"].get<std::string>().c_str()):obj["ishornon"].get<bool>());
        }
        if(obj.contains("lincolnlamptype"))
        {
            msg.lincolnlamptype = (obj["lincolnlamptype"].is_string()?atoi(obj["lincolnlamptype"].get<std::string>().c_str()):obj["lincolnlamptype"].get<int>());
        }
        if(obj.contains("lincolnwiper"))
        {
            msg.lincolnwiper = (obj["lincolnwiper"].is_string()?atoi(obj["lincolnwiper"].get<std::string>().c_str()):obj["lincolnwiper"].get<int>());
        }
        if(obj.contains("lincolnambient"))
        {
            msg.lincolnambient = (obj["lincolnambient"].is_string()?atoi(obj["lincolnambient"].get<std::string>().c_str()):obj["lincolnambient"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusLight from_json<ApollocanbusLight>(nlohmann::json obj){
        return from_json_ApollocanbusLight(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLight &dt)
    {
        dt=from_json_ApollocanbusLight(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLight & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLight & dt)
    {
        os << to_json(dt);
        return os;
    }
}
