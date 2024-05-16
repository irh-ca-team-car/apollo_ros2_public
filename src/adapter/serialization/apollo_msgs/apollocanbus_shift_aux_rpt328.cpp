#include "adapter/serialization/apollo_msgs/apollocanbus_shift_aux_rpt328.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusShiftAuxRpt328 &msg) {
        nlohmann::json obj;
        obj["speedinterlockactiveisvalid"] = (msg.speedinterlockactiveisvalid);
        obj["speedinterlockactive"] = (msg.speedinterlockactive);
        obj["brakeinterlockactiveisvalid"] = (msg.brakeinterlockactiveisvalid);
        obj["brakeinterlockactive"] = (msg.brakeinterlockactive);
        obj["stayinneutralmodeisvalid"] = (msg.stayinneutralmodeisvalid);
        obj["stayinneutralmode"] = (msg.stayinneutralmode);
        obj["betweengearsisvalid"] = (msg.betweengearsisvalid);
        obj["betweengears"] = (msg.betweengears);
        return obj;
    }
    ApollocanbusShiftAuxRpt328 from_json_ApollocanbusShiftAuxRpt328 (nlohmann::json obj) {
        ApollocanbusShiftAuxRpt328 msg;
        if(obj.contains("speedinterlockactiveisvalid"))
        {
            msg.speedinterlockactiveisvalid = (obj["speedinterlockactiveisvalid"].is_string()?(bool)atoi(obj["speedinterlockactiveisvalid"].get<std::string>().c_str()):obj["speedinterlockactiveisvalid"].get<bool>());
        }
        if(obj.contains("speedinterlockactive"))
        {
            msg.speedinterlockactive = (obj["speedinterlockactive"].is_string()?(bool)atoi(obj["speedinterlockactive"].get<std::string>().c_str()):obj["speedinterlockactive"].get<bool>());
        }
        if(obj.contains("brakeinterlockactiveisvalid"))
        {
            msg.brakeinterlockactiveisvalid = (obj["brakeinterlockactiveisvalid"].is_string()?(bool)atoi(obj["brakeinterlockactiveisvalid"].get<std::string>().c_str()):obj["brakeinterlockactiveisvalid"].get<bool>());
        }
        if(obj.contains("brakeinterlockactive"))
        {
            msg.brakeinterlockactive = (obj["brakeinterlockactive"].is_string()?(bool)atoi(obj["brakeinterlockactive"].get<std::string>().c_str()):obj["brakeinterlockactive"].get<bool>());
        }
        if(obj.contains("stayinneutralmodeisvalid"))
        {
            msg.stayinneutralmodeisvalid = (obj["stayinneutralmodeisvalid"].is_string()?(bool)atoi(obj["stayinneutralmodeisvalid"].get<std::string>().c_str()):obj["stayinneutralmodeisvalid"].get<bool>());
        }
        if(obj.contains("stayinneutralmode"))
        {
            msg.stayinneutralmode = (obj["stayinneutralmode"].is_string()?(bool)atoi(obj["stayinneutralmode"].get<std::string>().c_str()):obj["stayinneutralmode"].get<bool>());
        }
        if(obj.contains("betweengearsisvalid"))
        {
            msg.betweengearsisvalid = (obj["betweengearsisvalid"].is_string()?(bool)atoi(obj["betweengearsisvalid"].get<std::string>().c_str()):obj["betweengearsisvalid"].get<bool>());
        }
        if(obj.contains("betweengears"))
        {
            msg.betweengears = (obj["betweengears"].is_string()?(bool)atoi(obj["betweengears"].get<std::string>().c_str()):obj["betweengears"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusShiftAuxRpt328 from_json<ApollocanbusShiftAuxRpt328>(nlohmann::json obj){
        return from_json_ApollocanbusShiftAuxRpt328(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusShiftAuxRpt328 &dt)
    {
        dt=from_json_ApollocanbusShiftAuxRpt328(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusShiftAuxRpt328 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusShiftAuxRpt328 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
