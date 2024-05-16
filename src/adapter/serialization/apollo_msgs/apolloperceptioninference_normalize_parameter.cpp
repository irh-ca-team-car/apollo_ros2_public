#include "adapter/serialization/apollo_msgs/apolloperceptioninference_normalize_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNormalizeParameter &msg) {
        nlohmann::json obj;
        obj["acrossspatial"] = (msg.acrossspatial);
        obj["scalefiller"] = to_json(msg.scalefiller);
        obj["channelshared"] = (msg.channelshared);
        obj["eps"] = (msg.eps);
        return obj;
    }
    ApolloperceptioninferenceNormalizeParameter from_json_ApolloperceptioninferenceNormalizeParameter (nlohmann::json obj) {
        ApolloperceptioninferenceNormalizeParameter msg;
        if(obj.contains("acrossspatial"))
        {
            msg.acrossspatial = (obj["acrossspatial"].is_string()?(bool)atoi(obj["acrossspatial"].get<std::string>().c_str()):obj["acrossspatial"].get<bool>());
        }
        if(obj.contains("scalefiller"))
        {
            msg.scalefiller = from_json_ApolloperceptioninferenceFillerParameter(obj["scalefiller"]);
        }
        if(obj.contains("channelshared"))
        {
            msg.channelshared = (obj["channelshared"].is_string()?(bool)atoi(obj["channelshared"].get<std::string>().c_str()):obj["channelshared"].get<bool>());
        }
        if(obj.contains("eps"))
        {
            msg.eps = (obj["eps"].is_string()?(float)atof(obj["eps"].get<std::string>().c_str()):obj["eps"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceNormalizeParameter from_json<ApolloperceptioninferenceNormalizeParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceNormalizeParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNormalizeParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceNormalizeParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNormalizeParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNormalizeParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
