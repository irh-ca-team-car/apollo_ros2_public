#include "adapter/serialization/apollo_msgs/apolloperceptioninference_inner_product_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceInnerProductParameter &msg) {
        nlohmann::json obj;
        obj["numoutput"] = (msg.numoutput);
        obj["biasterm"] = (msg.biasterm);
        obj["weightfiller"] = to_json(msg.weightfiller);
        obj["biasfiller"] = to_json(msg.biasfiller);
        obj["axis"] = (msg.axis);
        obj["transpose"] = (msg.transpose);
        return obj;
    }
    ApolloperceptioninferenceInnerProductParameter from_json_ApolloperceptioninferenceInnerProductParameter (nlohmann::json obj) {
        ApolloperceptioninferenceInnerProductParameter msg;
        if(obj.contains("numoutput"))
        {
            msg.numoutput = (obj["numoutput"].is_string()?atoi(obj["numoutput"].get<std::string>().c_str()):obj["numoutput"].get<uint32_t>());
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
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("transpose"))
        {
            msg.transpose = (obj["transpose"].is_string()?(bool)atoi(obj["transpose"].get<std::string>().c_str()):obj["transpose"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceInnerProductParameter from_json<ApolloperceptioninferenceInnerProductParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceInnerProductParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceInnerProductParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceInnerProductParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceInnerProductParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceInnerProductParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
