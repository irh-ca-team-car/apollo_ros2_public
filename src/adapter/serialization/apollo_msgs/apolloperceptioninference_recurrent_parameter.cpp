#include "adapter/serialization/apollo_msgs/apolloperceptioninference_recurrent_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceRecurrentParameter &msg) {
        nlohmann::json obj;
        obj["numoutput"] = (msg.numoutput);
        obj["weightfiller"] = to_json(msg.weightfiller);
        obj["biasfiller"] = to_json(msg.biasfiller);
        obj["debuginfo"] = (msg.debuginfo);
        obj["exposehidden"] = (msg.exposehidden);
        return obj;
    }
    ApolloperceptioninferenceRecurrentParameter from_json_ApolloperceptioninferenceRecurrentParameter (nlohmann::json obj) {
        ApolloperceptioninferenceRecurrentParameter msg;
        if(obj.contains("numoutput"))
        {
            msg.numoutput = (obj["numoutput"].is_string()?atoi(obj["numoutput"].get<std::string>().c_str()):obj["numoutput"].get<uint32_t>());
        }
        if(obj.contains("weightfiller"))
        {
            msg.weightfiller = from_json_ApolloperceptioninferenceFillerParameter(obj["weightfiller"]);
        }
        if(obj.contains("biasfiller"))
        {
            msg.biasfiller = from_json_ApolloperceptioninferenceFillerParameter(obj["biasfiller"]);
        }
        if(obj.contains("debuginfo"))
        {
            msg.debuginfo = (obj["debuginfo"].is_string()?(bool)atoi(obj["debuginfo"].get<std::string>().c_str()):obj["debuginfo"].get<bool>());
        }
        if(obj.contains("exposehidden"))
        {
            msg.exposehidden = (obj["exposehidden"].is_string()?(bool)atoi(obj["exposehidden"].get<std::string>().c_str()):obj["exposehidden"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceRecurrentParameter from_json<ApolloperceptioninferenceRecurrentParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceRecurrentParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceRecurrentParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceRecurrentParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceRecurrentParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceRecurrentParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
