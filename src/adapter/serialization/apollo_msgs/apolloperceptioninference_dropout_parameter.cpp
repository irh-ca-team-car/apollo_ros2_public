#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dropout_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDropoutParameter &msg) {
        nlohmann::json obj;
        obj["dropoutratio"] = (msg.dropoutratio);
        return obj;
    }
    ApolloperceptioninferenceDropoutParameter from_json_ApolloperceptioninferenceDropoutParameter (nlohmann::json obj) {
        ApolloperceptioninferenceDropoutParameter msg;
        if(obj.contains("dropoutratio"))
        {
            msg.dropoutratio = (obj["dropoutratio"].is_string()?(float)atof(obj["dropoutratio"].get<std::string>().c_str()):obj["dropoutratio"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDropoutParameter from_json<ApolloperceptioninferenceDropoutParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDropoutParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDropoutParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceDropoutParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDropoutParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDropoutParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
