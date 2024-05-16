#include "adapter/serialization/apollo_msgs/apolloperceptioninference_threshold_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceThresholdParameter &msg) {
        nlohmann::json obj;
        obj["threshold"] = (msg.threshold);
        return obj;
    }
    ApolloperceptioninferenceThresholdParameter from_json_ApolloperceptioninferenceThresholdParameter (nlohmann::json obj) {
        ApolloperceptioninferenceThresholdParameter msg;
        if(obj.contains("threshold"))
        {
            msg.threshold = (obj["threshold"].is_string()?(float)atof(obj["threshold"].get<std::string>().c_str()):obj["threshold"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceThresholdParameter from_json<ApolloperceptioninferenceThresholdParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceThresholdParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceThresholdParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceThresholdParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceThresholdParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceThresholdParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
