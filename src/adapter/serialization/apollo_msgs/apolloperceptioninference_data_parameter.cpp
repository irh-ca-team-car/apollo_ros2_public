#include "adapter/serialization/apollo_msgs/apolloperceptioninference_data_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDataParameter &msg) {
        nlohmann::json obj;
        obj["source"] = (msg.source);
        obj["batchsize"] = (msg.batchsize);
        obj["randskip"] = (msg.randskip);
        obj["backend"] = (msg.backend);
        obj["scale"] = (msg.scale);
        obj["meanfile"] = (msg.meanfile);
        obj["cropsize"] = (msg.cropsize);
        obj["mirror"] = (msg.mirror);
        obj["forceencodedcolor"] = (msg.forceencodedcolor);
        obj["prefetch"] = (msg.prefetch);
        return obj;
    }
    ApolloperceptioninferenceDataParameter from_json_ApolloperceptioninferenceDataParameter (nlohmann::json obj) {
        ApolloperceptioninferenceDataParameter msg;
        if(obj.contains("source"))
        {
            msg.source = (obj["source"].is_string()?(obj["source"].get<std::string>().c_str()):obj["source"].get<std::string>());
        }
        if(obj.contains("batchsize"))
        {
            msg.batchsize = (obj["batchsize"].is_string()?atoi(obj["batchsize"].get<std::string>().c_str()):obj["batchsize"].get<uint32_t>());
        }
        if(obj.contains("randskip"))
        {
            msg.randskip = (obj["randskip"].is_string()?atoi(obj["randskip"].get<std::string>().c_str()):obj["randskip"].get<uint32_t>());
        }
        if(obj.contains("backend"))
        {
            msg.backend = (obj["backend"].is_string()?atoi(obj["backend"].get<std::string>().c_str()):obj["backend"].get<int>());
        }
        if(obj.contains("scale"))
        {
            msg.scale = (obj["scale"].is_string()?(float)atof(obj["scale"].get<std::string>().c_str()):obj["scale"].get<float>());
        }
        if(obj.contains("meanfile"))
        {
            msg.meanfile = (obj["meanfile"].is_string()?(obj["meanfile"].get<std::string>().c_str()):obj["meanfile"].get<std::string>());
        }
        if(obj.contains("cropsize"))
        {
            msg.cropsize = (obj["cropsize"].is_string()?atoi(obj["cropsize"].get<std::string>().c_str()):obj["cropsize"].get<uint32_t>());
        }
        if(obj.contains("mirror"))
        {
            msg.mirror = (obj["mirror"].is_string()?(bool)atoi(obj["mirror"].get<std::string>().c_str()):obj["mirror"].get<bool>());
        }
        if(obj.contains("forceencodedcolor"))
        {
            msg.forceencodedcolor = (obj["forceencodedcolor"].is_string()?(bool)atoi(obj["forceencodedcolor"].get<std::string>().c_str()):obj["forceencodedcolor"].get<bool>());
        }
        if(obj.contains("prefetch"))
        {
            msg.prefetch = (obj["prefetch"].is_string()?atoi(obj["prefetch"].get<std::string>().c_str()):obj["prefetch"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDataParameter from_json<ApolloperceptioninferenceDataParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDataParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDataParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceDataParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
