#include "adapter/serialization/apollo_msgs/apolloperceptioninference_accuracy_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAccuracyParameter &msg) {
        nlohmann::json obj;
        obj["topk"] = (msg.topk);
        obj["axis"] = (msg.axis);
        obj["ignorelabel"] = (msg.ignorelabel);
        return obj;
    }
    ApolloperceptioninferenceAccuracyParameter from_json_ApolloperceptioninferenceAccuracyParameter (nlohmann::json obj) {
        ApolloperceptioninferenceAccuracyParameter msg;
        if(obj.contains("topk"))
        {
            msg.topk = (obj["topk"].is_string()?atoi(obj["topk"].get<std::string>().c_str()):obj["topk"].get<uint32_t>());
        }
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("ignorelabel"))
        {
            msg.ignorelabel = (obj["ignorelabel"].is_string()?atoi(obj["ignorelabel"].get<std::string>().c_str()):obj["ignorelabel"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceAccuracyParameter from_json<ApolloperceptioninferenceAccuracyParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceAccuracyParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAccuracyParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceAccuracyParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAccuracyParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAccuracyParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
