#include "adapter/serialization/apollo_msgs/apollocanbus_wey.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWey &msg) {
        nlohmann::json obj;
        obj["adsshifter115"] = to_json(msg.adsshifter115);
        obj["adseps113"] = to_json(msg.adseps113);
        obj["status310"] = to_json(msg.status310);
        obj["vinresp3393"] = to_json(msg.vinresp3393);
        obj["vinresp2392"] = to_json(msg.vinresp2392);
        obj["vinresp1391"] = to_json(msg.vinresp1391);
        obj["adsreqvin390"] = to_json(msg.adsreqvin390);
        obj["ads1111"] = to_json(msg.ads1111);
        obj["fbs2240"] = to_json(msg.fbs2240);
        obj["fbs1243"] = to_json(msg.fbs1243);
        obj["fbs4235"] = to_json(msg.fbs4235);
        obj["fail241"] = to_json(msg.fail241);
        obj["fbs3237"] = to_json(msg.fbs3237);
        obj["ads338e"] = to_json(msg.ads338e);
        return obj;
    }
    ApollocanbusWey from_json_ApollocanbusWey (nlohmann::json obj) {
        ApollocanbusWey msg;
        if(obj.contains("adsshifter115"))
        {
            msg.adsshifter115 = from_json_ApollocanbusAdsShifter115(obj["adsshifter115"]);
        }
        if(obj.contains("adseps113"))
        {
            msg.adseps113 = from_json_ApollocanbusAdsEps113(obj["adseps113"]);
        }
        if(obj.contains("status310"))
        {
            msg.status310 = from_json_ApollocanbusStatus310(obj["status310"]);
        }
        if(obj.contains("vinresp3393"))
        {
            msg.vinresp3393 = from_json_ApollocanbusVinResp3393(obj["vinresp3393"]);
        }
        if(obj.contains("vinresp2392"))
        {
            msg.vinresp2392 = from_json_ApollocanbusVinResp2392(obj["vinresp2392"]);
        }
        if(obj.contains("vinresp1391"))
        {
            msg.vinresp1391 = from_json_ApollocanbusVinResp1391(obj["vinresp1391"]);
        }
        if(obj.contains("adsreqvin390"))
        {
            msg.adsreqvin390 = from_json_ApollocanbusAdsReqVin390(obj["adsreqvin390"]);
        }
        if(obj.contains("ads1111"))
        {
            msg.ads1111 = from_json_ApollocanbusAds1111(obj["ads1111"]);
        }
        if(obj.contains("fbs2240"))
        {
            msg.fbs2240 = from_json_ApollocanbusFbs2240(obj["fbs2240"]);
        }
        if(obj.contains("fbs1243"))
        {
            msg.fbs1243 = from_json_ApollocanbusFbs1243(obj["fbs1243"]);
        }
        if(obj.contains("fbs4235"))
        {
            msg.fbs4235 = from_json_ApollocanbusFbs4235(obj["fbs4235"]);
        }
        if(obj.contains("fail241"))
        {
            msg.fail241 = from_json_ApollocanbusFail241(obj["fail241"]);
        }
        if(obj.contains("fbs3237"))
        {
            msg.fbs3237 = from_json_ApollocanbusFbs3237(obj["fbs3237"]);
        }
        if(obj.contains("ads338e"))
        {
            msg.ads338e = from_json_ApollocanbusAds338e(obj["ads338e"]);
        }
        return msg;
    }
    template <>
    ApollocanbusWey from_json<ApollocanbusWey>(nlohmann::json obj){
        return from_json_ApollocanbusWey(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWey &dt)
    {
        dt=from_json_ApollocanbusWey(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWey & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWey & dt)
    {
        os << to_json(dt);
        return os;
    }
}
