#include "adapter/serialization/apollo_msgs/apollocanbus_ads_shifter115.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsShifter115 &msg) {
        nlohmann::json obj;
        obj["adsshiftmode"] = (msg.adsshiftmode);
        obj["adstargetgear"] = (msg.adstargetgear);
        return obj;
    }
    ApollocanbusAdsShifter115 from_json_ApollocanbusAdsShifter115 (nlohmann::json obj) {
        ApollocanbusAdsShifter115 msg;
        if(obj.contains("adsshiftmode"))
        {
            msg.adsshiftmode = (obj["adsshiftmode"].is_string()?atoi(obj["adsshiftmode"].get<std::string>().c_str()):obj["adsshiftmode"].get<int>());
        }
        if(obj.contains("adstargetgear"))
        {
            msg.adstargetgear = (obj["adstargetgear"].is_string()?atoi(obj["adstargetgear"].get<std::string>().c_str()):obj["adstargetgear"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusAdsShifter115 from_json<ApollocanbusAdsShifter115>(nlohmann::json obj){
        return from_json_ApollocanbusAdsShifter115(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsShifter115 &dt)
    {
        dt=from_json_ApollocanbusAdsShifter115(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsShifter115 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsShifter115 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
