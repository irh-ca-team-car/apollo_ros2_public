#include "adapter/serialization/apollo_msgs/apollocanbus_ads_diagnosis628.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdsDiagnosis628 &msg) {
        nlohmann::json obj;
        obj["faultrank"] = (msg.faultrank);
        obj["adasfaultcode"] = (msg.adasfaultcode);
        obj["adassoftwareversion"] = (msg.adassoftwareversion);
        obj["adashardwareversion"] = (msg.adashardwareversion);
        return obj;
    }
    ApollocanbusAdsDiagnosis628 from_json_ApollocanbusAdsDiagnosis628 (nlohmann::json obj) {
        ApollocanbusAdsDiagnosis628 msg;
        if(obj.contains("faultrank"))
        {
            msg.faultrank = (obj["faultrank"].is_string()?atoi(obj["faultrank"].get<std::string>().c_str()):obj["faultrank"].get<int>());
        }
        if(obj.contains("adasfaultcode"))
        {
            msg.adasfaultcode = (obj["adasfaultcode"].is_string()?atoi(obj["adasfaultcode"].get<std::string>().c_str()):obj["adasfaultcode"].get<int>());
        }
        if(obj.contains("adassoftwareversion"))
        {
            msg.adassoftwareversion = (obj["adassoftwareversion"].is_string()?atoi(obj["adassoftwareversion"].get<std::string>().c_str()):obj["adassoftwareversion"].get<int>());
        }
        if(obj.contains("adashardwareversion"))
        {
            msg.adashardwareversion = (obj["adashardwareversion"].is_string()?atoi(obj["adashardwareversion"].get<std::string>().c_str()):obj["adashardwareversion"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusAdsDiagnosis628 from_json<ApollocanbusAdsDiagnosis628>(nlohmann::json obj){
        return from_json_ApollocanbusAdsDiagnosis628(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdsDiagnosis628 &dt)
    {
        dt=from_json_ApollocanbusAdsDiagnosis628(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdsDiagnosis628 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdsDiagnosis628 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
