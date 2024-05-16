#include "adapter/serialization/apollo_msgs/apolloperceptioninference_batch_sampler.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBatchSampler &msg) {
        nlohmann::json obj;
        obj["useoriginalimage"] = (msg.useoriginalimage);
        obj["sampler"] = to_json(msg.sampler);
        obj["sampleconstraint"] = to_json(msg.sampleconstraint);
        obj["maxsample"] = (msg.maxsample);
        obj["maxtrials"] = (msg.maxtrials);
        return obj;
    }
    ApolloperceptioninferenceBatchSampler from_json_ApolloperceptioninferenceBatchSampler (nlohmann::json obj) {
        ApolloperceptioninferenceBatchSampler msg;
        if(obj.contains("useoriginalimage"))
        {
            msg.useoriginalimage = (obj["useoriginalimage"].is_string()?(bool)atoi(obj["useoriginalimage"].get<std::string>().c_str()):obj["useoriginalimage"].get<bool>());
        }
        if(obj.contains("sampler"))
        {
            msg.sampler = from_json_ApolloperceptioninferenceSampler(obj["sampler"]);
        }
        if(obj.contains("sampleconstraint"))
        {
            msg.sampleconstraint = from_json_ApolloperceptioninferenceSampleConstraint(obj["sampleconstraint"]);
        }
        if(obj.contains("maxsample"))
        {
            msg.maxsample = (obj["maxsample"].is_string()?atoi(obj["maxsample"].get<std::string>().c_str()):obj["maxsample"].get<uint32_t>());
        }
        if(obj.contains("maxtrials"))
        {
            msg.maxtrials = (obj["maxtrials"].is_string()?atoi(obj["maxtrials"].get<std::string>().c_str()):obj["maxtrials"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceBatchSampler from_json<ApolloperceptioninferenceBatchSampler>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceBatchSampler(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBatchSampler &dt)
    {
        dt=from_json_ApolloperceptioninferenceBatchSampler(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBatchSampler & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBatchSampler & dt)
    {
        os << to_json(dt);
        return os;
    }
}
