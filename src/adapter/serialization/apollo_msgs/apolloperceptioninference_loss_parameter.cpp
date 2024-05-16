#include "adapter/serialization/apollo_msgs/apolloperceptioninference_loss_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceLossParameter &msg) {
        nlohmann::json obj;
        obj["ignorelabel"] = (msg.ignorelabel);
        obj["normalization"] = (msg.normalization);
        obj["normalize"] = (msg.normalize);
        return obj;
    }
    ApolloperceptioninferenceLossParameter from_json_ApolloperceptioninferenceLossParameter (nlohmann::json obj) {
        ApolloperceptioninferenceLossParameter msg;
        if(obj.contains("ignorelabel"))
        {
            msg.ignorelabel = (obj["ignorelabel"].is_string()?atoi(obj["ignorelabel"].get<std::string>().c_str()):obj["ignorelabel"].get<int>());
        }
        if(obj.contains("normalization"))
        {
            msg.normalization = (obj["normalization"].is_string()?atoi(obj["normalization"].get<std::string>().c_str()):obj["normalization"].get<int>());
        }
        if(obj.contains("normalize"))
        {
            msg.normalize = (obj["normalize"].is_string()?(bool)atoi(obj["normalize"].get<std::string>().c_str()):obj["normalize"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceLossParameter from_json<ApolloperceptioninferenceLossParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceLossParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceLossParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceLossParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
