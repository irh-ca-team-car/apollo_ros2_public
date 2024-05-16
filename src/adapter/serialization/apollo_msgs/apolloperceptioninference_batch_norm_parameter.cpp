#include "adapter/serialization/apollo_msgs/apolloperceptioninference_batch_norm_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBatchNormParameter &msg) {
        nlohmann::json obj;
        obj["useglobalstats"] = (msg.useglobalstats);
        obj["movingaveragefraction"] = (msg.movingaveragefraction);
        obj["eps"] = (msg.eps);
        return obj;
    }
    ApolloperceptioninferenceBatchNormParameter from_json_ApolloperceptioninferenceBatchNormParameter (nlohmann::json obj) {
        ApolloperceptioninferenceBatchNormParameter msg;
        if(obj.contains("useglobalstats"))
        {
            msg.useglobalstats = (obj["useglobalstats"].is_string()?(bool)atoi(obj["useglobalstats"].get<std::string>().c_str()):obj["useglobalstats"].get<bool>());
        }
        if(obj.contains("movingaveragefraction"))
        {
            msg.movingaveragefraction = (obj["movingaveragefraction"].is_string()?(float)atof(obj["movingaveragefraction"].get<std::string>().c_str()):obj["movingaveragefraction"].get<float>());
        }
        if(obj.contains("eps"))
        {
            msg.eps = (obj["eps"].is_string()?(float)atof(obj["eps"].get<std::string>().c_str()):obj["eps"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceBatchNormParameter from_json<ApolloperceptioninferenceBatchNormParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceBatchNormParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBatchNormParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceBatchNormParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBatchNormParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBatchNormParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
