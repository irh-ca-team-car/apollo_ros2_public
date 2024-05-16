#include "adapter/serialization/apollo_msgs/apolloperceptioninference_elu_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceELUParameter &msg) {
        nlohmann::json obj;
        obj["alpha"] = (msg.alpha);
        return obj;
    }
    ApolloperceptioninferenceELUParameter from_json_ApolloperceptioninferenceELUParameter (nlohmann::json obj) {
        ApolloperceptioninferenceELUParameter msg;
        if(obj.contains("alpha"))
        {
            msg.alpha = (obj["alpha"].is_string()?(float)atof(obj["alpha"].get<std::string>().c_str()):obj["alpha"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceELUParameter from_json<ApolloperceptioninferenceELUParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceELUParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceELUParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceELUParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceELUParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceELUParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
