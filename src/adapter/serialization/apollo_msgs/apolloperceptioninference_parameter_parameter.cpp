#include "adapter/serialization/apollo_msgs/apolloperceptioninference_parameter_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceParameterParameter &msg) {
        nlohmann::json obj;
        obj["shape"] = to_json(msg.shape);
        return obj;
    }
    ApolloperceptioninferenceParameterParameter from_json_ApolloperceptioninferenceParameterParameter (nlohmann::json obj) {
        ApolloperceptioninferenceParameterParameter msg;
        if(obj.contains("shape"))
        {
            msg.shape = from_json_ApolloperceptioninferenceBlobShape(obj["shape"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceParameterParameter from_json<ApolloperceptioninferenceParameterParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceParameterParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceParameterParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceParameterParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceParameterParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceParameterParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
