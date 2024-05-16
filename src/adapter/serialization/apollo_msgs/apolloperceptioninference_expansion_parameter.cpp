#include "adapter/serialization/apollo_msgs/apolloperceptioninference_expansion_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceExpansionParameter &msg) {
        nlohmann::json obj;
        obj["prob"] = (msg.prob);
        obj["maxexpandratio"] = (msg.maxexpandratio);
        return obj;
    }
    ApolloperceptioninferenceExpansionParameter from_json_ApolloperceptioninferenceExpansionParameter (nlohmann::json obj) {
        ApolloperceptioninferenceExpansionParameter msg;
        if(obj.contains("prob"))
        {
            msg.prob = (obj["prob"].is_string()?(float)atof(obj["prob"].get<std::string>().c_str()):obj["prob"].get<float>());
        }
        if(obj.contains("maxexpandratio"))
        {
            msg.maxexpandratio = (obj["maxexpandratio"].is_string()?(float)atof(obj["maxexpandratio"].get<std::string>().c_str()):obj["maxexpandratio"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceExpansionParameter from_json<ApolloperceptioninferenceExpansionParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceExpansionParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceExpansionParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceExpansionParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceExpansionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceExpansionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
