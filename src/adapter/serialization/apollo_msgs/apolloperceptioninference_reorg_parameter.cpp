#include "adapter/serialization/apollo_msgs/apolloperceptioninference_reorg_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceReorgParameter &msg) {
        nlohmann::json obj;
        obj["stride"] = (msg.stride);
        return obj;
    }
    ApolloperceptioninferenceReorgParameter from_json_ApolloperceptioninferenceReorgParameter (nlohmann::json obj) {
        ApolloperceptioninferenceReorgParameter msg;
        if(obj.contains("stride"))
        {
            msg.stride = (obj["stride"].is_string()?atoi(obj["stride"].get<std::string>().c_str()):obj["stride"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceReorgParameter from_json<ApolloperceptioninferenceReorgParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceReorgParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceReorgParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceReorgParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceReorgParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceReorgParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
