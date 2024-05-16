#include "adapter/serialization/apollo_msgs/apolloperceptioninference_bias_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBiasParameter &msg) {
        nlohmann::json obj;
        obj["axis"] = (msg.axis);
        obj["numaxes"] = (msg.numaxes);
        obj["filler"] = to_json(msg.filler);
        return obj;
    }
    ApolloperceptioninferenceBiasParameter from_json_ApolloperceptioninferenceBiasParameter (nlohmann::json obj) {
        ApolloperceptioninferenceBiasParameter msg;
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
        return msg;
    }
    template <>
    ApolloperceptioninferenceBiasParameter from_json<ApolloperceptioninferenceBiasParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceBiasParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBiasParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceBiasParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBiasParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBiasParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
