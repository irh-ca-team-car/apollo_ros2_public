#include "adapter/serialization/apollo_msgs/apollocanbus_ads1111.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAds1111 &msg) {
        nlohmann::json obj;
        obj["adsdectostop"] = (msg.adsdectostop);
        obj["adsmode"] = (msg.adsmode);
        obj["adstaracce"] = (msg.adstaracce);
        obj["adsdriveoffreq"] = (msg.adsdriveoffreq);
        obj["adsaebtaracce"] = (msg.adsaebtaracce);
        obj["adsaebtgtdecelreq"] = (msg.adsaebtgtdecelreq);
        return obj;
    }
    ApollocanbusAds1111 from_json_ApollocanbusAds1111 (nlohmann::json obj) {
        ApollocanbusAds1111 msg;
        if(obj.contains("adsdectostop"))
        {
            msg.adsdectostop = (obj["adsdectostop"].is_string()?atoi(obj["adsdectostop"].get<std::string>().c_str()):obj["adsdectostop"].get<int>());
        }
        if(obj.contains("adsmode"))
        {
            msg.adsmode = (obj["adsmode"].is_string()?atoi(obj["adsmode"].get<std::string>().c_str()):obj["adsmode"].get<int>());
        }
        if(obj.contains("adstaracce"))
        {
            msg.adstaracce = (obj["adstaracce"].is_string()?atof(obj["adstaracce"].get<std::string>().c_str()):obj["adstaracce"].get<double>());
        }
        if(obj.contains("adsdriveoffreq"))
        {
            msg.adsdriveoffreq = (obj["adsdriveoffreq"].is_string()?atoi(obj["adsdriveoffreq"].get<std::string>().c_str()):obj["adsdriveoffreq"].get<int>());
        }
        if(obj.contains("adsaebtaracce"))
        {
            msg.adsaebtaracce = (obj["adsaebtaracce"].is_string()?atof(obj["adsaebtaracce"].get<std::string>().c_str()):obj["adsaebtaracce"].get<double>());
        }
        if(obj.contains("adsaebtgtdecelreq"))
        {
            msg.adsaebtgtdecelreq = (obj["adsaebtgtdecelreq"].is_string()?atoi(obj["adsaebtgtdecelreq"].get<std::string>().c_str()):obj["adsaebtgtdecelreq"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusAds1111 from_json<ApollocanbusAds1111>(nlohmann::json obj){
        return from_json_ApollocanbusAds1111(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAds1111 &dt)
    {
        dt=from_json_ApollocanbusAds1111(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAds1111 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAds1111 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
