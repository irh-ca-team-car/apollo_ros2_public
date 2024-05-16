#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_loss_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceYoloLossParameter &msg) {
        nlohmann::json obj;
        obj["reglosstype"] = (msg.reglosstype);
        obj["targetaxis"] = (msg.targetaxis);
        return obj;
    }
    ApolloperceptioninferenceYoloLossParameter from_json_ApolloperceptioninferenceYoloLossParameter (nlohmann::json obj) {
        ApolloperceptioninferenceYoloLossParameter msg;
        if(obj.contains("reglosstype"))
        {
            msg.reglosstype = (obj["reglosstype"].is_string()?atoi(obj["reglosstype"].get<std::string>().c_str()):obj["reglosstype"].get<int>());
        }
        if(obj.contains("targetaxis"))
        {
            msg.targetaxis = (obj["targetaxis"].is_string()?atoi(obj["targetaxis"].get<std::string>().c_str()):obj["targetaxis"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceYoloLossParameter from_json<ApolloperceptioninferenceYoloLossParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceYoloLossParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceYoloLossParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceYoloLossParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceYoloLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceYoloLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
