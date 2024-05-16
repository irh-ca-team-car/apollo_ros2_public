#include "adapter/serialization/apollo_msgs/apolloperceptioninference_scale_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceScaleParameter &msg) {
        nlohmann::json obj;
        obj["axis"] = (msg.axis);
        obj["numaxes"] = (msg.numaxes);
        obj["filler"] = to_json(msg.filler);
        obj["biasterm"] = (msg.biasterm);
        obj["biasfiller"] = to_json(msg.biasfiller);
        return obj;
    }
    ApolloperceptioninferenceScaleParameter from_json_ApolloperceptioninferenceScaleParameter (nlohmann::json obj) {
        ApolloperceptioninferenceScaleParameter msg;
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("numaxes"))
        {
            msg.numaxes = (obj["numaxes"].is_string()?atoi(obj["numaxes"].get<std::string>().c_str()):obj["numaxes"].get<int>());
        }
        if(obj.contains("filler"))
        {
            msg.filler = from_json_ApolloperceptioninferenceFillerParameter(obj["filler"]);
        }
        if(obj.contains("biasterm"))
        {
            msg.biasterm = (obj["biasterm"].is_string()?(bool)atoi(obj["biasterm"].get<std::string>().c_str()):obj["biasterm"].get<bool>());
        }
        if(obj.contains("biasfiller"))
        {
            msg.biasfiller = from_json_ApolloperceptioninferenceFillerParameter(obj["biasfiller"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceScaleParameter from_json<ApolloperceptioninferenceScaleParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceScaleParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceScaleParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceScaleParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceScaleParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceScaleParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
