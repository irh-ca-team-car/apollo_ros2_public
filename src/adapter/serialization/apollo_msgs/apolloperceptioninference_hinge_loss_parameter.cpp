#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hinge_loss_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceHingeLossParameter &msg) {
        nlohmann::json obj;
        obj["norm"] = (msg.norm);
        return obj;
    }
    ApolloperceptioninferenceHingeLossParameter from_json_ApolloperceptioninferenceHingeLossParameter (nlohmann::json obj) {
        ApolloperceptioninferenceHingeLossParameter msg;
        if(obj.contains("norm"))
        {
            msg.norm = (obj["norm"].is_string()?atoi(obj["norm"].get<std::string>().c_str()):obj["norm"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceHingeLossParameter from_json<ApolloperceptioninferenceHingeLossParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceHingeLossParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceHingeLossParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceHingeLossParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceHingeLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceHingeLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
