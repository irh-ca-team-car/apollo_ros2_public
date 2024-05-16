#include "adapter/serialization/apollo_msgs/apolloperceptioninference_reduction_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceReductionParameter &msg) {
        nlohmann::json obj;
        obj["operation"] = (msg.operation);
        obj["axis"] = (msg.axis);
        obj["coeff"] = (msg.coeff);
        return obj;
    }
    ApolloperceptioninferenceReductionParameter from_json_ApolloperceptioninferenceReductionParameter (nlohmann::json obj) {
        ApolloperceptioninferenceReductionParameter msg;
        if(obj.contains("operation"))
        {
            msg.operation = (obj["operation"].is_string()?atoi(obj["operation"].get<std::string>().c_str()):obj["operation"].get<int>());
        }
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("coeff"))
        {
            msg.coeff = (obj["coeff"].is_string()?(float)atof(obj["coeff"].get<std::string>().c_str()):obj["coeff"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceReductionParameter from_json<ApolloperceptioninferenceReductionParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceReductionParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceReductionParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceReductionParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceReductionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceReductionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
