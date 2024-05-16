#include "adapter/serialization/apollo_msgs/apollocanbus_ads338e.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAds338e &msg) {
        nlohmann::json obj;
        obj["adsbcmworksts"] = (msg.adsbcmworksts);
        obj["adsbcmworkstsvalid"] = (msg.adsbcmworkstsvalid);
        obj["adsreqcontrolbcm"] = (msg.adsreqcontrolbcm);
        obj["highbeamton"] = (msg.highbeamton);
        obj["dippedbeamon"] = (msg.dippedbeamon);
        obj["turnllighton"] = (msg.turnllighton);
        obj["emergencylighton"] = (msg.emergencylighton);
        obj["ffoglampon"] = (msg.ffoglampon);
        obj["rfoglampon"] = (msg.rfoglampon);
        obj["brakelight"] = (msg.brakelight);
        obj["hornon"] = (msg.hornon);
        obj["fwindshieldwiper"] = (msg.fwindshieldwiper);
        obj["rwindshieldwiper"] = (msg.rwindshieldwiper);
        return obj;
    }
    ApollocanbusAds338e from_json_ApollocanbusAds338e (nlohmann::json obj) {
        ApollocanbusAds338e msg;
        if(obj.contains("adsbcmworksts"))
        {
            msg.adsbcmworksts = (obj["adsbcmworksts"].is_string()?atoi(obj["adsbcmworksts"].get<std::string>().c_str()):obj["adsbcmworksts"].get<int>());
        }
        if(obj.contains("adsbcmworkstsvalid"))
        {
            msg.adsbcmworkstsvalid = (obj["adsbcmworkstsvalid"].is_string()?atoi(obj["adsbcmworkstsvalid"].get<std::string>().c_str()):obj["adsbcmworkstsvalid"].get<int>());
        }
        if(obj.contains("adsreqcontrolbcm"))
        {
            msg.adsreqcontrolbcm = (obj["adsreqcontrolbcm"].is_string()?atoi(obj["adsreqcontrolbcm"].get<std::string>().c_str()):obj["adsreqcontrolbcm"].get<int>());
        }
        if(obj.contains("highbeamton"))
        {
            msg.highbeamton = (obj["highbeamton"].is_string()?atoi(obj["highbeamton"].get<std::string>().c_str()):obj["highbeamton"].get<int>());
        }
        if(obj.contains("dippedbeamon"))
        {
            msg.dippedbeamon = (obj["dippedbeamon"].is_string()?atoi(obj["dippedbeamon"].get<std::string>().c_str()):obj["dippedbeamon"].get<int>());
        }
        if(obj.contains("turnllighton"))
        {
            msg.turnllighton = (obj["turnllighton"].is_string()?atoi(obj["turnllighton"].get<std::string>().c_str()):obj["turnllighton"].get<int>());
        }
        if(obj.contains("emergencylighton"))
        {
            msg.emergencylighton = (obj["emergencylighton"].is_string()?atoi(obj["emergencylighton"].get<std::string>().c_str()):obj["emergencylighton"].get<int>());
        }
        if(obj.contains("ffoglampon"))
        {
            msg.ffoglampon = (obj["ffoglampon"].is_string()?atoi(obj["ffoglampon"].get<std::string>().c_str()):obj["ffoglampon"].get<int>());
        }
        if(obj.contains("rfoglampon"))
        {
            msg.rfoglampon = (obj["rfoglampon"].is_string()?atoi(obj["rfoglampon"].get<std::string>().c_str()):obj["rfoglampon"].get<int>());
        }
        if(obj.contains("brakelight"))
        {
            msg.brakelight = (obj["brakelight"].is_string()?atoi(obj["brakelight"].get<std::string>().c_str()):obj["brakelight"].get<int>());
        }
        if(obj.contains("hornon"))
        {
            msg.hornon = (obj["hornon"].is_string()?atoi(obj["hornon"].get<std::string>().c_str()):obj["hornon"].get<int>());
        }
        if(obj.contains("fwindshieldwiper"))
        {
            msg.fwindshieldwiper = (obj["fwindshieldwiper"].is_string()?atoi(obj["fwindshieldwiper"].get<std::string>().c_str()):obj["fwindshieldwiper"].get<int>());
        }
        if(obj.contains("rwindshieldwiper"))
        {
            msg.rwindshieldwiper = (obj["rwindshieldwiper"].is_string()?atoi(obj["rwindshieldwiper"].get<std::string>().c_str()):obj["rwindshieldwiper"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusAds338e from_json<ApollocanbusAds338e>(nlohmann::json obj){
        return from_json_ApollocanbusAds338e(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAds338e &dt)
    {
        dt=from_json_ApollocanbusAds338e(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAds338e & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAds338e & dt)
    {
        os << to_json(dt);
        return os;
    }
}
