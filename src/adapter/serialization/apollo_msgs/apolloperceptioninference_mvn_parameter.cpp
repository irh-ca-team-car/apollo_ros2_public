#include "adapter/serialization/apollo_msgs/apolloperceptioninference_mvn_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceMVNParameter &msg) {
        nlohmann::json obj;
        obj["normalizevariance"] = (msg.normalizevariance);
        obj["acrosschannels"] = (msg.acrosschannels);
        obj["eps"] = (msg.eps);
        return obj;
    }
    ApolloperceptioninferenceMVNParameter from_json_ApolloperceptioninferenceMVNParameter (nlohmann::json obj) {
        ApolloperceptioninferenceMVNParameter msg;
        if(obj.contains("normalizevariance"))
        {
            msg.normalizevariance = (obj["normalizevariance"].is_string()?(bool)atoi(obj["normalizevariance"].get<std::string>().c_str()):obj["normalizevariance"].get<bool>());
        }
        if(obj.contains("acrosschannels"))
        {
            msg.acrosschannels = (obj["acrosschannels"].is_string()?(bool)atoi(obj["acrosschannels"].get<std::string>().c_str()):obj["acrosschannels"].get<bool>());
        }
        if(obj.contains("eps"))
        {
            msg.eps = (obj["eps"].is_string()?(float)atof(obj["eps"].get<std::string>().c_str()):obj["eps"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceMVNParameter from_json<ApolloperceptioninferenceMVNParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceMVNParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceMVNParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceMVNParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceMVNParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceMVNParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
