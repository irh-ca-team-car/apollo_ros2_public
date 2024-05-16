#include "adapter/serialization/apollo_msgs/apolloperceptioninference_embed_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceEmbedParameter &msg) {
        nlohmann::json obj;
        obj["numoutput"] = (msg.numoutput);
        obj["inputdim"] = (msg.inputdim);
        obj["biasterm"] = (msg.biasterm);
        obj["weightfiller"] = to_json(msg.weightfiller);
        obj["biasfiller"] = to_json(msg.biasfiller);
        return obj;
    }
    ApolloperceptioninferenceEmbedParameter from_json_ApolloperceptioninferenceEmbedParameter (nlohmann::json obj) {
        ApolloperceptioninferenceEmbedParameter msg;
        if(obj.contains("numoutput"))
        {
            msg.numoutput = (obj["numoutput"].is_string()?atoi(obj["numoutput"].get<std::string>().c_str()):obj["numoutput"].get<uint32_t>());
        }
        if(obj.contains("inputdim"))
        {
            msg.inputdim = (obj["inputdim"].is_string()?atoi(obj["inputdim"].get<std::string>().c_str()):obj["inputdim"].get<uint32_t>());
        }
        if(obj.contains("biasterm"))
        {
            msg.biasterm = (obj["biasterm"].is_string()?(bool)atoi(obj["biasterm"].get<std::string>().c_str()):obj["biasterm"].get<bool>());
        }
        if(obj.contains("weightfiller"))
        {
            msg.weightfiller = from_json_ApolloperceptioninferenceFillerParameter(obj["weightfiller"]);
        }
        if(obj.contains("biasfiller"))
        {
            msg.biasfiller = from_json_ApolloperceptioninferenceFillerParameter(obj["biasfiller"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceEmbedParameter from_json<ApolloperceptioninferenceEmbedParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceEmbedParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceEmbedParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceEmbedParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceEmbedParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceEmbedParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
