#include "adapter/serialization/apollo_msgs/apolloperceptioninference_arg_max_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceArgMaxParameter &msg) {
        nlohmann::json obj;
        obj["outmaxval"] = (msg.outmaxval);
        obj["topk"] = (msg.topk);
        obj["axis"] = (msg.axis);
        return obj;
    }
    ApolloperceptioninferenceArgMaxParameter from_json_ApolloperceptioninferenceArgMaxParameter (nlohmann::json obj) {
        ApolloperceptioninferenceArgMaxParameter msg;
        if(obj.contains("outmaxval"))
        {
            msg.outmaxval = (obj["outmaxval"].is_string()?(bool)atoi(obj["outmaxval"].get<std::string>().c_str()):obj["outmaxval"].get<bool>());
        }
        if(obj.contains("topk"))
        {
            msg.topk = (obj["topk"].is_string()?atoi(obj["topk"].get<std::string>().c_str()):obj["topk"].get<uint32_t>());
        }
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceArgMaxParameter from_json<ApolloperceptioninferenceArgMaxParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceArgMaxParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceArgMaxParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceArgMaxParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceArgMaxParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceArgMaxParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
