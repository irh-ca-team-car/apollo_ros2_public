#include "adapter/serialization/apollo_msgs/apollocanbus_ads_eps_command56.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsEpsCommand56 &msg) {
        nlohmann::json obj;
        obj["driveenable"] = (msg.driveenable);
        obj["autotargetangle"] = (msg.autotargetangle);
        obj["autodrivercmdalivecounter"] = (msg.autodrivercmdalivecounter);
        obj["autodrivercmdchecksum"] = (msg.autodrivercmdchecksum);
        return obj;
    }
    ApollocanbusAdsEpsCommand56 from_json_ApollocanbusAdsEpsCommand56 (nlohmann::json obj) {
        ApollocanbusAdsEpsCommand56 msg;
        if(obj.contains("driveenable"))
        {
            msg.driveenable = (obj["driveenable"].is_string()?(bool)atoi(obj["driveenable"].get<std::string>().c_str()):obj["driveenable"].get<bool>());
        }
        if(obj.contains("autotargetangle"))
        {
            msg.autotargetangle = (obj["autotargetangle"].is_string()?atof(obj["autotargetangle"].get<std::string>().c_str()):obj["autotargetangle"].get<double>());
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
    ApollocanbusAdsEpsCommand56 from_json<ApollocanbusAdsEpsCommand56>(nlohmann::json obj){
        return from_json_ApollocanbusAdsEpsCommand56(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsEpsCommand56 &dt)
    {
        dt=from_json_ApollocanbusAdsEpsCommand56(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsEpsCommand56 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsEpsCommand56 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
