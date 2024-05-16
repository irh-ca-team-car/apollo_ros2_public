#include "adapter/serialization/apollo_msgs/apolloperceptioninference_exp_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceExpParameter &msg) {
        nlohmann::json obj;
        obj["base"] = (msg.base);
        obj["scale"] = (msg.scale);
        obj["shift"] = (msg.shift);
        return obj;
    }
    ApolloperceptioninferenceExpParameter from_json_ApolloperceptioninferenceExpParameter (nlohmann::json obj) {
        ApolloperceptioninferenceExpParameter msg;
        if(obj.contains("base"))
        {
            msg.base = (obj["base"].is_string()?(float)atof(obj["base"].get<std::string>().c_str()):obj["base"].get<float>());
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
    ApolloperceptioninferenceExpParameter from_json<ApolloperceptioninferenceExpParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceExpParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceExpParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceExpParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceExpParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceExpParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
