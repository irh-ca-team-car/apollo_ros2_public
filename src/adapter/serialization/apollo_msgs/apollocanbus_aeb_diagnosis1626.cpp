#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_diagnosis1626.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebDiagnosis1626 &msg) {
        nlohmann::json obj;
        obj["aebsoftwareversion"] = (msg.aebsoftwareversion);
        obj["aebhardwareversion"] = (msg.aebhardwareversion);
        return obj;
    }
    ApollocanbusAebDiagnosis1626 from_json_ApollocanbusAebDiagnosis1626 (nlohmann::json obj) {
        ApollocanbusAebDiagnosis1626 msg;
        if(obj.contains("aebsoftwareversion"))
        {
            msg.aebsoftwareversion = (obj["aebsoftwareversion"].is_string()?atof(obj["aebsoftwareversion"].get<std::string>().c_str()):obj["aebsoftwareversion"].get<double>());
        }
        if(obj.contains("aebhardwareversion"))
        {
            msg.aebhardwareversion = (obj["aebhardwareversion"].is_string()?atof(obj["aebhardwareversion"].get<std::string>().c_str()):obj["aebhardwareversion"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusAebDiagnosis1626 from_json<ApollocanbusAebDiagnosis1626>(nlohmann::json obj){
        return from_json_ApollocanbusAebDiagnosis1626(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebDiagnosis1626 &dt)
    {
        dt=from_json_ApollocanbusAebDiagnosis1626(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebDiagnosis1626 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebDiagnosis1626 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
