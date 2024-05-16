#include "adapter/serialization/apollo_msgs/apolloperceptioninference_lrn_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceLRNParameter &msg) {
        nlohmann::json obj;
        obj["localsize"] = (msg.localsize);
        obj["alpha"] = (msg.alpha);
        obj["beta"] = (msg.beta);
        obj["normregion"] = (msg.normregion);
        obj["k"] = (msg.k);
        obj["engine"] = (msg.engine);
        return obj;
    }
    ApolloperceptioninferenceLRNParameter from_json_ApolloperceptioninferenceLRNParameter (nlohmann::json obj) {
        ApolloperceptioninferenceLRNParameter msg;
        if(obj.contains("localsize"))
        {
            msg.localsize = (obj["localsize"].is_string()?atoi(obj["localsize"].get<std::string>().c_str()):obj["localsize"].get<uint32_t>());
        }
        if(obj.contains("alpha"))
        {
            msg.alpha = (obj["alpha"].is_string()?(float)atof(obj["alpha"].get<std::string>().c_str()):obj["alpha"].get<float>());
        }
        if(obj.contains("beta"))
        {
            msg.beta = (obj["beta"].is_string()?(float)atof(obj["beta"].get<std::string>().c_str()):obj["beta"].get<float>());
        }
        if(obj.contains("normregion"))
        {
            msg.normregion = (obj["normregion"].is_string()?atoi(obj["normregion"].get<std::string>().c_str()):obj["normregion"].get<int>());
        }
        if(obj.contains("k"))
        {
            msg.k = (obj["k"].is_string()?(float)atof(obj["k"].get<std::string>().c_str()):obj["k"].get<float>());
        }
        if(obj.contains("engine"))
        {
            msg.engine = (obj["engine"].is_string()?atoi(obj["engine"].get<std::string>().c_str()):obj["engine"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceLRNParameter from_json<ApolloperceptioninferenceLRNParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceLRNParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceLRNParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceLRNParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceLRNParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceLRNParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
