#include "adapter/serialization/apollo_msgs/apolloperceptioninference_log_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceLogParameter &msg) {
        nlohmann::json obj;
        obj["base"] = (msg.base);
        obj["scale"] = (msg.scale);
        obj["shift"] = (msg.shift);
        return obj;
    }
    ApolloperceptioninferenceLogParameter from_json_ApolloperceptioninferenceLogParameter (nlohmann::json obj) {
        ApolloperceptioninferenceLogParameter msg;
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
    ApolloperceptioninferenceLogParameter from_json<ApolloperceptioninferenceLogParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceLogParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceLogParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceLogParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceLogParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceLogParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
