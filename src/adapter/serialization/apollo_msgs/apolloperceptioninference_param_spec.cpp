#include "adapter/serialization/apollo_msgs/apolloperceptioninference_param_spec.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceParamSpec &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["sharemode"] = (msg.sharemode);
        obj["lrmult"] = (msg.lrmult);
        obj["decaymult"] = (msg.decaymult);
        return obj;
    }
    ApolloperceptioninferenceParamSpec from_json_ApolloperceptioninferenceParamSpec (nlohmann::json obj) {
        ApolloperceptioninferenceParamSpec msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("sharemode"))
        {
            msg.sharemode = (obj["sharemode"].is_string()?atoi(obj["sharemode"].get<std::string>().c_str()):obj["sharemode"].get<int>());
        }
        if(obj.contains("lrmult"))
        {
            msg.lrmult = (obj["lrmult"].is_string()?(float)atof(obj["lrmult"].get<std::string>().c_str()):obj["lrmult"].get<float>());
        }
        if(obj.contains("decaymult"))
        {
            msg.decaymult = (obj["decaymult"].is_string()?(float)atof(obj["decaymult"].get<std::string>().c_str()):obj["decaymult"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceParamSpec from_json<ApolloperceptioninferenceParamSpec>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceParamSpec(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceParamSpec &dt)
    {
        dt=from_json_ApolloperceptioninferenceParamSpec(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceParamSpec & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceParamSpec & dt)
    {
        os << to_json(dt);
        return os;
    }
}
