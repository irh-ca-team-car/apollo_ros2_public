#include "adapter/serialization/apollo_msgs/apollodrivers_details739.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDetails739 &msg) {
        nlohmann::json obj;
        obj["obstacleid"] = (msg.obstacleid);
        obj["obstacleposx"] = (msg.obstacleposx);
        obj["reseved2"] = (msg.reseved2);
        obj["obstacleposy"] = (msg.obstacleposy);
        obj["blinkerinfo"] = (msg.blinkerinfo);
        obj["cutinandout"] = (msg.cutinandout);
        obj["obstaclerelvelx"] = (msg.obstaclerelvelx);
        obj["obstacletype"] = (msg.obstacletype);
        obj["reserved3"] = (msg.reserved3);
        obj["obstaclestatus"] = (msg.obstaclestatus);
        obj["obstaclebrakelights"] = (msg.obstaclebrakelights);
        obj["reserved4"] = (msg.reserved4);
        obj["obstaclevalid"] = (msg.obstaclevalid);
        return obj;
    }
    ApollodriversDetails739 from_json_ApollodriversDetails739 (nlohmann::json obj) {
        ApollodriversDetails739 msg;
        if(obj.contains("obstacleid"))
        {
            msg.obstacleid = (obj["obstacleid"].is_string()?atoi(obj["obstacleid"].get<std::string>().c_str()):obj["obstacleid"].get<int>());
        }
        if(obj.contains("obstacleposx"))
        {
            msg.obstacleposx = (obj["obstacleposx"].is_string()?atof(obj["obstacleposx"].get<std::string>().c_str()):obj["obstacleposx"].get<double>());
        }
        if(obj.contains("reseved2"))
        {
            msg.reseved2 = (obj["reseved2"].is_string()?atoi(obj["reseved2"].get<std::string>().c_str()):obj["reseved2"].get<int>());
        }
        if(obj.contains("obstacleposy"))
        {
            msg.obstacleposy = (obj["obstacleposy"].is_string()?atof(obj["obstacleposy"].get<std::string>().c_str()):obj["obstacleposy"].get<double>());
        }
        if(obj.contains("blinkerinfo"))
        {
            msg.blinkerinfo = (obj["blinkerinfo"].is_string()?atoi(obj["blinkerinfo"].get<std::string>().c_str()):obj["blinkerinfo"].get<int>());
        }
        if(obj.contains("cutinandout"))
        {
            msg.cutinandout = (obj["cutinandout"].is_string()?atoi(obj["cutinandout"].get<std::string>().c_str()):obj["cutinandout"].get<int>());
        }
        if(obj.contains("obstaclerelvelx"))
        {
            msg.obstaclerelvelx = (obj["obstaclerelvelx"].is_string()?atof(obj["obstaclerelvelx"].get<std::string>().c_str()):obj["obstaclerelvelx"].get<double>());
        }
        if(obj.contains("obstacletype"))
        {
            msg.obstacletype = (obj["obstacletype"].is_string()?atoi(obj["obstacletype"].get<std::string>().c_str()):obj["obstacletype"].get<int>());
        }
        if(obj.contains("reserved3"))
        {
            msg.reserved3 = (obj["reserved3"].is_string()?(bool)atoi(obj["reserved3"].get<std::string>().c_str()):obj["reserved3"].get<bool>());
        }
        if(obj.contains("obstaclestatus"))
        {
            msg.obstaclestatus = (obj["obstaclestatus"].is_string()?atoi(obj["obstaclestatus"].get<std::string>().c_str()):obj["obstaclestatus"].get<int>());
        }
        if(obj.contains("obstaclebrakelights"))
        {
            msg.obstaclebrakelights = (obj["obstaclebrakelights"].is_string()?(bool)atoi(obj["obstaclebrakelights"].get<std::string>().c_str()):obj["obstaclebrakelights"].get<bool>());
        }
        if(obj.contains("reserved4"))
        {
            msg.reserved4 = (obj["reserved4"].is_string()?atoi(obj["reserved4"].get<std::string>().c_str()):obj["reserved4"].get<int>());
        }
        if(obj.contains("obstaclevalid"))
        {
            msg.obstaclevalid = (obj["obstaclevalid"].is_string()?atoi(obj["obstaclevalid"].get<std::string>().c_str()):obj["obstaclevalid"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversDetails739 from_json<ApollodriversDetails739>(nlohmann::json obj){
        return from_json_ApollodriversDetails739(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDetails739 &dt)
    {
        dt=from_json_ApollodriversDetails739(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversDetails739 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDetails739 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
