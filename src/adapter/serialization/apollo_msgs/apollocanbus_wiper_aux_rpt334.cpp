#include "adapter/serialization/apollo_msgs/apollocanbus_wiper_aux_rpt334.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWiperAuxRpt334 &msg) {
        nlohmann::json obj;
        obj["sprayemptyisvalid"] = (msg.sprayemptyisvalid);
        obj["sprayempty"] = (msg.sprayempty);
        obj["spraynearemptyisvalid"] = (msg.spraynearemptyisvalid);
        obj["spraynearempty"] = (msg.spraynearempty);
        obj["rearsprayingisvalid"] = (msg.rearsprayingisvalid);
        obj["rearspraying"] = (msg.rearspraying);
        obj["rearwipingisvalid"] = (msg.rearwipingisvalid);
        obj["rearwiping"] = (msg.rearwiping);
        obj["frontsprayingisvalid"] = (msg.frontsprayingisvalid);
        obj["frontspraying"] = (msg.frontspraying);
        obj["frontwipingisvalid"] = (msg.frontwipingisvalid);
        obj["frontwiping"] = (msg.frontwiping);
        return obj;
    }
    ApollocanbusWiperAuxRpt334 from_json_ApollocanbusWiperAuxRpt334 (nlohmann::json obj) {
        ApollocanbusWiperAuxRpt334 msg;
        if(obj.contains("sprayemptyisvalid"))
        {
            msg.sprayemptyisvalid = (obj["sprayemptyisvalid"].is_string()?(bool)atoi(obj["sprayemptyisvalid"].get<std::string>().c_str()):obj["sprayemptyisvalid"].get<bool>());
        }
        if(obj.contains("sprayempty"))
        {
            msg.sprayempty = (obj["sprayempty"].is_string()?(bool)atoi(obj["sprayempty"].get<std::string>().c_str()):obj["sprayempty"].get<bool>());
        }
        if(obj.contains("spraynearemptyisvalid"))
        {
            msg.spraynearemptyisvalid = (obj["spraynearemptyisvalid"].is_string()?(bool)atoi(obj["spraynearemptyisvalid"].get<std::string>().c_str()):obj["spraynearemptyisvalid"].get<bool>());
        }
        if(obj.contains("spraynearempty"))
        {
            msg.spraynearempty = (obj["spraynearempty"].is_string()?(bool)atoi(obj["spraynearempty"].get<std::string>().c_str()):obj["spraynearempty"].get<bool>());
        }
        if(obj.contains("rearsprayingisvalid"))
        {
            msg.rearsprayingisvalid = (obj["rearsprayingisvalid"].is_string()?(bool)atoi(obj["rearsprayingisvalid"].get<std::string>().c_str()):obj["rearsprayingisvalid"].get<bool>());
        }
        if(obj.contains("rearspraying"))
        {
            msg.rearspraying = (obj["rearspraying"].is_string()?(bool)atoi(obj["rearspraying"].get<std::string>().c_str()):obj["rearspraying"].get<bool>());
        }
        if(obj.contains("rearwipingisvalid"))
        {
            msg.rearwipingisvalid = (obj["rearwipingisvalid"].is_string()?(bool)atoi(obj["rearwipingisvalid"].get<std::string>().c_str()):obj["rearwipingisvalid"].get<bool>());
        }
        if(obj.contains("rearwiping"))
        {
            msg.rearwiping = (obj["rearwiping"].is_string()?(bool)atoi(obj["rearwiping"].get<std::string>().c_str()):obj["rearwiping"].get<bool>());
        }
        if(obj.contains("frontsprayingisvalid"))
        {
            msg.frontsprayingisvalid = (obj["frontsprayingisvalid"].is_string()?(bool)atoi(obj["frontsprayingisvalid"].get<std::string>().c_str()):obj["frontsprayingisvalid"].get<bool>());
        }
        if(obj.contains("frontspraying"))
        {
            msg.frontspraying = (obj["frontspraying"].is_string()?(bool)atoi(obj["frontspraying"].get<std::string>().c_str()):obj["frontspraying"].get<bool>());
        }
        if(obj.contains("frontwipingisvalid"))
        {
            msg.frontwipingisvalid = (obj["frontwipingisvalid"].is_string()?(bool)atoi(obj["frontwipingisvalid"].get<std::string>().c_str()):obj["frontwipingisvalid"].get<bool>());
        }
        if(obj.contains("frontwiping"))
        {
            msg.frontwiping = (obj["frontwiping"].is_string()?(bool)atoi(obj["frontwiping"].get<std::string>().c_str()):obj["frontwiping"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusWiperAuxRpt334 from_json<ApollocanbusWiperAuxRpt334>(nlohmann::json obj){
        return from_json_ApollocanbusWiperAuxRpt334(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWiperAuxRpt334 &dt)
    {
        dt=from_json_ApollocanbusWiperAuxRpt334(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWiperAuxRpt334 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWiperAuxRpt334 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
