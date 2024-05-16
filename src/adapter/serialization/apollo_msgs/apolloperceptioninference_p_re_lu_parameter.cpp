#include "adapter/serialization/apollo_msgs/apolloperceptioninference_p_re_lu_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePReLUParameter &msg) {
        nlohmann::json obj;
        obj["filler"] = to_json(msg.filler);
        obj["channelshared"] = (msg.channelshared);
        return obj;
    }
    ApolloperceptioninferencePReLUParameter from_json_ApolloperceptioninferencePReLUParameter (nlohmann::json obj) {
        ApolloperceptioninferencePReLUParameter msg;
        if(obj.contains("filler"))
        {
            msg.filler = from_json_ApolloperceptioninferenceFillerParameter(obj["filler"]);
        }
        if(obj.contains("channelshared"))
        {
            msg.channelshared = (obj["channelshared"].is_string()?(bool)atoi(obj["channelshared"].get<std::string>().c_str()):obj["channelshared"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferencePReLUParameter from_json<ApolloperceptioninferencePReLUParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferencePReLUParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePReLUParameter &dt)
    {
        dt=from_json_ApolloperceptioninferencePReLUParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePReLUParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePReLUParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
