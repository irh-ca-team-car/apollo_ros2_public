#include "adapter/serialization/apollo_msgs/apollocanbus_ads_eps113.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsEps113 &msg) {
        nlohmann::json obj;
        obj["adsepsmode"] = (msg.adsepsmode);
        obj["adsreqepstargetangle"] = (msg.adsreqepstargetangle);
        return obj;
    }
    ApollocanbusAdsEps113 from_json_ApollocanbusAdsEps113 (nlohmann::json obj) {
        ApollocanbusAdsEps113 msg;
        if(obj.contains("adsepsmode"))
        {
            msg.adsepsmode = (obj["adsepsmode"].is_string()?atoi(obj["adsepsmode"].get<std::string>().c_str()):obj["adsepsmode"].get<int>());
        }
        if(obj.contains("adsreqepstargetangle"))
        {
            msg.adsreqepstargetangle = (obj["adsreqepstargetangle"].is_string()?atof(obj["adsreqepstargetangle"].get<std::string>().c_str()):obj["adsreqepstargetangle"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusAdsEps113 from_json<ApollocanbusAdsEps113>(nlohmann::json obj){
        return from_json_ApollocanbusAdsEps113(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsEps113 &dt)
    {
        dt=from_json_ApollocanbusAdsEps113(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsEps113 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsEps113 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
