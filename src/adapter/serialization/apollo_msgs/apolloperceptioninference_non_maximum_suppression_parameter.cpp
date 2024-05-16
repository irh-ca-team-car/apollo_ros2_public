#include "adapter/serialization/apollo_msgs/apolloperceptioninference_non_maximum_suppression_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNonMaximumSuppressionParameter &msg) {
        nlohmann::json obj;
        obj["nmsthreshold"] = (msg.nmsthreshold);
        obj["topk"] = (msg.topk);
        obj["eta"] = (msg.eta);
        return obj;
    }
    ApolloperceptioninferenceNonMaximumSuppressionParameter from_json_ApolloperceptioninferenceNonMaximumSuppressionParameter (nlohmann::json obj) {
        ApolloperceptioninferenceNonMaximumSuppressionParameter msg;
        if(obj.contains("nmsthreshold"))
        {
            msg.nmsthreshold = (obj["nmsthreshold"].is_string()?(float)atof(obj["nmsthreshold"].get<std::string>().c_str()):obj["nmsthreshold"].get<float>());
        }
        if(obj.contains("topk"))
        {
            msg.topk = (obj["topk"].is_string()?atoi(obj["topk"].get<std::string>().c_str()):obj["topk"].get<int>());
        }
        if(obj.contains("eta"))
        {
            msg.eta = (obj["eta"].is_string()?(float)atof(obj["eta"].get<std::string>().c_str()):obj["eta"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceNonMaximumSuppressionParameter from_json<ApolloperceptioninferenceNonMaximumSuppressionParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceNonMaximumSuppressionParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNonMaximumSuppressionParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceNonMaximumSuppressionParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNonMaximumSuppressionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNonMaximumSuppressionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
