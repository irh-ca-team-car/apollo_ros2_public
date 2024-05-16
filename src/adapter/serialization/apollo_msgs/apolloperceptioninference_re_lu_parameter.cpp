#include "adapter/serialization/apollo_msgs/apolloperceptioninference_re_lu_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceReLUParameter &msg) {
        nlohmann::json obj;
        obj["negativeslope"] = (msg.negativeslope);
        obj["engine"] = (msg.engine);
        return obj;
    }
    ApolloperceptioninferenceReLUParameter from_json_ApolloperceptioninferenceReLUParameter (nlohmann::json obj) {
        ApolloperceptioninferenceReLUParameter msg;
        if(obj.contains("negativeslope"))
        {
            msg.negativeslope = (obj["negativeslope"].is_string()?(float)atof(obj["negativeslope"].get<std::string>().c_str()):obj["negativeslope"].get<float>());
        }
        if(obj.contains("engine"))
        {
            msg.engine = (obj["engine"].is_string()?atoi(obj["engine"].get<std::string>().c_str()):obj["engine"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceReLUParameter from_json<ApolloperceptioninferenceReLUParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceReLUParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceReLUParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceReLUParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceReLUParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceReLUParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
