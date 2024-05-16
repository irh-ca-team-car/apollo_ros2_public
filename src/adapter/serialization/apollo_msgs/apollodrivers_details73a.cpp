#include "adapter/serialization/apollo_msgs/apollodrivers_details73a.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDetails73a &msg) {
        nlohmann::json obj;
        obj["obstaclelength"] = (msg.obstaclelength);
        obj["obstaclewidth"] = (msg.obstaclewidth);
        obj["obstacleage"] = (msg.obstacleage);
        obj["obstaclelane"] = (msg.obstaclelane);
        obj["cipvflag"] = (msg.cipvflag);
        obj["reserved5"] = (msg.reserved5);
        obj["radarposx"] = (msg.radarposx);
        obj["radarvelx"] = (msg.radarvelx);
        obj["radarmatchconfidence"] = (msg.radarmatchconfidence);
        obj["reserved6"] = (msg.reserved6);
        obj["matchedradarid"] = (msg.matchedradarid);
        obj["reserved7"] = (msg.reserved7);
        return obj;
    }
    ApollodriversDetails73a from_json_ApollodriversDetails73a (nlohmann::json obj) {
        ApollodriversDetails73a msg;
        if(obj.contains("obstaclelength"))
        {
            msg.obstaclelength = (obj["obstaclelength"].is_string()?atof(obj["obstaclelength"].get<std::string>().c_str()):obj["obstaclelength"].get<double>());
        }
        if(obj.contains("obstaclewidth"))
        {
            msg.obstaclewidth = (obj["obstaclewidth"].is_string()?atof(obj["obstaclewidth"].get<std::string>().c_str()):obj["obstaclewidth"].get<double>());
        }
        if(obj.contains("obstacleage"))
        {
            msg.obstacleage = (obj["obstacleage"].is_string()?atoi(obj["obstacleage"].get<std::string>().c_str()):obj["obstacleage"].get<int>());
        }
        if(obj.contains("obstaclelane"))
        {
            msg.obstaclelane = (obj["obstaclelane"].is_string()?atoi(obj["obstaclelane"].get<std::string>().c_str()):obj["obstaclelane"].get<int>());
        }
        if(obj.contains("cipvflag"))
        {
            msg.cipvflag = (obj["cipvflag"].is_string()?(bool)atoi(obj["cipvflag"].get<std::string>().c_str()):obj["cipvflag"].get<bool>());
        }
        if(obj.contains("reserved5"))
        {
            msg.reserved5 = (obj["reserved5"].is_string()?(bool)atoi(obj["reserved5"].get<std::string>().c_str()):obj["reserved5"].get<bool>());
        }
        if(obj.contains("radarposx"))
        {
            msg.radarposx = (obj["radarposx"].is_string()?atof(obj["radarposx"].get<std::string>().c_str()):obj["radarposx"].get<double>());
        }
        if(obj.contains("radarvelx"))
        {
            msg.radarvelx = (obj["radarvelx"].is_string()?atof(obj["radarvelx"].get<std::string>().c_str()):obj["radarvelx"].get<double>());
        }
        if(obj.contains("radarmatchconfidence"))
        {
            msg.radarmatchconfidence = (obj["radarmatchconfidence"].is_string()?atoi(obj["radarmatchconfidence"].get<std::string>().c_str()):obj["radarmatchconfidence"].get<int>());
        }
        if(obj.contains("reserved6"))
        {
            msg.reserved6 = (obj["reserved6"].is_string()?(bool)atoi(obj["reserved6"].get<std::string>().c_str()):obj["reserved6"].get<bool>());
        }
        if(obj.contains("matchedradarid"))
        {
            msg.matchedradarid = (obj["matchedradarid"].is_string()?atoi(obj["matchedradarid"].get<std::string>().c_str()):obj["matchedradarid"].get<int>());
        }
        if(obj.contains("reserved7"))
        {
            msg.reserved7 = (obj["reserved7"].is_string()?(bool)atoi(obj["reserved7"].get<std::string>().c_str()):obj["reserved7"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollodriversDetails73a from_json<ApollodriversDetails73a>(nlohmann::json obj){
        return from_json_ApollodriversDetails73a(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDetails73a &dt)
    {
        dt=from_json_ApollodriversDetails73a(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversDetails73a & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDetails73a & dt)
    {
        os << to_json(dt);
        return os;
    }
}
