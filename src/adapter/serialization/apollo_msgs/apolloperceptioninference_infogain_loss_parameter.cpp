#include "adapter/serialization/apollo_msgs/apolloperceptioninference_infogain_loss_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceInfogainLossParameter &msg) {
        nlohmann::json obj;
        obj["source"] = (msg.source);
        return obj;
    }
    ApolloperceptioninferenceInfogainLossParameter from_json_ApolloperceptioninferenceInfogainLossParameter (nlohmann::json obj) {
        ApolloperceptioninferenceInfogainLossParameter msg;
        if(obj.contains("source"))
        {
            msg.source = (obj["source"].is_string()?(obj["source"].get<std::string>().c_str()):obj["source"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceInfogainLossParameter from_json<ApolloperceptioninferenceInfogainLossParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceInfogainLossParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceInfogainLossParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceInfogainLossParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceInfogainLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceInfogainLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
