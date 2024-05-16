#include "adapter/serialization/apollo_msgs/apollocanbus_ads_light_horn_command310.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsLightHornCommand310 &msg) {
        nlohmann::json obj;
        obj["turnrightlightcommand"] = (msg.turnrightlightcommand);
        obj["turnleftlightcommand"] = (msg.turnleftlightcommand);
        obj["horncommand"] = (msg.horncommand);
        obj["beamcommand"] = (msg.beamcommand);
        obj["autodrivercmdalivecounter"] = (msg.autodrivercmdalivecounter);
        obj["autodrivercmdchecksum"] = (msg.autodrivercmdchecksum);
        return obj;
    }
    ApollocanbusAdsLightHornCommand310 from_json_ApollocanbusAdsLightHornCommand310 (nlohmann::json obj) {
        ApollocanbusAdsLightHornCommand310 msg;
        if(obj.contains("turnrightlightcommand"))
        {
            msg.turnrightlightcommand = (obj["turnrightlightcommand"].is_string()?(bool)atoi(obj["turnrightlightcommand"].get<std::string>().c_str()):obj["turnrightlightcommand"].get<bool>());
        }
        if(obj.contains("turnleftlightcommand"))
        {
            msg.turnleftlightcommand = (obj["turnleftlightcommand"].is_string()?(bool)atoi(obj["turnleftlightcommand"].get<std::string>().c_str()):obj["turnleftlightcommand"].get<bool>());
        }
        if(obj.contains("horncommand"))
        {
            msg.horncommand = (obj["horncommand"].is_string()?(bool)atoi(obj["horncommand"].get<std::string>().c_str()):obj["horncommand"].get<bool>());
        }
        if(obj.contains("beamcommand"))
        {
            msg.beamcommand = (obj["beamcommand"].is_string()?atoi(obj["beamcommand"].get<std::string>().c_str()):obj["beamcommand"].get<int>());
        }
        if(obj.contains("autodrivercmdalivecounter"))
        {
            msg.autodrivercmdalivecounter = (obj["autodrivercmdalivecounter"].is_string()?atoi(obj["autodrivercmdalivecounter"].get<std::string>().c_str()):obj["autodrivercmdalivecounter"].get<int>());
        }
        if(obj.contains("autodrivercmdchecksum"))
        {
            msg.autodrivercmdchecksum = (obj["autodrivercmdchecksum"].is_string()?atoi(obj["autodrivercmdchecksum"].get<std::string>().c_str()):obj["autodrivercmdchecksum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusAdsLightHornCommand310 from_json<ApollocanbusAdsLightHornCommand310>(nlohmann::json obj){
        return from_json_ApollocanbusAdsLightHornCommand310(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsLightHornCommand310 &dt)
    {
        dt=from_json_ApollocanbusAdsLightHornCommand310(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsLightHornCommand310 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsLightHornCommand310 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
