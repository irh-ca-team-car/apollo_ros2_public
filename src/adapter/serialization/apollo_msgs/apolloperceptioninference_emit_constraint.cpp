#include "adapter/serialization/apollo_msgs/apolloperceptioninference_emit_constraint.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceEmitConstraint &msg) {
        nlohmann::json obj;
        obj["emittype"] = (msg.emittype);
        obj["emitoverlap"] = (msg.emitoverlap);
        return obj;
    }
    ApolloperceptioninferenceEmitConstraint from_json_ApolloperceptioninferenceEmitConstraint (nlohmann::json obj) {
        ApolloperceptioninferenceEmitConstraint msg;
        if(obj.contains("emittype"))
        {
            msg.emittype = (obj["emittype"].is_string()?atoi(obj["emittype"].get<std::string>().c_str()):obj["emittype"].get<int>());
        }
        if(obj.contains("emitoverlap"))
        {
            msg.emitoverlap = (obj["emitoverlap"].is_string()?(float)atof(obj["emitoverlap"].get<std::string>().c_str()):obj["emitoverlap"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceEmitConstraint from_json<ApolloperceptioninferenceEmitConstraint>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceEmitConstraint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceEmitConstraint &dt)
    {
        dt=from_json_ApolloperceptioninferenceEmitConstraint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceEmitConstraint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceEmitConstraint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
