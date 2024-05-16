#include "adapter/serialization/apollo_msgs/apolloperceptioninference_power_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePowerParameter &msg) {
        nlohmann::json obj;
        obj["power"] = (msg.power);
        obj["scale"] = (msg.scale);
        obj["shift"] = (msg.shift);
        return obj;
    }
    ApolloperceptioninferencePowerParameter from_json_ApolloperceptioninferencePowerParameter (nlohmann::json obj) {
        ApolloperceptioninferencePowerParameter msg;
        if(obj.contains("power"))
        {
            msg.power = (obj["power"].is_string()?(float)atof(obj["power"].get<std::string>().c_str()):obj["power"].get<float>());
        }
        if(obj.contains("scale"))
        {
            msg.scale = (obj["scale"].is_string()?(float)atof(obj["scale"].get<std::string>().c_str()):obj["scale"].get<float>());
        }
        if(obj.contains("shift"))
        {
            msg.shift = (obj["shift"].is_string()?(float)atof(obj["shift"].get<std::string>().c_str()):obj["shift"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferencePowerParameter from_json<ApolloperceptioninferencePowerParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferencePowerParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePowerParameter &dt)
    {
        dt=from_json_ApolloperceptioninferencePowerParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePowerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePowerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
