#include "adapter/serialization/apollo_msgs/apolloperceptioninference_contrastive_loss_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceContrastiveLossParameter &msg) {
        nlohmann::json obj;
        obj["margin"] = (msg.margin);
        obj["legacyversion"] = (msg.legacyversion);
        return obj;
    }
    ApolloperceptioninferenceContrastiveLossParameter from_json_ApolloperceptioninferenceContrastiveLossParameter (nlohmann::json obj) {
        ApolloperceptioninferenceContrastiveLossParameter msg;
        if(obj.contains("margin"))
        {
            msg.margin = (obj["margin"].is_string()?(float)atof(obj["margin"].get<std::string>().c_str()):obj["margin"].get<float>());
        }
        if(obj.contains("legacyversion"))
        {
            msg.legacyversion = (obj["legacyversion"].is_string()?(bool)atoi(obj["legacyversion"].get<std::string>().c_str()):obj["legacyversion"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceContrastiveLossParameter from_json<ApolloperceptioninferenceContrastiveLossParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceContrastiveLossParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceContrastiveLossParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceContrastiveLossParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceContrastiveLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceContrastiveLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
