#include "adapter/serialization/apollo_msgs/apolloperception_light_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionLightStatus &msg) {
        nlohmann::json obj;
        obj["brakevisible"] = (msg.brakevisible);
        obj["brakeswitchon"] = (msg.brakeswitchon);
        obj["leftturnvisible"] = (msg.leftturnvisible);
        obj["leftturnswitchon"] = (msg.leftturnswitchon);
        obj["rightturnvisible"] = (msg.rightturnvisible);
        obj["rightturnswitchon"] = (msg.rightturnswitchon);
        return obj;
    }
    ApolloperceptionLightStatus from_json_ApolloperceptionLightStatus (nlohmann::json obj) {
        ApolloperceptionLightStatus msg;
        if(obj.contains("brakevisible"))
        {
            msg.brakevisible = (obj["brakevisible"].is_string()?atof(obj["brakevisible"].get<std::string>().c_str()):obj["brakevisible"].get<double>());
        }
        if(obj.contains("brakeswitchon"))
        {
            msg.brakeswitchon = (obj["brakeswitchon"].is_string()?atof(obj["brakeswitchon"].get<std::string>().c_str()):obj["brakeswitchon"].get<double>());
        }
        if(obj.contains("leftturnvisible"))
        {
            msg.leftturnvisible = (obj["leftturnvisible"].is_string()?atof(obj["leftturnvisible"].get<std::string>().c_str()):obj["leftturnvisible"].get<double>());
        }
        if(obj.contains("leftturnswitchon"))
        {
            msg.leftturnswitchon = (obj["leftturnswitchon"].is_string()?atof(obj["leftturnswitchon"].get<std::string>().c_str()):obj["leftturnswitchon"].get<double>());
        }
        if(obj.contains("rightturnvisible"))
        {
            msg.rightturnvisible = (obj["rightturnvisible"].is_string()?atof(obj["rightturnvisible"].get<std::string>().c_str()):obj["rightturnvisible"].get<double>());
        }
        if(obj.contains("rightturnswitchon"))
        {
            msg.rightturnswitchon = (obj["rightturnswitchon"].is_string()?atof(obj["rightturnswitchon"].get<std::string>().c_str()):obj["rightturnswitchon"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionLightStatus from_json<ApolloperceptionLightStatus>(nlohmann::json obj){
        return from_json_ApolloperceptionLightStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionLightStatus &dt)
    {
        dt=from_json_ApolloperceptionLightStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionLightStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionLightStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
