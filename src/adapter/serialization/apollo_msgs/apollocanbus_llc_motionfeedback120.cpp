#include "adapter/serialization/apollo_msgs/apollocanbus_llc_motionfeedback120.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcMotionfeedback120 &msg) {
        nlohmann::json obj;
        obj["llcfbkgear"] = (msg.llcfbkgear);
        obj["llcfbkparkingbrake"] = (msg.llcfbkparkingbrake);
        obj["llcfbkthrottleposition"] = (msg.llcfbkthrottleposition);
        obj["llcfbkbrakepercentrear"] = (msg.llcfbkbrakepercentrear);
        obj["llcfbkbrakepercentfront"] = (msg.llcfbkbrakepercentfront);
        obj["llcfbksteeringcontrolmode"] = (msg.llcfbksteeringcontrolmode);
        obj["llcmotionfeedback1counter"] = (msg.llcmotionfeedback1counter);
        obj["llcmotionfeedback1checksum"] = (msg.llcmotionfeedback1checksum);
        obj["llcfbkcommandaligned"] = (msg.llcfbkcommandaligned);
        obj["llcfbkestoppressed"] = (msg.llcfbkestoppressed);
        obj["llcfbkadcrequestautonomy"] = (msg.llcfbkadcrequestautonomy);
        obj["llcfbkallowautonomy"] = (msg.llcfbkallowautonomy);
        obj["llcfbklongitudinalcontrolmode"] = (msg.llcfbklongitudinalcontrolmode);
        obj["llcfbkstate"] = (msg.llcfbkstate);
        return obj;
    }
    ApollocanbusLlcMotionfeedback120 from_json_ApollocanbusLlcMotionfeedback120 (nlohmann::json obj) {
        ApollocanbusLlcMotionfeedback120 msg;
        if(obj.contains("llcfbkgear"))
        {
            msg.llcfbkgear = (obj["llcfbkgear"].is_string()?atoi(obj["llcfbkgear"].get<std::string>().c_str()):obj["llcfbkgear"].get<int>());
        }
        if(obj.contains("llcfbkparkingbrake"))
        {
            msg.llcfbkparkingbrake = (obj["llcfbkparkingbrake"].is_string()?(bool)atoi(obj["llcfbkparkingbrake"].get<std::string>().c_str()):obj["llcfbkparkingbrake"].get<bool>());
        }
        if(obj.contains("llcfbkthrottleposition"))
        {
            msg.llcfbkthrottleposition = (obj["llcfbkthrottleposition"].is_string()?atof(obj["llcfbkthrottleposition"].get<std::string>().c_str()):obj["llcfbkthrottleposition"].get<double>());
        }
        if(obj.contains("llcfbkbrakepercentrear"))
        {
            msg.llcfbkbrakepercentrear = (obj["llcfbkbrakepercentrear"].is_string()?atof(obj["llcfbkbrakepercentrear"].get<std::string>().c_str()):obj["llcfbkbrakepercentrear"].get<double>());
        }
        if(obj.contains("llcfbkbrakepercentfront"))
        {
            msg.llcfbkbrakepercentfront = (obj["llcfbkbrakepercentfront"].is_string()?atof(obj["llcfbkbrakepercentfront"].get<std::string>().c_str()):obj["llcfbkbrakepercentfront"].get<double>());
        }
        if(obj.contains("llcfbksteeringcontrolmode"))
        {
            msg.llcfbksteeringcontrolmode = (obj["llcfbksteeringcontrolmode"].is_string()?atoi(obj["llcfbksteeringcontrolmode"].get<std::string>().c_str()):obj["llcfbksteeringcontrolmode"].get<int>());
        }
        if(obj.contains("llcmotionfeedback1counter"))
        {
            msg.llcmotionfeedback1counter = (obj["llcmotionfeedback1counter"].is_string()?atoi(obj["llcmotionfeedback1counter"].get<std::string>().c_str()):obj["llcmotionfeedback1counter"].get<int>());
        }
        if(obj.contains("llcmotionfeedback1checksum"))
        {
            msg.llcmotionfeedback1checksum = (obj["llcmotionfeedback1checksum"].is_string()?atoi(obj["llcmotionfeedback1checksum"].get<std::string>().c_str()):obj["llcmotionfeedback1checksum"].get<int>());
        }
        if(obj.contains("llcfbkcommandaligned"))
        {
            msg.llcfbkcommandaligned = (obj["llcfbkcommandaligned"].is_string()?(bool)atoi(obj["llcfbkcommandaligned"].get<std::string>().c_str()):obj["llcfbkcommandaligned"].get<bool>());
        }
        if(obj.contains("llcfbkestoppressed"))
        {
            msg.llcfbkestoppressed = (obj["llcfbkestoppressed"].is_string()?(bool)atoi(obj["llcfbkestoppressed"].get<std::string>().c_str()):obj["llcfbkestoppressed"].get<bool>());
        }
        if(obj.contains("llcfbkadcrequestautonomy"))
        {
            msg.llcfbkadcrequestautonomy = (obj["llcfbkadcrequestautonomy"].is_string()?(bool)atoi(obj["llcfbkadcrequestautonomy"].get<std::string>().c_str()):obj["llcfbkadcrequestautonomy"].get<bool>());
        }
        if(obj.contains("llcfbkallowautonomy"))
        {
            msg.llcfbkallowautonomy = (obj["llcfbkallowautonomy"].is_string()?(bool)atoi(obj["llcfbkallowautonomy"].get<std::string>().c_str()):obj["llcfbkallowautonomy"].get<bool>());
        }
        if(obj.contains("llcfbklongitudinalcontrolmode"))
        {
            msg.llcfbklongitudinalcontrolmode = (obj["llcfbklongitudinalcontrolmode"].is_string()?atoi(obj["llcfbklongitudinalcontrolmode"].get<std::string>().c_str()):obj["llcfbklongitudinalcontrolmode"].get<int>());
        }
        if(obj.contains("llcfbkstate"))
        {
            msg.llcfbkstate = (obj["llcfbkstate"].is_string()?atoi(obj["llcfbkstate"].get<std::string>().c_str()):obj["llcfbkstate"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusLlcMotionfeedback120 from_json<ApollocanbusLlcMotionfeedback120>(nlohmann::json obj){
        return from_json_ApollocanbusLlcMotionfeedback120(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcMotionfeedback120 &dt)
    {
        dt=from_json_ApollocanbusLlcMotionfeedback120(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcMotionfeedback120 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcMotionfeedback120 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
