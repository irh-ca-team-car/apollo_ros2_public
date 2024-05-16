#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceFillerParameter &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        obj["value"] = (msg.value);
        obj["min"] = (msg.min);
        obj["max"] = (msg.max);
        obj["mean"] = (msg.mean);
        obj["std"] = (msg.std);
        obj["sparse"] = (msg.sparse);
        obj["variancenorm"] = (msg.variancenorm);
        return obj;
    }
    ApolloperceptioninferenceFillerParameter from_json_ApolloperceptioninferenceFillerParameter (nlohmann::json obj) {
        ApolloperceptioninferenceFillerParameter msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?(obj["type"].get<std::string>().c_str()):obj["type"].get<std::string>());
        }
        if(obj.contains("value"))
        {
            msg.value = (obj["value"].is_string()?(float)atof(obj["value"].get<std::string>().c_str()):obj["value"].get<float>());
        }
        if(obj.contains("min"))
        {
            msg.min = (obj["min"].is_string()?(float)atof(obj["min"].get<std::string>().c_str()):obj["min"].get<float>());
        }
        if(obj.contains("max"))
        {
            msg.max = (obj["max"].is_string()?(float)atof(obj["max"].get<std::string>().c_str()):obj["max"].get<float>());
        }
        if(obj.contains("mean"))
        {
            msg.mean = (obj["mean"].is_string()?(float)atof(obj["mean"].get<std::string>().c_str()):obj["mean"].get<float>());
        }
        if(obj.contains("std"))
        {
            msg.std = (obj["std"].is_string()?(float)atof(obj["std"].get<std::string>().c_str()):obj["std"].get<float>());
        }
        if(obj.contains("sparse"))
        {
            msg.sparse = (obj["sparse"].is_string()?atoi(obj["sparse"].get<std::string>().c_str()):obj["sparse"].get<int>());
        }
        if(obj.contains("variancenorm"))
        {
            msg.variancenorm = (obj["variancenorm"].is_string()?atoi(obj["variancenorm"].get<std::string>().c_str()):obj["variancenorm"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceFillerParameter from_json<ApolloperceptioninferenceFillerParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceFillerParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceFillerParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceFillerParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceFillerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceFillerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
